# Normalized Hamming Distance

Calculates the normalized Hamming distance between two strings.

## Usage

``` r
hamming_normalized_distance(s1, s2, pad = TRUE)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

- pad:

  If true, the strings are padded to the same length (default: TRUE).

## Value

A value between 0 and 1 representing the normalized distance.

## Examples

``` r
hamming_normalized_distance("karolin", "kathrin")
#> [1] 0.4285714
```
