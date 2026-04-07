# LCSseq Edit Operations

Calculates the edit operations required to transform one string into
another.

## Usage

``` r
lcs_seq_editops(s1, s2)
```

## Arguments

- s1:

  The first string.

- s2:

  The second string.

## Value

A data.frame containing the edit operations (substitutions, insertions,
and deletions).

## Examples

``` r
lcs_seq_editops("kitten", "sitting")
#>   operation source_position destination_position
#> 1    insert               0                    0
#> 2    delete               0                    1
#> 3    insert               4                    4
#> 4    delete               4                    5
#> 5    insert               6                    6
```
