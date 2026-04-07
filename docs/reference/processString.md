# Process a String

Processes a given input string by applying optional trimming, case
conversion, and ASCII transliteration.

## Usage

``` r
processString(input, processor = TRUE, asciify = FALSE)
```

## Arguments

- input:

  A `std::string` representing the input string to be processed.

- processor:

  A `bool` indicating whether to trim whitespace and convert the string
  to lowercase. Default is `true`.

- asciify:

  A `bool` indicating whether to transliterate non-ASCII characters to
  their closest ASCII equivalents. Default is `false`.

## Value

A `std::string` representing the processed string.

## Details

The function applies the following transformations to the input string,
in this order:

- **Trimming (if `processor = TRUE`):** Removes leading and trailing
  whitespace.

- **Lowercasing (if `processor = TRUE`):** Converts all characters to
  lowercase.

- **ASCII Transliteration (if `asciify = TRUE`):** Replaces accented or
  special characters with their closest ASCII equivalents.

## Examples

``` r
# Example usage
processString("  Éxâmple!  ", processor = TRUE, asciify = TRUE)
#> [1] "example!"
# Returns: "example!"

processString("  Éxâmple!  ", processor = TRUE, asciify = FALSE)
#> [1] "éxâmple!"
# Returns: "éxâmple!"

processString("  Éxâmple!  ", processor = FALSE, asciify = TRUE)
#> [1] "  Example!  "
# Returns: "Éxâmple!"

processString("  Éxâmple!  ", processor = FALSE, asciify = FALSE)
#> [1] "  Éxâmple!  "
# Returns: "  Éxâmple!  "
```
