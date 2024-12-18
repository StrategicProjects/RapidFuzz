% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{fuzz_QRatio}
\alias{fuzz_QRatio}
\title{Quick Ratio Calculation}
\usage{
fuzz_QRatio(s1, s2, score_cutoff = 0)
}
\arguments{
\item{s1}{First string.}

\item{s2}{Second string.}

\item{score_cutoff}{Optional score cutoff threshold (default: 0.0).}
}
\value{
A double representing the quick ratio between the two strings.
}
\description{
Calculates a quick ratio using fuzz ratio.
}
\examples{
fuzz_QRatio("this is a test", "this is a test!")
}
