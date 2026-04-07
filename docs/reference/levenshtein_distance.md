# Levenshtein Distance

Calculates the Levenshtein distance between two strings, which
represents the minimum number of insertions, deletions, and
substitutions required to transform one string into the other.

## Usage

``` r
levenshtein_distance(s1, s2)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

## Value

A numeric value representing the Levenshtein distance.

## Examples

``` r
levenshtein_distance("kitten", "sitting")
#> [1] 3
```
