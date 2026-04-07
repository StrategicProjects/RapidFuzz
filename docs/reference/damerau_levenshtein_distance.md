# Damerau-Levenshtein Distance

Calculate the Damerau-Levenshtein distance between two strings.

Computes the Damerau-Levenshtein distance, which is an edit distance
allowing transpositions in addition to substitutions, insertions, and
deletions.

## Usage

``` r
damerau_levenshtein_distance(s1, s2, score_cutoff = NULL)
```

## Arguments

- s1:

  A string. The first input string.

- s2:

  A string. The second input string.

- score_cutoff:

  An optional maximum threshold for the distance. Defaults to the
  largest integer value in R (\`.Machine\$integer.max\`).

## Value

The Damerau-Levenshtein distance as an integer.

## Examples

``` r
damerau_levenshtein_distance("abcdef", "abcfde")
#> [1] 2
damerau_levenshtein_distance("abcdef", "abcfde", score_cutoff = 3)
#> [1] 2
```
