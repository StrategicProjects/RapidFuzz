# Normalized Hamming Similarity

Calculates the normalized Hamming similarity between two strings.

## Usage

``` r
hamming_normalized_similarity(s1, s2, pad = TRUE)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

- pad:

  If true, the strings are padded to the same length (default: TRUE).

## Value

A value between 0 and 1 representing the normalized similarity.

## Examples

``` r
hamming_normalized_similarity("karolin", "kathrin")
#> [1] 0.5714286
```
