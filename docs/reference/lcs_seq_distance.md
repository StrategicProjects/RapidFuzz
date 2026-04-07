# LCSseq Distance

Calculates the LCSseq (Longest Common Subsequence) distance between two
strings.

## Usage

``` r
lcs_seq_distance(s1, s2, score_cutoff = NULL)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

- score_cutoff:

  Score threshold to stop calculation. Default is the maximum possible
  value.

## Value

A numeric value representing the LCSseq distance.

## Examples

``` r
lcs_seq_distance("kitten", "sitting")
#> [1] 3
```
