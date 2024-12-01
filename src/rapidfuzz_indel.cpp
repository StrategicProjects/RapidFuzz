#include <Rcpp.h>
#include "rapidfuzz/distance/Indel.hpp"

#ifndef SIZE_MAX
#define SIZE_MAX static_cast<size_t>(-1)
#endif

using namespace Rcpp;

//' @name indel_distance
//' @title Indel Distance
//' @description Calculates the insertion/deletion (Indel) distance between two strings.
//' @param s1 The first string.
//' @param s2 The second string.
//' @return A numeric value representing the Indel distance.
//' @examples
//' indel_distance("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 size_t indel_distance(std::string s1, std::string s2) {
   return rapidfuzz::indel_distance(s1, s2);
 }

//' @name indel_normalized_distance
//' @title Normalized Indel Distance
//' @description Calculates the normalized insertion/deletion (Indel) distance between two strings.
//' @param s1 The first string.
//' @param s2 The second string.
//' @return A numeric value between 0 and 1 representing the normalized Indel distance.
//' @examples
//' indel_normalized_distance("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 double indel_normalized_distance(std::string s1, std::string s2) {
   return rapidfuzz::indel_normalized_distance(s1, s2);
 }

//' @name indel_similarity
//' @title Indel Similarity
//' @description Calculates the insertion/deletion (Indel) similarity between two strings.
//' @param s1 The first string.
//' @param s2 The second string.
//' @return A numeric value representing the Indel similarity.
//' @examples
//' indel_similarity("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 size_t indel_similarity(std::string s1, std::string s2) {
   return rapidfuzz::indel_similarity(s1, s2);
 }

//' @name indel_normalized_similarity
//' @title Normalized Indel Similarity
//' @description Calculates the normalized insertion/deletion (Indel) similarity between two strings.
//' @param s1 The first string.
//' @param s2 The second string.
//' @return A numeric value between 0 and 1 representing the normalized Indel similarity.
//' @examples
//' indel_normalized_similarity("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 double indel_normalized_similarity(std::string s1, std::string s2) {
   return rapidfuzz::indel_normalized_similarity(s1, s2);
 }
