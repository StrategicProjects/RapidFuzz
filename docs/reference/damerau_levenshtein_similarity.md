# Damerau-Levenshtein Similarity

Calculate the Damerau-Levenshtein similarity between two strings.

Computes the similarity based on the Damerau-Levenshtein metric, which
considers transpositions in addition to substitutions, insertions, and
deletions.

## Usage

``` r
damerau_levenshtein_similarity(s1, s2, score_cutoff = 0L)
```

## Arguments

- s1:

  A string. The first input string.

- s2:

  A string. The second input string.

- score_cutoff:

  An optional minimum threshold for the similarity score. Defaults to 0.

## Value

The Damerau-Levenshtein similarity as an integer.

## Examples

``` r
damerau_levenshtein_similarity("abcdef", "abcfde")
#> [1] 4
damerau_levenshtein_similarity("abcdef", "abcfde", score_cutoff = 3)
#> [1] 4
```
