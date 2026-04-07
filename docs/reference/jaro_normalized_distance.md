# Normalized Jaro Distance

Calculates the normalized Jaro distance between two strings, a value
between 0 and 1.

## Usage

``` r
jaro_normalized_distance(s1, s2)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

## Value

A numeric value representing the normalized Jaro distance.

## Examples

``` r
jaro_normalized_distance("kitten", "sitting")
#> [1] 0.2539683
```
