# Weighted Ratio Calculation

Calculates a weighted ratio based on other ratio algorithms.

## Usage

``` r
fuzz_WRatio(s1, s2, score_cutoff = 0)
```

## Arguments

- s1:

  First string.

- s2:

  Second string.

- score_cutoff:

  Optional score cutoff threshold (default: 0.0).

## Value

A double representing the weighted ratio between the two strings.

## Examples

``` r
fuzz_WRatio("this is a test", "this is a test!")
#> [1] 96.55172
```
