# Partial Ratio Calculation

Calculates a partial ratio between two strings, which ignores long
mismatching substrings.

## Usage

``` r
fuzz_partial_ratio(s1, s2, score_cutoff = 0)
```

## Arguments

- s1:

  First string.

- s2:

  Second string.

- score_cutoff:

  Optional score cutoff threshold (default: 0.0).

## Value

A double representing the partial ratio between the two strings.

## Examples

``` r
fuzz_partial_ratio("this is a test", "this is a test!")
#> [1] 100
```
