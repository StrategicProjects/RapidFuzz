# Calculate the normalized prefix distance between two strings

Computes the normalized distance of the prefixes of two strings, where
the result is between 0.0 (identical) and 1.0 (completely different).

## Usage

``` r
prefix_normalized_distance(s1, s2, score_cutoff = 1)
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

The normalized prefix distance as a double.

## Examples

``` r
prefix_normalized_distance("abcdef", "abcxyz")
#> [1] 0.5
prefix_normalized_distance("abcdef", "abcxyz", score_cutoff = 0.5)
#> [1] 0.5
```
