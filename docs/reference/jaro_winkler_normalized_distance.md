# Normalized Jaro-Winkler Distance

Calculates the normalized Jaro-Winkler distance between two strings.

## Usage

``` r
jaro_winkler_normalized_distance(s1, s2, prefix_weight = 0.1)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

- prefix_weight:

  The weight applied to the prefix (default: 0.1).

## Value

A numeric value representing the normalized Jaro-Winkler distance.

## Examples

``` r
jaro_winkler_normalized_distance("kitten", "sitting")
#> [1] 0.2539683
```
