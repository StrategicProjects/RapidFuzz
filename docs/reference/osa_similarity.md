# Similarity Using OSA

Calculates the OSA similarity between two strings.

## Usage

``` r
osa_similarity(s1, s2, score_cutoff = 0L)
```

## Arguments

- s1:

  A string to compare.

- s2:

  Another string to compare.

- score_cutoff:

  A threshold for the similarity score (default is 0).

## Value

An integer representing the OSA similarity.

## Examples

``` r
osa_similarity("string1", "string2")
#> [1] 6
```
