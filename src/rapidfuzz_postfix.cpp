#include <Rcpp.h>
#include <rapidfuzz/details/Range.hpp>
#include <rapidfuzz/distance/Postfix_impl.hpp>

#ifndef SIZE_MAX
#define SIZE_MAX static_cast<size_t>(-1)
#endif

using namespace Rcpp;

/**
 * @title Postfix Distance
 * @description Calculates the distance between the postfixes of two strings.
 *
 * @param s1 A string to compare.
 * @param s2 Another string to compare.
 * @param score_cutoff A threshold for the distance score (default is the maximum possible size_t value).
 *
 * @return An integer representing the postfix distance.
 *
 * @examples
 * \dontrun{
 * postfix_distance("string1", "string2")
 * }
 */
// [[Rcpp::export]]
size_t postfix_distance(std::string s1, std::string s2, Rcpp::Nullable<double> score_cutoff = R_NilValue) {
  size_t cutoff_value = score_cutoff.isNull() ? std::numeric_limits<size_t>::max() : Rcpp::as<size_t>(score_cutoff);
  size_t score_hint = std::numeric_limits<size_t>::max();
  return rapidfuzz::detail::Postfix::distance(s1, s2, cutoff_value, score_hint);
}

/**
 * @title Postfix Similarity
 * @description Calculates the similarity between the postfixes of two strings.
 *
 * @param s1 A string to compare.
 * @param s2 Another string to compare.
 * @param score_cutoff A threshold for the similarity score (default is 0).
 *
 * @return An integer representing the postfix similarity.
 *
 * @examples
 * \dontrun{
 * postfix_similarity("string1", "string2")
 * }
 */
// [[Rcpp::export]]
size_t postfix_similarity(std::string s1, std::string s2, size_t score_cutoff = 0) {
  size_t score_hint = 0;
  return rapidfuzz::detail::Postfix::similarity(s1, s2, score_cutoff, score_hint);
}

/**
 * @title Normalized Postfix Distance
 * @description Calculates the normalized distance between the postfixes of two strings.
 *
 * @param s1 A string to compare.
 * @param s2 Another string to compare.
 * @param score_cutoff A threshold for the normalized distance score (default is 1.0).
 *
 * @return A double representing the normalized postfix distance.
 *
 * @examples
 * \dontrun{
 * postfix_normalized_distance("string1", "string2")
 * }
 */
// [[Rcpp::export]]
double postfix_normalized_distance(std::string s1, std::string s2, double score_cutoff = 1.0) {
  double score_hint = 1.0;
  return rapidfuzz::detail::Postfix::normalized_distance(s1, s2, score_cutoff, score_hint);
}

/**
 * @title Normalized Postfix Similarity
 * @description Calculates the normalized similarity between the postfixes of two strings.
 *
 * @param s1 A string to compare.
 * @param s2 Another string to compare.
 * @param score_cutoff A threshold for the normalized similarity score (default is 0.0).
 *
 * @return A double representing the normalized postfix similarity.
 *
 * @examples
 * \dontrun{
 * postfix_normalized_similarity("string1", "string2")
 * }
 */
// [[Rcpp::export]]
double postfix_normalized_similarity(std::string s1, std::string s2, double score_cutoff = 0.0) {
  double score_hint = 0.0;
  return rapidfuzz::detail::Postfix::normalized_similarity(s1, s2, score_cutoff, score_hint);
}
