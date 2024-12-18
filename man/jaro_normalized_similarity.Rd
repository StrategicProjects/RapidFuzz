% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{jaro_normalized_similarity}
\alias{jaro_normalized_similarity}
\title{Normalized Jaro Similarity}
\usage{
jaro_normalized_similarity(s1, s2)
}
\arguments{
\item{s1}{The first string.}

\item{s2}{The second string.}
}
\value{
A numeric value representing the normalized Jaro similarity.
}
\description{
Calculates the normalized Jaro similarity between two strings, a value between 0 and 1.
}
\examples{
jaro_normalized_similarity("kitten", "sitting")
}
