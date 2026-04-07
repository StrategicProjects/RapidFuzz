# Normalized Levenshtein Distance

The normalized Levenshtein distance is the Levenshtein distance divided
by the maximum length of the compared strings, returning a value between
0 and 1.

## Usage

``` r
levenshtein_normalized_distance(s1, s2)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

## Value

A numeric value representing the normalized Levenshtein distance.

## Examples

``` r
levenshtein_normalized_distance("kitten", "sitting")
#> [1] 0.4285714
```
