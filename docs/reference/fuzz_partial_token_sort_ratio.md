# Partial Token Sort Ratio Calculation

Sorts the words in the strings and calculates the partial ratio between
them. This combines the advantages of token_sort_ratio and
partial_ratio.

## Usage

``` r
fuzz_partial_token_sort_ratio(s1, s2, score_cutoff = 0)
```

## Arguments

- s1:

  First string.

- s2:

  Second string.

- score_cutoff:

  Optional score cutoff threshold (default: 0.0).

## Value

A double representing the partial token sort ratio between the two
strings.

## Examples

``` r
fuzz_partial_token_sort_ratio("fuzzy wuzzy was a bear", "wuzzy fuzzy was a bear")
#> [1] 100
```
