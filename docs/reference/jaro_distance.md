# Jaro Distance

Calculates the Jaro distance between two strings, a value between 0 and
1.

## Usage

``` r
jaro_distance(s1, s2)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

## Value

A numeric value representing the Jaro distance.

## Examples

``` r
jaro_distance("kitten", "sitting")
#> [1] 0.2539683
```
