# Normalized Similarity Using OSA

Calculates the normalized similarity between two strings using the
Optimal String Alignment (OSA) algorithm.

## Usage

``` r
osa_normalized_similarity(s1, s2, score_cutoff = 0)
```

## Arguments

- s1:

  A string to compare.

- s2:

  Another string to compare.

- score_cutoff:

  A threshold for the normalized similarity score (default is 0.0).

## Value

A double representing the normalized similarity score.

## Examples

``` r
osa_normalized_similarity("string1", "string2")
#> [1] 0.8571429
```
