# LCSseq Similarity

Calculates the LCSseq similarity between two strings.

## Usage

``` r
lcs_seq_similarity(s1, s2, score_cutoff = 0L)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

- score_cutoff:

  Score threshold to stop calculation. Default is 0.

## Value

A numeric value representing the LCSseq similarity.

## Examples

``` r
lcs_seq_similarity("kitten", "sitting")
#> [1] 4
```
