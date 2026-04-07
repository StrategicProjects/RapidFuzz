# Normalized Damerau-Levenshtein Similarity

Calculate the normalized Damerau-Levenshtein similarity between two
strings.

Computes the normalized similarity based on the Damerau-Levenshtein
metric, where the result is between 0.0 (completely different) and 1.0
(identical).

## Usage

``` r
damerau_levenshtein_normalized_similarity(s1, s2, score_cutoff = 0)
```

## Arguments

- s1:

  A string. The first input string.

- s2:

  A string. The second input string.

- score_cutoff:

  An optional minimum threshold for the normalized similarity. Defaults
  to 0.0.

## Value

The normalized Damerau-Levenshtein similarity as a double.

## Examples

``` r
damerau_levenshtein_normalized_similarity("abcdef", "abcfde")
#> [1] 0.6666667
damerau_levenshtein_normalized_similarity("abcdef", "abcfde", score_cutoff = 0.7)
#> [1] 0
```
