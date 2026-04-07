# Jaro-Winkler Similarity

Calculates the Jaro-Winkler similarity between two strings.

## Usage

``` r
jaro_winkler_similarity(s1, s2, prefix_weight = 0.1)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

- prefix_weight:

  The weight applied to the prefix (default: 0.1).

## Value

A numeric value representing the Jaro-Winkler similarity.

## Examples

``` r
jaro_winkler_similarity("kitten", "sitting")
#> [1] 0.7460317
```
