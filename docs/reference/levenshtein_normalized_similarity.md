# Normalized Levenshtein Similarity

The normalized Levenshtein similarity returns a value between 0 and 1,
indicating how similar the compared strings are.

## Usage

``` r
levenshtein_normalized_similarity(s1, s2)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

## Value

A numeric value representing the normalized Levenshtein similarity.

## Examples

``` r
levenshtein_normalized_similarity("kitten", "sitting")
#> [1] 0.5714286
```
