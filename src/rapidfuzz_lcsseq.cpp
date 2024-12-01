#include <Rcpp.h>
#include "rapidfuzz/distance/LCSseq.hpp"

#ifndef SIZE_MAX
#define SIZE_MAX static_cast<size_t>(-1)
#endif

using namespace Rcpp;

//' @name lcs_seq_distance
//' @title LCSseq Distance
//' @description Calculates the LCSseq (Longest Common Subsequence) distance between two strings.
//' @param s1 The first string.
//' @param s2 The second string.
//' @param score_cutoff Score threshold to stop calculation. Default is the maximum possible value.
//' @return A numeric value representing the LCSseq distance.
//' @examples
//' lcs_seq_distance("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 size_t lcs_seq_distance(std::string s1, std::string s2, Rcpp::Nullable<double> score_cutoff = R_NilValue) {
   size_t cutoff_value = score_cutoff.isNull() ? std::numeric_limits<size_t>::max() : Rcpp::as<size_t>(score_cutoff);
   return rapidfuzz::lcs_seq_distance(s1, s2, cutoff_value);
 }


//' @name lcs_seq_similarity
//' @title LCSseq Similarity
//' @description Calculates the LCSseq similarity between two strings.
//' @param s1 The first string.
//' @param s2 The second string.
//' @param score_cutoff Score threshold to stop calculation. Default is 0.
//' @return A numeric value representing the LCSseq similarity.
//' @examples
//' lcs_seq_similarity("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 size_t lcs_seq_similarity(std::string s1, std::string s2, size_t score_cutoff = 0) {
   return rapidfuzz::lcs_seq_similarity(s1, s2, score_cutoff);
 }

//' @name lcs_seq_normalized_distance
//' @title Normalized LCSseq Distance
//' @description Calculates the normalized LCSseq distance between two strings.
//' @param s1 The first string.
//' @param s2 The second string.
//' @param score_cutoff Score threshold to stop calculation. Default is 1.0.
//' @return A numeric value representing the normalized LCSseq distance.
//' @examples
//' lcs_seq_normalized_distance("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 double lcs_seq_normalized_distance(std::string s1, std::string s2, double score_cutoff = 1.0) {
   return rapidfuzz::lcs_seq_normalized_distance(s1, s2, score_cutoff);
 }

//' @name lcs_seq_normalized_similarity
//' @title Normalized LCSseq Similarity
//' @description Calculates the normalized LCSseq similarity between two strings.
//' @param s1 The first string.
//' @param s2 The second string.
//' @param score_cutoff Score threshold to stop calculation. Default is 0.0.
//' @return A numeric value representing the normalized LCSseq similarity.
//' @examples
//' lcs_seq_normalized_similarity("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 double lcs_seq_normalized_similarity(std::string s1, std::string s2, double score_cutoff = 0.0) {
   return rapidfuzz::lcs_seq_normalized_similarity(s1, s2, score_cutoff);
 }

//' @name lcs_seq_editops
//' @title LCSseq Edit Operations
//' @description Calculates the edit operations required to transform one string into another.
//' @param s1 The first string.
//' @param s2 The second string.
//' @return A data.frame containing the edit operations (substitutions, insertions, and deletions).
//' @examples
//' lcs_seq_editops("kitten", "sitting")
//' @export
// [[Rcpp::export]]
 DataFrame lcs_seq_editops(std::string s1, std::string s2) {
   auto ops = rapidfuzz::lcs_seq_editops(s1, s2);
   std::vector<std::string> op_types;
   std::vector<int> src_pos;
   std::vector<int> dest_pos;

   for (const auto& op : ops) {
     op_types.push_back(op.type == rapidfuzz::EditType::Delete ? "delete" :
                          op.type == rapidfuzz::EditType::Insert ? "insert" : "replace");
     src_pos.push_back(op.src_pos);
     dest_pos.push_back(op.dest_pos);
   }

   return DataFrame::create(Named("operation") = op_types,
                            Named("source_position") = src_pos,
                            Named("destination_position") = dest_pos);
 }
