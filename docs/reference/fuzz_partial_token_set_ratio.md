# Partial Token Set Ratio Calculation

Compares the unique and common words in the strings and calculates the
partial ratio. This combines the advantages of token_set_ratio and
partial_ratio.

## Usage

``` r
fuzz_partial_token_set_ratio(s1, s2, score_cutoff = 0)
```

## Arguments

- s1:

  First string.

- s2:

  Second string.

- score_cutoff:

  Optional score cutoff threshold (default: 0.0).

## Value

A double representing the partial token set ratio between the two
strings.

## Examples

``` r
fuzz_partial_token_set_ratio("fuzzy wuzzy was a bear", "fuzzy fuzzy was a bear")
#> [1] 100
```
