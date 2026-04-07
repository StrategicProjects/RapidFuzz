#include <Rcpp.h>
#include <rapidfuzz/distance.hpp>

#ifndef SIZE_MAX
#define SIZE_MAX static_cast<size_t>(-1)
#endif

using namespace Rcpp;

//' @name postfix_distance
//' @title Postfix Distance
//' @description Calculates the distance between the postfixes of two strings.
//'
//' @param s1 A string to compare.
//' @param s2 Another string to compare.
//' @param score_cutoff A threshold for the distance score (default is the maximum possible size_t value).
//'
//' @return An integer representing the postfix distance.
//'
//' @examples
//' postfix_distance("string1", "string2")
//' @export
// [[Rcpp::export]]
size_t postfix_distance(std::string s1, std::string s2, Rcpp::Nullable<double> score_cutoff = R_NilValue) {
  size_t cutoff_value = score_cutoff.isNull() ? std::numeric_limits<size_t>::max() : Rcpp::as<size_t>(score_cutoff);
  return rapidfuzz::postfix_distance(s1, s2, cutoff_value);
}

//' @name postfix_similarity
//' @title Postfix Similarity
//' @description Calculates the similarity between the postfixes of two strings.
//'
//' @param s1 A string to compare.
//' @param s2 Another string to compare.
//' @param score_cutoff A threshold for the similarity score (default is 0).
//'
//' @return An integer representing the postfix similarity.
//'
//' @examples
//' postfix_similarity("string1", "string2")
//' @export
// [[Rcpp::export]]
size_t postfix_similarity(std::string s1, std::string s2, size_t score_cutoff = 0) {
  return rapidfuzz::postfix_similarity(s1, s2, score_cutoff);
}

//' @name postfix_normalized_distance
//' @title Normalized Postfix Distance
//' @description Calculates the normalized distance between the postfixes of two strings.
//'
//' @param s1 A string to compare.
//' @param s2 Another string to compare.
//' @param score_cutoff A threshold for the normalized distance score (default is 1.0).
//'
//' @return A double representing the normalized postfix distance.
//'
//' @examples
//' postfix_normalized_distance("string1", "string2")
//' @export
// [[Rcpp::export]]
double postfix_normalized_distance(std::string s1, std::string s2, double score_cutoff = 1.0) {
  return rapidfuzz::postfix_normalized_distance(s1, s2, score_cutoff);
}

//' @name postfix_normalized_similarity
//' @title Normalized Postfix Similarity
//' @description Calculates the normalized similarity between the postfixes of two strings.
//'
//' @param s1 A string to compare.
//' @param s2 Another string to compare.
//' @param score_cutoff A threshold for the normalized similarity score (default is 0.0).
//'
//' @return A double representing the normalized postfix similarity.
//'
//' @examples
//' postfix_normalized_similarity("string1", "string2")
//' @export
// [[Rcpp::export]]
double postfix_normalized_similarity(std::string s1, std::string s2, double score_cutoff = 0.0) {
  return rapidfuzz::postfix_normalized_similarity(s1, s2, score_cutoff);
}
