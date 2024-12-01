#include <Rcpp.h>
#include <rapidfuzz/distance.hpp>
#include <stdexcept>
#include <string>
#include <vector>

#ifndef SIZE_MAX
#define SIZE_MAX static_cast<size_t>(-1)
#endif

using namespace Rcpp;

//' @title Get Edit Operations
//' @description Generates edit operations between two strings.
//' @param s1 The source string.
//' @param s2 The target string.
//' @return A DataFrame with edit operations.
//' @export
// [[Rcpp::export]]
DataFrame get_editops(std::string s1, std::string s2) {
   auto ops = rapidfuzz::levenshtein_editops(s1, s2);

   std::vector<int> src_pos;
   std::vector<int> dest_pos;
   std::vector<std::string> op_type;

   for (const auto& op : ops) {
     src_pos.push_back(op.src_pos);
     dest_pos.push_back(op.dest_pos);

     if (op.type == rapidfuzz::EditType::Insert) {
       op_type.push_back("insert");
     } else if (op.type == rapidfuzz::EditType::Delete) {
       op_type.push_back("delete");
     } else if (op.type == rapidfuzz::EditType::Replace) {
       op_type.push_back("replace");
     }
   }

   return DataFrame::create(
     Named("src_pos") = src_pos,
     Named("dest_pos") = dest_pos,
     Named("type") = op_type
   );
 }



//' @title Apply Edit Operations to String
//' @description Applies edit operations to transform a string.
//' @param editops A data frame of edit operations (type, src_pos, dest_pos).
//' @param s1 The source string.
//' @param s2 The target string.
//' @return The transformed string.
//' @export
// [[Rcpp::export]]
 std::string editops_apply_str(Rcpp::DataFrame editops, std::string s1, std::string s2) {
   std::string result = s1;
   Rcpp::CharacterVector types = editops["type"];
   Rcpp::IntegerVector src_pos = editops["src_pos"];
   Rcpp::IntegerVector dest_pos = editops["dest_pos"];

// Offset para ajustar posições após inserções
   int offset = 0;

   for (int i = 0; i < types.size(); ++i) {
     std::string operation = Rcpp::as<std::string>(types[i]);

     if (operation == "replace") {
// Substituir caractere na posição src_pos por caractere em dest_pos
       int src_idx = src_pos[i] - 1;// Índice baseado em 0
       int dest_idx = dest_pos[i] - 1;// Índice baseado em 0
       if (src_idx >= 0 && src_idx < result.size() && dest_idx >= 0 && dest_idx < s2.size()) {
         result[src_idx] = s2[dest_idx];
       }
     } else if (operation == "insert") {
// Inserir caractere de dest_pos em s2 na posição dest_pos em result
       int dest_idx = dest_pos[i] - 1;// Índice baseado em 0
       if (dest_idx >= 0 && dest_idx < s2.size()) {
         result.insert(result.begin() + dest_idx + offset, s2[dest_idx]);
         offset++;// Ajustar deslocamento
       }
     }
   }

   return result;
 }


//' @title Apply Opcodes to String
//' @description Applies opcodes to transform a string.
//' @param opcodes A data frame of opcode transformations (type, src_begin, src_end, dest_begin, dest_end).
//' @param s1 The source string.
//' @param s2 The target string.
//' @return The transformed string.
//' @export
// [[Rcpp::export]]
 std::string opcodes_apply_str(Rcpp::DataFrame opcodes, std::string s1, std::string s2) {
   std::string result;// Resultado final
   size_t current_pos_s1 = 0;// Posição atual na string de origem (s1)

// Verificar integridade do DataFrame
   if (opcodes.nrows() == 0) {
     return s1;// Se não houver operações, retornar s1 inalterada
   }

// Obter as colunas do DataFrame
   std::vector<std::string> types = Rcpp::as<std::vector<std::string>>(opcodes["type"]);
   std::vector<int> src_begin = Rcpp::as<std::vector<int>>(opcodes["src_begin"]);
   std::vector<int> src_end = Rcpp::as<std::vector<int>>(opcodes["src_end"]);
   std::vector<int> dest_begin = Rcpp::as<std::vector<int>>(opcodes["dest_begin"]);
   std::vector<int> dest_end = Rcpp::as<std::vector<int>>(opcodes["dest_end"]);

// Processar cada opcode
   for (size_t i = 0; i < opcodes.nrows(); ++i) {
// Validar tipo de operação
     if (types[i] != "replace" && types[i] != "insert" && types[i] != "delete") {
       Rcpp::stop("Tipo de operação inválido na linha: " + std::to_string(i + 1));
     }

// Ajustar índices para 0-based
     size_t sbegin = (src_begin[i] != NA_INTEGER) ? src_begin[i] - 1 : s1.size();
     size_t send = (src_end[i] != NA_INTEGER) ? src_end[i] - 1 : s1.size();
     size_t dbegin = (dest_begin[i] != NA_INTEGER) ? dest_begin[i] - 1 : s2.size();
     size_t dend = (dest_end[i] != NA_INTEGER) ? dest_end[i] - 1 : s2.size();

// Adicionar os caracteres inalterados de s1 ao resultado
     while (current_pos_s1 < sbegin && current_pos_s1 < s1.size()) {
       result += s1[current_pos_s1++];
     }

// Aplicar a operação atual
     if (types[i] == "replace") {
// Substituir caracteres de s1 por caracteres de s2
       for (size_t j = dbegin; j <= dend && j < s2.size(); ++j) {
         result += s2[j];
       }
       current_pos_s1 = send + 1;// Avançar na string s1
     } else if (types[i] == "insert") {
// Inserir caracteres de s2
       for (size_t j = dbegin; j <= dend && j < s2.size(); ++j) {
         result += s2[j];
       }
     } else if (types[i] == "delete") {
// Remover caracteres de s1
       current_pos_s1 = send + 1;
     }
   }

// Adicionar os caracteres restantes de s1
   while (current_pos_s1 < s1.size()) {
     result += s1[current_pos_s1++];
   }

   return result;
 }


