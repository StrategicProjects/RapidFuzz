# Normalized LCSseq Similarity

Calculates the normalized LCSseq similarity between two strings.

## Usage

``` r
lcs_seq_normalized_similarity(s1, s2, score_cutoff = 0)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

- score_cutoff:

  Score threshold to stop calculation. Default is 0.0.

## Value

A numeric value representing the normalized LCSseq similarity.

## Examples

``` r
lcs_seq_normalized_similarity("kitten", "sitting")
#> [1] 0.5714286
```
