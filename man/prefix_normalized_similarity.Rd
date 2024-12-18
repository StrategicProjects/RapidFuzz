% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{prefix_normalized_similarity}
\alias{prefix_normalized_similarity}
\title{Calculate the normalized prefix similarity between two strings}
\usage{
prefix_normalized_similarity(s1, s2, score_cutoff = 0)
}
\arguments{
\item{s1}{A string. The first input string.}

\item{s2}{A string. The second input string.}

\item{score_cutoff}{An optional minimum threshold for the normalized similarity. Defaults to 0.0.}
}
\value{
The normalized prefix similarity as a double.
}
\description{
Computes the normalized similarity of the prefixes of two strings, where the result is between
0.0 (completely different) and 1.0 (identical).
}
\examples{
prefix_normalized_similarity("abcdef", "abcxyz")
prefix_normalized_similarity("abcdef", "abcxyz", score_cutoff = 0.7)
}
