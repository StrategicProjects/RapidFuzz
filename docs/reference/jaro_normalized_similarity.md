# Normalized Jaro Similarity

Calculates the normalized Jaro similarity between two strings, a value
between 0 and 1.

## Usage

``` r
jaro_normalized_similarity(s1, s2)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

## Value

A numeric value representing the normalized Jaro similarity.

## Examples

``` r
jaro_normalized_similarity("kitten", "sitting")
#> [1] 0.7460317
```
