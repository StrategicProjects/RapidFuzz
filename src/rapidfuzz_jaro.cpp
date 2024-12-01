#include <Rcpp.h>
#include "rapidfuzz/distance/Jaro.hpp"

#ifndef SIZE_MAX
#define SIZE_MAX static_cast<size_t>(-1)
#endif

using namespace Rcpp;

//' @name jaro_distance
//' @title Jaro Distance
//' @description Calculates the Jaro distance between two strings, a value between 0 and 1.
//' @param s1 The first string.
//' @param s2 The second string.
//' @return A numeric value representing the Jaro distance.
//' @examples
//' jaro_distance("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 double jaro_distance(std::string s1, std::string s2) {
   return rapidfuzz::jaro_distance(s1, s2);
 }

//' @name jaro_similarity
//' @title Jaro Similarity
//' @description Calculates the Jaro similarity between two strings, a value between 0 and 1.
//' @param s1 The first string.
//' @param s2 The second string.
//' @return A numeric value representing the Jaro similarity.
//' @examples
//' jaro_similarity("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 double jaro_similarity(std::string s1, std::string s2) {
   return rapidfuzz::jaro_similarity(s1, s2);
 }

//' @name jaro_normalized_distance
//' @title Normalized Jaro Distance
//' @description Calculates the normalized Jaro distance between two strings, a value between 0 and 1.
//' @param s1 The first string.
//' @param s2 The second string.
//' @return A numeric value representing the normalized Jaro distance.
//' @examples
//' jaro_normalized_distance("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 double jaro_normalized_distance(std::string s1, std::string s2) {
   return rapidfuzz::jaro_normalized_distance(s1, s2);
 }

//' @name jaro_normalized_similarity
//' @title Normalized Jaro Similarity
//' @description Calculates the normalized Jaro similarity between two strings, a value between 0 and 1.
//' @param s1 The first string.
//' @param s2 The second string.
//' @return A numeric value representing the normalized Jaro similarity.
//' @examples
//' jaro_normalized_similarity("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 double jaro_normalized_similarity(std::string s1, std::string s2) {
   return rapidfuzz::jaro_normalized_similarity(s1, s2);
 }
