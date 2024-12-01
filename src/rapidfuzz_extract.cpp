#include <Rcpp.h>
#include <string>
#include <vector>
#include <optional>
#include <utility>
#include <algorithm>
#include <cctype>
#include <rapidfuzz/fuzz.hpp>
#include <unordered_map>

#ifndef SIZE_MAX
#define SIZE_MAX static_cast<size_t>(-1)
#endif

// Helper function to remove leading and trailing whitespace
std::string trimString(const std::string& input) {
  size_t start = input.find_first_not_of(" \t\n\r");
  size_t end = input.find_last_not_of(" \t\n\r");

  if (start == std::string::npos || end == std::string::npos) {
    return "";// Input string is all whitespace
  }

  return input.substr(start, end - start + 1);
}

// Map of accented characters to ASCII equivalents
static const std::unordered_map<std::string, std::string> accents = {
 // Lowercase letters
  {"à", "a"}, {"á", "a"}, {"â", "a"}, {"ã", "a"}, {"ä", "a"}, {"å", "a"},
  {"è", "e"}, {"é", "e"}, {"ê", "e"}, {"ë", "e"},
  {"ì", "i"}, {"í", "i"}, {"î", "i"}, {"ï", "i"},
  {"ò", "o"}, {"ó", "o"}, {"ô", "o"}, {"õ", "o"}, {"ö", "o"},
  {"ù", "u"}, {"ú", "u"}, {"û", "u"}, {"ü", "u"},
  {"ç", "c"}, {"ñ", "n"}, {"ÿ", "y"},

 // Uppercase letters
  {"À", "A"}, {"Á", "A"}, {"Â", "A"}, {"Ã", "A"}, {"Ä", "A"}, {"Å", "A"},
  {"È", "E"}, {"É", "E"}, {"Ê", "E"}, {"Ë", "E"},
  {"Ì", "I"}, {"Í", "I"}, {"Î", "I"}, {"Ï", "I"},
  {"Ò", "O"}, {"Ó", "O"}, {"Ô", "O"}, {"Õ", "O"}, {"Ö", "O"},
  {"Ù", "U"}, {"Ú", "U"}, {"Û", "U"}, {"Ü", "U"},
  {"Ç", "C"}, {"Ñ", "N"}, {"Ÿ", "Y"}
};

// Helper function to convert a UTF-8 string to its ASCII equivalent
std::string toASCII(const std::string& input) {
  std::string result;

  for (size_t i = 0; i < input.length(); ++i) {
    std::string ch(1, input[i]);

   // Handle multi-byte UTF-8 sequences
    if ((input[i] & 0x80) != 0) {
      size_t len = 1;
      if ((input[i] & 0xE0) == 0xC0) len = 2;
      else if ((input[i] & 0xF0) == 0xE0) len = 3;
      else if ((input[i] & 0xF8) == 0xF0) len = 4;

      ch = input.substr(i, len);
      i += len - 1;
    }

   // Replace accented character or append as-is
    auto it = accents.find(ch);
    if (it != accents.end()) {
      result += it->second;
    } else {
      result += ch;
    }
  }

  return result;
}

