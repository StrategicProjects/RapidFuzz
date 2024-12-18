% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{jaro_winkler_similarity}
\alias{jaro_winkler_similarity}
\title{Jaro-Winkler Similarity}
\usage{
jaro_winkler_similarity(s1, s2, prefix_weight = 0.1)
}
\arguments{
\item{s1}{The first string.}

\item{s2}{The second string.}

\item{prefix_weight}{The weight applied to the prefix (default: 0.1).}
}
\value{
A numeric value representing the Jaro-Winkler similarity.
}
\description{
Calculates the Jaro-Winkler similarity between two strings.
}
\examples{
jaro_winkler_similarity("kitten", "sitting")
}
