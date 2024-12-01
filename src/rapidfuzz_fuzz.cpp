#include <Rcpp.h>
#include <rapidfuzz/fuzz.hpp>

#ifndef SIZE_MAX
#define SIZE_MAX static_cast<size_t>(-1)
#endif

using namespace Rcpp;



//' @name fuzz_ratio
//' @title Simple Ratio Calculation
//' @description Calculates a simple ratio between two strings.
//' @param s1 First string.
//' @param s2 Second string.
//' @param score_cutoff Optional score cutoff threshold (default: 0.0).
//' @return A double representing the ratio between the two strings.
//' @examples
//' fuzz_ratio("this is a test", "this is a test!")
//' @export
// [[Rcpp::export]]
 double fuzz_ratio(std::string s1, std::string s2, double score_cutoff = 0.0) {
   return rapidfuzz::fuzz::ratio(s1, s2, score_cutoff);
 }

//' @name fuzz_partial_ratio
//' @title Partial Ratio Calculation
//' @description Calculates a partial ratio between two strings, which ignores long mismatching substrings.
//' @param s1 First string.
//' @param s2 Second string.
//' @param score_cutoff Optional score cutoff threshold (default: 0.0).
//' @return A double representing the partial ratio between the two strings.
//' @examples
//' fuzz_partial_ratio("this is a test", "this is a test!")
//' @export
// [[Rcpp::export]]
 double fuzz_partial_ratio(std::string s1, std::string s2, double score_cutoff = 0.0) {
   return rapidfuzz::fuzz::partial_ratio(s1, s2, score_cutoff);
 }

//' @name fuzz_token_sort_ratio
//' @title Token Sort Ratio Calculation
//' @description Sorts the words in the strings and calculates the ratio between them.
//' @param s1 First string.
//' @param s2 Second string.
//' @param score_cutoff Optional score cutoff threshold (default: 0.0).
//' @return A double representing the token sort ratio between the two strings.
//' @examples
//' fuzz_token_sort_ratio("fuzzy wuzzy was a bear", "wuzzy fuzzy was a bear")
//' @export
// [[Rcpp::export]]
 double fuzz_token_sort_ratio(std::string s1, std::string s2, double score_cutoff = 0.0) {
   return rapidfuzz::fuzz::token_sort_ratio(s1, s2, score_cutoff);
 }

//' @name fuzz_token_set_ratio
//' @title Token Set Ratio Calculation
//' @description Compares the unique and common words in the strings and calculates the ratio.
//' @param s1 First string.
//' @param s2 Second string.
//' @param score_cutoff Optional score cutoff threshold (default: 0.0).
//' @return A double representing the token set ratio between the two strings.
//' @examples
//' fuzz_token_set_ratio("fuzzy wuzzy was a bear", "fuzzy fuzzy was a bear")
//' @export
// [[Rcpp::export]]
 double fuzz_token_set_ratio(std::string s1, std::string s2, double score_cutoff = 0.0) {
   return rapidfuzz::fuzz::token_set_ratio(s1, s2, score_cutoff);
 }

//' @name fuzz_token_ratio
//' @title Combined Token Ratio
//' @description Calculates the maximum ratio of token set ratio and token sort ratio.
//' @param s1 First string.
//' @param s2 Second string.
//' @param score_cutoff Optional score cutoff threshold (default: 0.0).
//' @return A double representing the combined token ratio between the two strings.
//' @examples
//' fuzz_token_ratio("fuzzy wuzzy was a bear", "wuzzy fuzzy was a bear")
//' @export
// [[Rcpp::export]]
 double fuzz_token_ratio(std::string s1, std::string s2, double score_cutoff = 0.0) {
   return rapidfuzz::fuzz::token_ratio(s1, s2, score_cutoff);
 }

//' @name fuzz_WRatio
//' @title Weighted Ratio Calculation
//' @description Calculates a weighted ratio based on other ratio algorithms.
//' @param s1 First string.
//' @param s2 Second string.
//' @param score_cutoff Optional score cutoff threshold (default: 0.0).
//' @return A double representing the weighted ratio between the two strings.
//' @examples
//' fuzz_WRatio("this is a test", "this is a test!")
//' @export
// [[Rcpp::export]]
 double fuzz_WRatio(std::string s1, std::string s2, double score_cutoff = 0.0) {
   return rapidfuzz::fuzz::WRatio(s1, s2, score_cutoff);
 }

//' @name fuzz_QRatio
//' @title Quick Ratio Calculation
//' @description Calculates a quick ratio using fuzz ratio.
//' @param s1 First string.
//' @param s2 Second string.
//' @param score_cutoff Optional score cutoff threshold (default: 0.0).
//' @return A double representing the quick ratio between the two strings.
//' @examples
//' fuzz_QRatio("this is a test", "this is a test!")
//' @export
// [[Rcpp::export]]
 double fuzz_QRatio(std::string s1, std::string s2, double score_cutoff = 0.0) {
   return rapidfuzz::fuzz::QRatio(s1, s2, score_cutoff);
 }
