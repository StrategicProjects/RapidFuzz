#include <Rcpp.h>
#include <string>
#include <limits>
#include <rapidfuzz/details/common.hpp>
#include <rapidfuzz/distance/DamerauLevenshtein.hpp>

#ifndef SIZE_MAX
#define SIZE_MAX static_cast<size_t>(-1)
#endif

//' @name damerau_levenshtein_distance
//' @title Damerau-Levenshtein Distance
//' @description Calculate the Damerau-Levenshtein distance between two strings.
//'
//' Computes the Damerau-Levenshtein distance, which is an edit distance allowing transpositions in addition
//' to substitutions, insertions, and deletions.
//'
//' @param s1 A string. The first input string.
//' @param s2 A string. The second input string.
//' @param score_cutoff An optional maximum threshold for the distance. Defaults to the largest
//' integer value in R (`.Machine$integer.max`).
//' @return The Damerau-Levenshtein distance as an integer.
//' @examples
//' damerau_levenshtein_distance("abcdef", "abcfde")
//' damerau_levenshtein_distance("abcdef", "abcfde", score_cutoff = 3)
//' @export
// [[Rcpp::export]]
 size_t damerau_levenshtein_distance(std::string s1, std::string s2, Rcpp::Nullable<double> score_cutoff = R_NilValue) {
   size_t cutoff_value = score_cutoff.isNull() ? std::numeric_limits<size_t>::max() : Rcpp::as<size_t>(score_cutoff);
   return rapidfuzz::experimental::damerau_levenshtein_distance(s1, s2, cutoff_value);
 }

//' @name damerau_levenshtein_similarity
//' @title Damerau-Levenshtein Similarity
//' @description Calculate the Damerau-Levenshtein similarity between two strings.
//'
//' Computes the similarity based on the Damerau-Levenshtein metric, which considers transpositions in addition
//' to substitutions, insertions, and deletions.
//'
//' @param s1 A string. The first input string.
//' @param s2 A string. The second input string.
//' @param score_cutoff An optional minimum threshold for the similarity score. Defaults to 0.
//' @return The Damerau-Levenshtein similarity as an integer.
//' @examples
//' damerau_levenshtein_similarity("abcdef", "abcfde")
//' damerau_levenshtein_similarity("abcdef", "abcfde", score_cutoff = 3)
//' @export
// [[Rcpp::export]]
 size_t damerau_levenshtein_similarity(std::string s1, std::string s2, size_t score_cutoff = 0) {
   return rapidfuzz::experimental::damerau_levenshtein_similarity(s1, s2, score_cutoff);
 }

//' @name damerau_levenshtein_normalized_distance
//' @title Normalized Damerau-Levenshtein Distance
//' @description Calculate the normalized Damerau-Levenshtein distance between two strings.
//'
//' Computes the normalized Damerau-Levenshtein distance, where the result is between
//' 0.0 (identical) and 1.0 (completely different).
//'
//' @param s1 A string. The first input string.
//' @param s2 A string. The second input string.
//' @param score_cutoff An optional maximum threshold for the normalized distance. Defaults to 1.0.
//' @return The normalized Damerau-Levenshtein distance as a double.
//' @examples
//' damerau_levenshtein_normalized_distance("abcdef", "abcfde")
//' damerau_levenshtein_normalized_distance("abcdef", "abcfde", score_cutoff = 0.5)
//' @export
// [[Rcpp::export]]
 double damerau_levenshtein_normalized_distance(std::string s1, std::string s2, double score_cutoff = 1.0) {
   return rapidfuzz::experimental::damerau_levenshtein_normalized_distance(s1, s2, score_cutoff);
 }

//' @name damerau_levenshtein_normalized_similarity
//' @title Normalized Damerau-Levenshtein Similarity
//' @description Calculate the normalized Damerau-Levenshtein similarity between two strings.
//'
//' Computes the normalized similarity based on the Damerau-Levenshtein metric, where the result is between
//' 0.0 (completely different) and 1.0 (identical).
//'
//' @param s1 A string. The first input string.
//' @param s2 A string. The second input string.
//' @param score_cutoff An optional minimum threshold for the normalized similarity. Defaults to 0.0.
//' @return The normalized Damerau-Levenshtein similarity as a double.
//' @examples
//' damerau_levenshtein_normalized_similarity("abcdef", "abcfde")
//' damerau_levenshtein_normalized_similarity("abcdef", "abcfde", score_cutoff = 0.7)
//' @export
// [[Rcpp::export]]
 double damerau_levenshtein_normalized_similarity(std::string s1, std::string s2, double score_cutoff = 0.0) {
   return rapidfuzz::experimental::damerau_levenshtein_normalized_similarity(s1, s2, score_cutoff);
 }
