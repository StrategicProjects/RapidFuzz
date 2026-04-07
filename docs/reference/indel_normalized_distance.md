# Normalized Indel Distance

Calculates the normalized insertion/deletion (Indel) distance between
two strings.

## Usage

``` r
indel_normalized_distance(s1, s2)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

## Value

A numeric value between 0 and 1 representing the normalized Indel
distance.

## Examples

``` r
indel_normalized_distance("kitten", "sitting")
#> [1] 0.3846154
```
