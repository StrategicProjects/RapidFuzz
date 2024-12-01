#include <Rcpp.h>
#include "rapidfuzz/distance/Levenshtein.hpp"

#ifndef SIZE_MAX
#define SIZE_MAX static_cast<size_t>(-1)
#endif

using namespace Rcpp;

//' @name levenshtein_distance
//' @title Levenshtein Distance
//' @description
//' Calculates the Levenshtein distance between two strings, which represents the minimum number
//' of insertions, deletions, and substitutions required to transform one string into the other.
//'
//' @param s1 The first string.
//' @param s2 The second string.
//' @return A numeric value representing the Levenshtein distance.
//' @examples
//' levenshtein_distance("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 size_t levenshtein_distance(std::string s1, std::string s2) {
   return rapidfuzz::levenshtein_distance(s1, s2);
 }

//' @name levenshtein_normalized_distance
//' @title Normalized Levenshtein Distance
//' @description
//' The normalized Levenshtein distance is the Levenshtein distance divided by the maximum length of the
//' compared strings, returning a value between 0 and 1.
//'
//' @param s1 The first string.
//' @param s2 The second string.
//' @return A numeric value representing the normalized Levenshtein distance.
//' @examples
//' levenshtein_normalized_distance("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 double levenshtein_normalized_distance(std::string s1, std::string s2) {
   return rapidfuzz::levenshtein_normalized_distance(s1, s2);
 }

//' @name levenshtein_similarity
//' @title Levenshtein Similarity
//' @description
//' Levenshtein similarity measures how similar two strings are, based on the minimum number
//' of operations required to make them identical.
//'
//' @param s1 The first string.
//' @param s2 The second string.
//' @return A numeric value representing the Levenshtein similarity.
//' @examples
//' levenshtein_similarity("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 size_t levenshtein_similarity(std::string s1, std::string s2) {
   return rapidfuzz::levenshtein_similarity(s1, s2);
 }

//' @name levenshtein_normalized_similarity
//' @title Normalized Levenshtein Similarity
//' @description
//' The normalized Levenshtein similarity returns a value between 0 and 1,
//' indicating how similar the compared strings are.
//'
//' @param s1 The first string.
//' @param s2 The second string.
//' @return A numeric value representing the normalized Levenshtein similarity.
//' @examples
//' levenshtein_normalized_similarity("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 double levenshtein_normalized_similarity(std::string s1, std::string s2) {
   return rapidfuzz::levenshtein_normalized_similarity(s1, s2);
 }
