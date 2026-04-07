# Calculate the prefix similarity between two strings

Computes the similarity of the prefixes of two strings based on their
number of matching characters.

## Usage

``` r
prefix_similarity(s1, s2, score_cutoff = 0L)
```

## Arguments

- s1:

  A string. The first input string.

- s2:

  A string. The second input string.

- score_cutoff:

  An optional minimum threshold for the similarity score. Defaults to 0.

## Value

The prefix similarity as an integer.

## Examples

``` r
prefix_similarity("abcdef", "abcxyz")
#> [1] 3
prefix_similarity("abcdef", "abcxyz", score_cutoff = 3)
#> [1] 3
```
