# Extract Matches with Scoring and Limit

Compares a query string to a list of choices using the specified scorer
and returns the top matches with a similarity score above the cutoff.

## Usage

``` r
extract_matches(
  query,
  choices,
  score_cutoff = 50,
  limit = 3L,
  processor = TRUE,
  scorer = "WRatio"
)
```

## Arguments

- query:

  The query string to compare.

- choices:

  A vector of strings to compare against the query.

- score_cutoff:

  A numeric value specifying the minimum similarity score (default is
  50.0).

- limit:

  The maximum number of matches to return (default is 3).

- processor:

  A boolean indicating whether to preprocess strings before comparison
  (default is TRUE).

- scorer:

  A string specifying the similarity scoring method ("WRatio", "Ratio",
  "PartialRatio", etc.).

## Value

A data frame containing the top matched strings and their similarity
scores.
