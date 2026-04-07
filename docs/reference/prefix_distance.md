# Calculate the prefix distance between two strings

Computes the prefix distance, which measures the number of character
edits required to convert one prefix into another. This includes
insertions, deletions, and substitutions.

## Usage

``` r
prefix_distance(s1, s2, score_cutoff = NULL)
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

The prefix distance as an integer.

## Examples

``` r
prefix_distance("abcdef", "abcxyz")
#> [1] 3
prefix_distance("abcdef", "abcxyz", score_cutoff = 3)
#> [1] 3
```
