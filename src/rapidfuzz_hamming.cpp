#include <Rcpp.h>
#include "rapidfuzz/distance/Hamming.hpp"

#ifndef SIZE_MAX
#define SIZE_MAX static_cast<size_t>(-1)
#endif

//' @name hamming_distance
//' @title Hamming Distance
//' @description Calculates the Hamming distance between two strings.
//' @param s1 The first string.
//' @param s2 The second string.
//' @param pad If true, the strings are padded to the same length (default: TRUE).
//' @return An integer representing the Hamming distance.
//' @examples
//' hamming_distance("karolin", "kathrin")
//' @export
// [[Rcpp::export]]
 size_t hamming_distance(std::string s1, std::string s2, bool pad = true) {
   return rapidfuzz::hamming_distance(s1, s2, pad);
 }

//' @name hamming_similarity
//' @title Hamming Similarity
//' @description Measures the similarity between two strings using the Hamming metric.
//' @param s1 The first string.
//' @param s2 The second string.
//' @param pad If true, the strings are padded to the same length (default: TRUE).
//' @return An integer representing the similarity.
//' @examples
//' hamming_similarity("karolin", "kathrin")
//' @export
// [[Rcpp::export]]
 size_t hamming_similarity(std::string s1, std::string s2, bool pad = true) {
   return rapidfuzz::hamming_similarity(s1, s2, pad);
 }

//' @name hamming_normalized_distance
//' @title Normalized Hamming Distance
//' @description Calculates the normalized Hamming distance between two strings.
//' @param s1 The first string.
//' @param s2 The second string.
//' @param pad If true, the strings are padded to the same length (default: TRUE).
//' @return A value between 0 and 1 representing the normalized distance.
//' @examples
//' hamming_normalized_distance("karolin", "kathrin")
//' @export
// [[Rcpp::export]]
 double hamming_normalized_distance(std::string s1, std::string s2, bool pad = true) {
   return rapidfuzz::hamming_normalized_distance(s1, s2, pad);
 }

//' @name hamming_normalized_similarity
//' @title Normalized Hamming Similarity
//' @description Calculates the normalized Hamming similarity between two strings.
//' @param s1 The first string.
//' @param s2 The second string.
//' @param pad If true, the strings are padded to the same length (default: TRUE).
//' @return A value between 0 and 1 representing the normalized similarity.
//' @examples
//' hamming_normalized_similarity("karolin", "kathrin")
//' @export
// [[Rcpp::export]]
 double hamming_normalized_similarity(std::string s1, std::string s2, bool pad = true) {
   return rapidfuzz::hamming_normalized_similarity(s1, s2, pad);
 }
