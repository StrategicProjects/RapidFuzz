# Normalized Postfix Distance

Calculates the normalized distance between the postfixes of two strings.

## Usage

``` r
postfix_normalized_distance(s1, s2, score_cutoff = 1)
```

## Arguments

- s1:

  A string to compare.

- s2:

  Another string to compare.

- score_cutoff:

  A threshold for the normalized distance score (default is 1.0).

## Value

A double representing the normalized postfix distance.

## Examples

``` r
postfix_normalized_distance("string1", "string2")
#> [1] 1
```