// Helper function to convert a string to lowercase
std::string toLower(const std::string& input) {
  std::unordered_map<std::string, std::string> utf8_case_map = {
    {"À", "à"}, {"Á", "á"}, {"Â", "â"}, {"Ã", "ã"}, {"Ä", "ä"}, {"Å", "å"},
    {"È", "è"}, {"É", "é"}, {"Ê", "ê"}, {"Ë", "ë"},
    {"Ì", "ì"}, {"Í", "í"}, {"Î", "î"}, {"Ï", "ï"},
    {"Ò", "ò"}, {"Ó", "ó"}, {"Ô", "ô"}, {"Õ", "õ"}, {"Ö", "ö"},
    {"Ù", "ù"}, {"Ú", "ú"}, {"Û", "û"}, {"Ü", "ü"},
    {"Ç", "ç"}, {"Ñ", "ñ"},
    {"Ÿ", "ÿ"}
  };

  std::string result;
  size_t i = 0;

  while (i < input.length()) {
    unsigned char c = input[i];

   // Handle multi-byte UTF-8 sequences
    if ((c & 0x80) != 0) {
      size_t len = 1;
      if ((c & 0xE0) == 0xC0) len = 2; // 2-byte sequence
      else if ((c & 0xF0) == 0xE0) len = 3; // 3-byte sequence
      else if ((c & 0xF8) == 0xF0) len = 4; // 4-byte sequence

      std::string utf8_char = input.substr(i, len);
      i += len;

     // Map the uppercase accented character to its lowercase equivalent if it exists
      if (utf8_case_map.count(utf8_char)) {
        result += utf8_case_map[utf8_char];
      } else {
        result += utf8_char; // Keep unchanged if no mapping exists
      }
    } else {
     // Handle ASCII characters
      result += std::tolower(c);
      ++i;
    }
  }

  return result;
}


//' @name processString
//' @title Process a String
//' @description Processes a given input string by applying optional trimming, case conversion, and ASCII transliteration.
//' @param input A \code{std::string} representing the input string to be processed.
//' @param processor A \code{bool} indicating whether to trim whitespace and convert the string to lowercase. Default is \code{true}.
//' @param asciify A \code{bool} indicating whether to transliterate non-ASCII characters to their closest ASCII equivalents. Default is \code{false}.
//' @details
//' The function applies the following transformations to the input string, in this order:
//' \itemize{
//'   \item \strong{Trimming (if \code{processor = TRUE}):} Removes leading and trailing whitespace.
//'   \item \strong{Lowercasing (if \code{processor = TRUE}):} Converts all characters to lowercase.
//'   \item \strong{ASCII Transliteration (if \code{asciify = TRUE}):} Replaces accented or special characters with their closest ASCII equivalents.
//' }
//' @return A \code{std::string} representing the processed string.
//' @examples
//' # Example usage
//' processString("  Éxâmple!  ", processor = TRUE, asciify = TRUE)
//' # Returns: "example!"
//'
//' processString("  Éxâmple!  ", processor = TRUE, asciify = FALSE)
//' # Returns: "éxâmple!"
//'
//' processString("  Éxâmple!  ", processor = FALSE, asciify = TRUE)
//' # Returns: "Éxâmple!"
//'
//' processString("  Éxâmple!  ", processor = FALSE, asciify = FALSE)
//' # Returns: "  Éxâmple!  "
//' @export
// [[Rcpp::export]]
std::string processString(const std::string& input, bool processor = true, bool asciify = false) {
  std::string processed = input;

  if (processor) {
   // Trim whitespace
    processed = trimString(processed);
   // Convert to lowercase
    processed = toLower(processed);
  }

  if (asciify) {
   // Convert to ASCII
    processed = toASCII(processed);
  }

  return processed;
}

//' @name extract_similar_strings
//' @title Extract Matches
//' @description Compares a query string to all strings in a list of choices and returns all elements
//' with a similarity score above the score_cutoff.
//' @param query The query string to compare.
//' @param choices A vector of strings to compare against the query.
//' @param score_cutoff A numeric value specifying the minimum similarity score (default is 50.0).
//' @param processor A boolean indicating whether to preprocess strings before comparison (default is TRUE).
//' @return A data frame containing matched strings and their similarity scores.
//' @export
// [[Rcpp::export]]
 Rcpp::DataFrame extract_similar_strings(const std::string& query,
                                         const std::vector<std::string>& choices,
                                         double score_cutoff = 50.0,
                                         bool processor = true) {
   std::string processedQuery = processString(query, processor);
   std::vector<std::string> matched_choices;
   std::vector<double> scores;

   rapidfuzz::fuzz::CachedWRatio<std::string::value_type> scorer(processedQuery);

   for (const auto& choice : choices) {
     std::string processedChoice = processString(choice, processor);
     double score = scorer.similarity(processedChoice, score_cutoff);

     if (score >= score_cutoff) {
       matched_choices.push_back(choice);
       scores.push_back(score);
     }
   }

   return Rcpp::DataFrame::create(Rcpp::Named("choice") = matched_choices,
                                  Rcpp::Named("score") = scores);
 }

