# Extract Best Match

Compares a query string to all strings in a list of choices and returns
the best match with a similarity score above the score_cutoff.

## Usage

``` r
extract_best_match(query, choices, score_cutoff = 50, processor = TRUE)
```

## Arguments

- query:

  The query string to compare.

- choices:

  A vector of strings to compare against the query.

- score_cutoff:

  A numeric value specifying the minimum similarity score (default is
  50.0).

- processor:

  A boolean indicating whether to preprocess strings before comparison
  (default is TRUE).

## Value

A list containing the best matching string and its similarity score.
