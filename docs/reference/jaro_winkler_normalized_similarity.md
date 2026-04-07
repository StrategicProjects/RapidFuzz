# Similaridade Normalizada Jaro-Winkler

Calcula a similaridade normalizada Jaro-Winkler entre duas strings.

## Usage

``` r
jaro_winkler_normalized_similarity(s1, s2, prefix_weight = 0.1)
```

## Arguments

- s1:

  Primeira string.

- s2:

  Segunda string.

- prefix_weight:

  Peso do prefixo (valor padrão: 0.1).

## Value

Um valor numérico representando a similaridade normalizada Jaro-Winkler.

## Examples

``` r
jaro_winkler_normalized_similarity("kitten", "sitting")
#> [1] 0.7460317
```