//' @name extract_best_match
//' @title Extract Best Match
//' @description Compares a query string to all strings in a list of choices and returns the best match
//' with a similarity score above the score_cutoff.
//' @param query The query string to compare.
//' @param choices A vector of strings to compare against the query.
//' @param score_cutoff A numeric value specifying the minimum similarity score (default is 50.0).
//' @param processor A boolean indicating whether to preprocess strings before comparison (default is TRUE).
//' @return A list containing the best matching string and its similarity score.
//' @export
// [[Rcpp::export]]
 Rcpp::List extract_best_match(const std::string& query,
                               const std::vector<std::string>& choices,
                               double score_cutoff = 50.0,
                               bool processor = true) {
   std::string processedQuery = processString(query, processor);
   std::string best_choice;
   double best_score = score_cutoff;

   rapidfuzz::fuzz::CachedWRatio<std::string::value_type> scorer(processedQuery);

   for (const auto& choice : choices) {
     std::string processedChoice = processString(choice, processor);
     double score = scorer.similarity(processedChoice, best_score);

     if (score > best_score) {
       best_score = score;
       best_choice = choice;
     }
   }

   return Rcpp::List::create(Rcpp::Named("choice") = best_choice,
                             Rcpp::Named("score") = best_score);
 }

//' @name extract_matches
//' @title Extract Matches with Scoring and Limit
//' @description Compares a query string to a list of choices using the specified scorer and returns
//' the top matches with a similarity score above the cutoff.
//' @param query The query string to compare.
//' @param choices A vector of strings to compare against the query.
//' @param score_cutoff A numeric value specifying the minimum similarity score (default is 50.0).
//' @param limit The maximum number of matches to return (default is 3).
//' @param processor A boolean indicating whether to preprocess strings before comparison (default is TRUE).
//' @param scorer A string specifying the similarity scoring method ("WRatio", "Ratio", "PartialRatio", etc.).
//' @return A data frame containing the top matched strings and their similarity scores.
//' @export
// [[Rcpp::export]]
 Rcpp::DataFrame extract_matches(const std::string& query,
                                 const std::vector<std::string>& choices,
                                 double score_cutoff = 50.0,
                                 int limit = 3,
                                 bool processor = true,
                                 std::string scorer = "WRatio") {
   std::string processedQuery = processString(query, processor);
   std::vector<std::pair<std::string, double>> results;

   for (const auto& choice : choices) {
     std::string processedChoice = processString(choice, processor);
     double similarity = 0.0;

  // Select scoring method
     if (scorer == "WRatio") {
       similarity = static_cast<double>(rapidfuzz::fuzz::WRatio(processedQuery, processedChoice));
     } else if (scorer == "Ratio") {
       similarity = static_cast<double>(rapidfuzz::fuzz::ratio(processedQuery, processedChoice));
     } else if (scorer == "PartialRatio") {
       similarity = static_cast<double>(rapidfuzz::fuzz::partial_ratio(processedQuery, processedChoice));
     } else {
       Rcpp::stop("Invalid scorer specified.");
     }

     if (similarity >= score_cutoff) {
       results.emplace_back(choice, similarity);
     }
   }


   std::sort(results.begin(), results.end(), [](const auto& a, const auto& b) {
     return a.second > b.second;// Sort descending by score
   });

   if (limit > 0 && results.size() > static_cast<size_t>(limit)) {
     results.resize(limit);// Limit the results
   }

   std::vector<std::string> matched_choices;
   std::vector<double> scores;

   for (const auto& result : results) {
     matched_choices.push_back(result.first);
     scores.push_back(result.second);
   }

   return Rcpp::DataFrame::create(Rcpp::Named("choice") = matched_choices,
                                  Rcpp::Named("score") = scores);
 }
