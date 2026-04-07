# Normalized LCSseq Distance

Calculates the normalized LCSseq distance between two strings.

## Usage

``` r
lcs_seq_normalized_distance(s1, s2, score_cutoff = 1)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

- score_cutoff:

  Score threshold to stop calculation. Default is 1.0.

## Value

A numeric value representing the normalized LCSseq distance.

## Examples

``` r
lcs_seq_normalized_distance("kitten", "sitting")
#> [1] 0.4285714
```
