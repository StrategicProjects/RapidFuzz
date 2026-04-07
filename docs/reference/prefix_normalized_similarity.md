# Calculate the normalized prefix similarity between two strings

Computes the normalized similarity of the prefixes of two strings, where
the result is between 0.0 (completely different) and 1.0 (identical).

## Usage

``` r
prefix_normalized_similarity(s1, s2, score_cutoff = 0)
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

The normalized prefix similarity as a double.

## Examples

``` r
prefix_normalized_similarity("abcdef", "abcxyz")
#> [1] 0.5
prefix_normalized_similarity("abcdef", "abcxyz", score_cutoff = 0.7)
#> [1] 0
```
