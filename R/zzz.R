#' @importFrom cli col_blue style_bold
#' @importFrom Rcpp evalCpp
#' @useDynLib RapidFuzz, .registration=TRUE
NULL

.onAttach <- function(libname, pkgname) {
  packageStartupMessage(
    cli::col_blue(cli::style_bold("RapidFuzz")),
    " v", utils::packageVersion("RapidFuzz"),
    " - High-performance string matching powered by rapidfuzz-cpp v3.3.3"
  )
}
