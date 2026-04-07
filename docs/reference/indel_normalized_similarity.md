# Normalized Indel Similarity

Calculates the normalized insertion/deletion (Indel) similarity between
two strings.

## Usage

``` r
indel_normalized_similarity(s1, s2)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

## Value

A numeric value between 0 and 1 representing the normalized Indel
similarity.

## Examples

``` r
indel_normalized_similarity("kitten", "sitting")
#> [1] 0.6153846
```
