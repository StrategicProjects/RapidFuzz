% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{hamming_normalized_distance}
\alias{hamming_normalized_distance}
\title{Normalized Hamming Distance}
\usage{
hamming_normalized_distance(s1, s2, pad = TRUE)
}
\arguments{
\item{s1}{The first string.}

\item{s2}{The second string.}

\item{pad}{If true, the strings are padded to the same length (default: TRUE).}
}
\value{
A value between 0 and 1 representing the normalized distance.
}
\description{
Calculates the normalized Hamming distance between two strings.
}
\examples{
hamming_normalized_distance("karolin", "kathrin")
}