//' @title Apply Opcodes to Vector
//' @description Applies opcodes to transform a string.
//' @param opcodes A data frame of opcode transformations (type, src_begin, src_end, dest_begin, dest_end).
//' @param s1 The source string.
//' @param s2 The target string.
//' @return A character vector representing the transformed string.
//' @export
// [[Rcpp::export]]
 Rcpp::CharacterVector opcodes_apply_vec(Rcpp::DataFrame opcodes, std::string s1, std::string s2) {
   std::string result;
   size_t src_pos = 0;

 // Extrair os vetores do DataFrame
   Rcpp::CharacterVector types = opcodes["type"];
   Rcpp::IntegerVector src_begin = opcodes["src_begin"];
   Rcpp::IntegerVector src_end = opcodes["src_end"];
   Rcpp::IntegerVector dest_begin = opcodes["dest_begin"];
   Rcpp::IntegerVector dest_end = opcodes["dest_end"];

   for (size_t i = 0; i < opcodes.nrows(); ++i) {
   // Ajustar os índices 1-based para 0-based
     int sb = src_begin[i] != NA_INTEGER ? src_begin[i] - 1 : -1;
     int se = src_end[i] != NA_INTEGER ? src_end[i] - 1 : -1;
     int db = dest_begin[i] != NA_INTEGER ? dest_begin[i] - 1 : -1;
     int de = dest_end[i] != NA_INTEGER ? dest_end[i] - 1 : -1;

   // Copiar caracteres não modificados da string de origem
     while (src_pos < (size_t)sb && src_pos < s1.size()) {
       result += s1[src_pos];
       ++src_pos;
     }

   // Aplicar operação
     if (types[i] == "replace") {
       for (int j = db; j <= de && j < (int)s2.size(); ++j) {
         result += s2[j];
       }
       src_pos = se + 1;// Avançar na string de origem
     } else if (types[i] == "insert") {
       for (int j = db; j <= de && j < (int)s2.size(); ++j) {
         result += s2[j];
       }
     } else if (types[i] == "delete") {
       src_pos = se + 1;// Ignorar caracteres na string de origem
     }
   }

 // Adicionar quaisquer caracteres restantes da string de origem
   while (src_pos < s1.size()) {
     result += s1[src_pos];
     ++src_pos;
   }

 // Converter a string resultante para um vetor de caracteres
   Rcpp::CharacterVector output(result.size());
   for (size_t i = 0; i < result.size(); ++i) {
     output[i] = std::string(1, result[i]);
   }

   return output;
 }


//' @title Apply Edit Operations to Vector
//' @description Applies edit operations to transform a string.
//' @param editops A data frame of edit operations (type, src_pos, dest_pos).
//' @param s1 The source string.
//' @param s2 The target string.
//' @return A character vector representing the transformed string.
//' @export
// [[Rcpp::export]]
 Rcpp::CharacterVector editops_apply_vec(Rcpp::DataFrame editops, std::string s1, std::string s2) {
   std::string result;
   size_t src_pos = 0;

  // Extrair vetores do DataFrame
   Rcpp::CharacterVector types = editops["type"];
   Rcpp::IntegerVector src_positions = editops["src_pos"];
   Rcpp::IntegerVector dest_positions = editops["dest_pos"];

   for (size_t i = 0; i < editops.nrows(); ++i) {
    // Ajustar índices 1-based para 0-based
     int sp = src_positions[i] != NA_INTEGER ? src_positions[i] - 1 : -1;
     int dp = dest_positions[i] != NA_INTEGER ? dest_positions[i] - 1 : -1;

    // Copiar caracteres não modificados da string de origem
     while (src_pos < (size_t)sp && src_pos < s1.size()) {
       result += s1[src_pos];
       ++src_pos;
     }

    // Aplicar operação
     if (types[i] == "replace") {
       if (dp >= 0 && dp < (int)s2.size()) {
         result += s2[dp];
       }
       src_pos = sp + 1;// Avançar na string de origem
     } else if (types[i] == "insert") {
       if (dp >= 0 && dp < (int)s2.size()) {
         result += s2[dp];
       }
     } else if (types[i] == "delete") {
       src_pos = sp + 1;// Ignorar caractere na string de origem
     }
   }

  // Adicionar quaisquer caracteres restantes da string de origem
   while (src_pos < s1.size()) {
     result += s1[src_pos];
     ++src_pos;
   }

  // Converter a string resultante para um vetor de caracteres
   Rcpp::CharacterVector output(result.size());
   for (size_t i = 0; i < result.size(); ++i) {
     output[i] = std::string(1, result[i]);
   }

   return output;
 }
