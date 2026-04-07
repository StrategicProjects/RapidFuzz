# Postfix Similarity

Calculates the similarity between the postfixes of two strings.

## Usage

``` r
postfix_similarity(s1, s2, score_cutoff = 0L)
```

## Arguments

- s1:

  A string to compare.

- s2:

  Another string to compare.

- score_cutoff:

  A threshold for the similarity score (default is 0).

## Value

An integer representing the postfix similarity.

## Examples

``` r
postfix_similarity("string1", "string2")
#> [1] 0
```
