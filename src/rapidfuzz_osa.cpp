#include <Rcpp.h>
#include <rapidfuzz/details/PatternMatchVector.hpp>
#include <rapidfuzz/details/Range.hpp>
#include <rapidfuzz/details/distance.hpp>
#include <rapidfuzz/details/common.hpp>
#include <rapidfuzz/distance/OSA_impl.hpp>
#include <rapidfuzz/distance/LCSseq_impl.hpp>

#ifndef SIZE_MAX
#define SIZE_MAX static_cast<size_t>(-1)
#endif

using namespace Rcpp;

//' @name osa_normalized_similarity
//' @title Normalized Similarity Using OSA
//' @description Calculates the normalized similarity between two strings using the Optimal String Alignment (OSA) algorithm.
//' @param s1 A string to compare.
//' @param s2 Another string to compare.
//' @param score_cutoff A threshold for the normalized similarity score (default is 0.0).
//' @return A double representing the normalized similarity score.
//' @examples
//' osa_normalized_similarity("string1", "string2")
//' @export
// [[Rcpp::export]]
 double osa_normalized_similarity(std::string s1, std::string s2, double score_cutoff = 0.0) {
   double score_hint = 1.0;
   return rapidfuzz::detail::OSA::normalized_similarity(s1, s2, score_cutoff, score_hint);
 }

//' @name osa_editops
//' @title Edit Operations Using OSA
//' @description Provides the edit operations required to transform one string into another using the OSA algorithm.
//' @param s1 A string to transform.
//' @param s2 A target string.
//' @return A data frame with the following columns:
//' \describe{
//'   \item{operation}{The type of operation (delete, insert, replace).}
//'   \item{source_position}{The position in the source string.}
//'   \item{destination_position}{The position in the target string.}
//' }
//' @examples
//' osa_editops("string1", "string2")
//' @export
// [[Rcpp::export]]
 DataFrame osa_editops(std::string s1, std::string s2) {
   auto ops = rapidfuzz::detail::lcs_seq_editops(
     rapidfuzz::detail::Range(s1), rapidfuzz::detail::Range(s2)
   );

   std::vector<std::string> operation_types;
   std::vector<int> source_positions;
   std::vector<int> destination_positions;

   for (const auto& op : ops) {
     switch (op.type) {
     case rapidfuzz::EditType::Delete:
       operation_types.push_back("delete");
       source_positions.push_back(op.src_pos);
       destination_positions.push_back(-1);
       break;
     case rapidfuzz::EditType::Insert:
       operation_types.push_back("insert");
       source_positions.push_back(-1);
       destination_positions.push_back(op.dest_pos);
       break;
     case rapidfuzz::EditType::Replace:
       operation_types.push_back("replace");
       source_positions.push_back(op.src_pos);
       destination_positions.push_back(op.dest_pos);
       break;
     }
   }

   return DataFrame::create(
     Named("operation") = operation_types,
     Named("source_position") = source_positions,
     Named("destination_position") = destination_positions
   );
 }

//' @name osa_distance
//' @title Distance Using OSA
//' @description Calculates the OSA distance between two strings.
//' @param s1 A string to compare.
//' @param s2 Another string to compare.
//' @param score_cutoff A threshold for the distance score (default is the maximum possible size_t value).
//' @return An integer representing the OSA distance.
//' @examples
//' osa_distance("string1", "string2")
//' @export
// [[Rcpp::export]]
 size_t osa_distance(std::string s1, std::string s2, Rcpp::Nullable<double> score_cutoff = R_NilValue) {
   size_t cutoff_value = score_cutoff.isNull() ? std::numeric_limits<size_t>::max() : Rcpp::as<size_t>(score_cutoff);
   size_t score_hint = std::numeric_limits<size_t>::max();
   return rapidfuzz::detail::OSA::distance(s1, s2, cutoff_value, score_hint);
 }

//' @name osa_similarity
//' @title Similarity Using OSA
//' @description Calculates the OSA similarity between two strings.
//' @param s1 A string to compare.
//' @param s2 Another string to compare.
//' @param score_cutoff A threshold for the similarity score (default is 0).
//' @return An integer representing the OSA similarity.
//' @examples
//' osa_similarity("string1", "string2")
//' @export
// [[Rcpp::export]]
 size_t osa_similarity(std::string s1, std::string s2, size_t score_cutoff = 0) {
   size_t score_hint = 0;
   return rapidfuzz::detail::OSA::similarity(s1, s2, score_cutoff, score_hint);
 }

//' @name osa_normalized_distance
//' @title Normalized Distance Using OSA
//' @description Calculates the normalized OSA distance between two strings.
//' @param s1 A string to compare.
//' @param s2 Another string to compare.
//' @param score_cutoff A threshold for the normalized distance score (default is 1.0).
//' @return A double representing the normalized distance score.
//' @examples
//' osa_normalized_distance("string1", "string2")
//' @export
// [[Rcpp::export]]
 double osa_normalized_distance(std::string s1, std::string s2, double score_cutoff = 1.0) {
   double score_hint = 1.0;
   return rapidfuzz::detail::OSA::normalized_distance(s1, s2, score_cutoff, score_hint);
 }
