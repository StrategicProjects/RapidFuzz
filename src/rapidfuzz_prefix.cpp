#include <Rcpp.h>
#include <string>
#include <rapidfuzz/details/common.hpp>
#include <rapidfuzz/distance/Prefix.hpp>

#ifndef SIZE_MAX
#define SIZE_MAX static_cast<size_t>(-1)
#endif

//' Calculate the prefix distance between two strings
//'
//' Computes the prefix distance, which measures the number of character edits required to convert
//' one prefix into another. This includes insertions, deletions, and substitutions.
//'
//' @param s1 A string. The first input string.
//' @param s2 A string. The second input string.
//' @param score_cutoff An optional maximum threshold for the distance. Defaults to the largest
//' integer value in R (`.Machine$integer.max`).
//' @return The prefix distance as an integer.
//' @examples
//' prefix_distance("abcdef", "abcxyz")
//' prefix_distance("abcdef", "abcxyz", score_cutoff = 3)
//' @export
// [[Rcpp::export]]
 size_t prefix_distance(std::string s1, std::string s2, Rcpp::Nullable<double> score_cutoff = R_NilValue) {
   size_t cutoff_value = score_cutoff.isNull() ? std::numeric_limits<size_t>::max() : Rcpp::as<size_t>(score_cutoff);
   return rapidfuzz::prefix_distance(s1, s2, cutoff_value);
 }

//' Calculate the prefix similarity between two strings
//'
//' Computes the similarity of the prefixes of two strings based on their number of matching characters.
//'
//' @param s1 A string. The first input string.
//' @param s2 A string. The second input string.
//' @param score_cutoff An optional minimum threshold for the similarity score. Defaults to 0.
//' @return The prefix similarity as an integer.
//' @examples
//' prefix_similarity("abcdef", "abcxyz")
//' prefix_similarity("abcdef", "abcxyz", score_cutoff = 3)
//' @export
// [[Rcpp::export]]
 size_t prefix_similarity(std::string s1, std::string s2, size_t score_cutoff = 0) {
   return rapidfuzz::prefix_similarity(s1, s2, score_cutoff);
 }

//' Calculate the normalized prefix distance between two strings
//'
//' Computes the normalized distance of the prefixes of two strings, where the result is between
//' 0.0 (identical) and 1.0 (completely different).
//'
//' @param s1 A string. The first input string.
//' @param s2 A string. The second input string.
//' @param score_cutoff An optional maximum threshold for the normalized distance. Defaults to 1.0.
//' @return The normalized prefix distance as a double.
//' @examples
//' prefix_normalized_distance("abcdef", "abcxyz")
//' prefix_normalized_distance("abcdef", "abcxyz", score_cutoff = 0.5)
//' @export
// [[Rcpp::export]]
 double prefix_normalized_distance(std::string s1, std::string s2, double score_cutoff = 1.0) {
   return rapidfuzz::prefix_normalized_distance(s1, s2, score_cutoff);
 }

//' Calculate the normalized prefix similarity between two strings
//'
//' Computes the normalized similarity of the prefixes of two strings, where the result is between
//' 0.0 (completely different) and 1.0 (identical).
//'
//' @param s1 A string. The first input string.
//' @param s2 A string. The second input string.
//' @param score_cutoff An optional minimum threshold for the normalized similarity. Defaults to 0.0.
//' @return The normalized prefix similarity as a double.
//' @examples
//' prefix_normalized_similarity("abcdef", "abcxyz")
//' prefix_normalized_similarity("abcdef", "abcxyz", score_cutoff = 0.7)
//' @export
// [[Rcpp::export]]
 double prefix_normalized_similarity(std::string s1, std::string s2, double score_cutoff = 0.0) {
   return rapidfuzz::prefix_normalized_similarity(s1, s2, score_cutoff);
 }
