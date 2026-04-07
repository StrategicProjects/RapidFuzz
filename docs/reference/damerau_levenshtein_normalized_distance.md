# Normalized Damerau-Levenshtein Distance

Calculate the normalized Damerau-Levenshtein distance between two
strings.

Computes the normalized Damerau-Levenshtein distance, where the result
is between 0.0 (identical) and 1.0 (completely different).

## Usage

``` r
damerau_levenshtein_normalized_distance(s1, s2, score_cutoff = 1)
```

## Arguments

- s1:

  A string. The first input string.

- s2:

  A string. The second input string.

- score_cutoff:

  An optional maximum threshold for the normalized distance. Defaults to
  1.0.

## Value

The normalized Damerau-Levenshtein distance as a double.

## Examples

``` r
damerau_levenshtein_normalized_distance("abcdef", "abcfde")
#> [1] 0.3333333
damerau_levenshtein_normalized_distance("abcdef", "abcfde", score_cutoff = 0.5)
#> [1] 0.3333333
```
