# Quick Ratio Calculation

Calculates a quick ratio using fuzz ratio.

## Usage

``` r
fuzz_QRatio(s1, s2, score_cutoff = 0)
```

## Arguments

- s1:

  First string.

- s2:

  Second string.

- score_cutoff:

  Optional score cutoff threshold (default: 0.0).

## Value

A double representing the quick ratio between the two strings.

## Examples

``` r
fuzz_QRatio("this is a test", "this is a test!")
#> [1] 96.55172
```
