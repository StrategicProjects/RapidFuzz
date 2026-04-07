# Combined Token Ratio

Calculates the maximum ratio of token set ratio and token sort ratio.

## Usage

``` r
fuzz_token_ratio(s1, s2, score_cutoff = 0)
```

## Arguments

- s1:

  First string.

- s2:

  Second string.

- score_cutoff:

  Optional score cutoff threshold (default: 0.0).

## Value

A double representing the combined token ratio between the two strings.

## Examples

``` r
fuzz_token_ratio("fuzzy wuzzy was a bear", "wuzzy fuzzy was a bear")
#> [1] 100
```
