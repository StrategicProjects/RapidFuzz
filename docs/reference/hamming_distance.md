# Hamming Distance

Calculates the Hamming distance between two strings.

## Usage

``` r
hamming_distance(s1, s2, pad = TRUE)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

- pad:

  If true, the strings are padded to the same length (default: TRUE).

## Value

An integer representing the Hamming distance.

## Examples

``` r
hamming_distance("karolin", "kathrin")
#> [1] 3
```
