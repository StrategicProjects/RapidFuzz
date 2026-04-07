# Normalized Postfix Similarity

Calculates the normalized similarity between the postfixes of two
strings.

## Usage

``` r
postfix_normalized_similarity(s1, s2, score_cutoff = 0)
```

## Arguments

- s1:

  A string to compare.

- s2:

  Another string to compare.

- score_cutoff:

  A threshold for the normalized similarity score (default is 0.0).

## Value

A double representing the normalized postfix similarity.

## Examples

``` r
postfix_normalized_similarity("string1", "string2")
#> [1] 0
```
