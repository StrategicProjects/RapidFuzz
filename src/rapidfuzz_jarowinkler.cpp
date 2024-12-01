#include <Rcpp.h>
#include "rapidfuzz/distance/JaroWinkler.hpp"

#ifndef SIZE_MAX
#define SIZE_MAX static_cast<size_t>(-1)
#endif

using namespace Rcpp;

//' @name jaro_winkler_distance
//' @title Jaro-Winkler Distance
//' @description Calculates the Jaro-Winkler distance between two strings.
//' @param s1 The first string.
//' @param s2 The second string.
//' @param prefix_weight The weight applied to the prefix (default: 0.1).
//' @return A numeric value representing the Jaro-Winkler distance.
//' @examples
//' jaro_winkler_distance("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 double jaro_winkler_distance(std::string s1, std::string s2, double prefix_weight = 0.1) {
   return rapidfuzz::jaro_winkler_distance(s1, s2, prefix_weight);
 }

//' @name jaro_winkler_similarity
//' @title Jaro-Winkler Similarity
//' @description Calculates the Jaro-Winkler similarity between two strings.
//' @param s1 The first string.
//' @param s2 The second string.
//' @param prefix_weight The weight applied to the prefix (default: 0.1).
//' @return A numeric value representing the Jaro-Winkler similarity.
//' @examples
//' jaro_winkler_similarity("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 double jaro_winkler_similarity(std::string s1, std::string s2, double prefix_weight = 0.1) {
   return rapidfuzz::jaro_winkler_similarity(s1, s2, prefix_weight);
 }

//' @name jaro_winkler_normalized_distance
//' @title Normalized Jaro-Winkler Distance
//' @description Calculates the normalized Jaro-Winkler distance between two strings.
//' @param s1 The first string.
//' @param s2 The second string.
//' @param prefix_weight The weight applied to the prefix (default: 0.1).
//' @return A numeric value representing the normalized Jaro-Winkler distance.
//' @examples
//' jaro_winkler_normalized_distance("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 double jaro_winkler_normalized_distance(std::string s1, std::string s2, double prefix_weight = 0.1) {
   return rapidfuzz::jaro_winkler_normalized_distance(s1, s2, prefix_weight);
 }

//' @name jaro_winkler_normalized_similarity
//' @title Normalized Jaro-Winkler Similarity
//' @description Calculates the normalized Jaro-Winkler similarity between two strings.
//' @param s1 The first string.
//' @param s2 The second string.
//' @param prefix_weight The weight applied to the prefix (default: 0.1).
//' @return A numeric value representing the normalized Jaro-Winkler similarity.
//' @examples
//' jaro_winkler_normalized_similarity("kitten", "sitting")
//' @export
// [[Rcpp::
