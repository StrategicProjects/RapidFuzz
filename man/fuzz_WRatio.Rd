% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{fuzz_WRatio}
\alias{fuzz_WRatio}
\title{Weighted Ratio Calculation}
\usage{
fuzz_WRatio(s1, s2, score_cutoff = 0)
}
\arguments{
\item{s1}{First string.}

\item{s2}{Second string.}

\item{score_cutoff}{Optional score cutoff threshold (default: 0.0).}
}
\value{
A double representing the weighted ratio between the two strings.
}
\description{
Calculates a weighted ratio based on other ratio algorithms.
}
\examples{
fuzz_WRatio("this is a test", "this is a test!")
}
