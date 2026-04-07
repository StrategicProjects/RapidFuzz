# Distance Using OSA

Calculates the OSA distance between two strings.

## Usage

``` r
osa_distance(s1, s2, score_cutoff = NULL)
```

## Arguments

- s1:

  A string to compare.

- s2:

  Another string to compare.

- score_cutoff:

  A threshold for the distance score (default is the maximum possible
  size_t value).

## Value

An integer representing the OSA distance.

## Examples

``` r
osa_distance("string1", "string2")
#> [1] 1
```
