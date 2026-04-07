# Levenshtein Similarity

Levenshtein similarity measures how similar two strings are, based on
the minimum number of operations required to make them identical.

## Usage

``` r
levenshtein_similarity(s1, s2)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

## Value

A numeric value representing the Levenshtein similarity.

## Examples

``` r
levenshtein_similarity("kitten", "sitting")
#> [1] 4
```
