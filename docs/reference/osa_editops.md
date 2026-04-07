# Edit Operations Using OSA

Provides the edit operations required to transform one string into
another using the OSA algorithm.

## Usage

``` r
osa_editops(s1, s2)
```

## Arguments

- s1:

  A string to transform.

- s2:

  A target string.

## Value

A data frame with the following columns:

- operation:

  The type of operation (delete, insert, replace).

- source_position:

  The position in the source string.

- destination_position:

  The position in the target string.

## Examples

``` r
osa_editops("string1", "string2")
#>   operation source_position destination_position
#> 1    insert              -1                    6
#> 2    delete               6                   -1
```
