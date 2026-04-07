# Hamming Similarity

Measures the similarity between two strings using the Hamming metric.

## Usage

``` r
hamming_similarity(s1, s2, pad = TRUE)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

- pad:

  If true, the strings are padded to the same length (default: TRUE).

## Value

An integer representing the similarity.

## Examples

``` r
hamming_similarity("karolin", "kathrin")
#> [1] 4
```
