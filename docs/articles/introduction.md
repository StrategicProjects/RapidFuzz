# Introduction to RapidFuzz

``` r

library(RapidFuzz)
#> RapidFuzz v1.1.0 - High-performance string matching powered by rapidfuzz-cpp v3.3.3
```

## Overview

`RapidFuzz` provides high-performance string similarity and distance
functions powered by the C++ library
[rapidfuzz-cpp](https://github.com/rapidfuzz/rapidfuzz-cpp). It is
useful for tasks such as record linkage, fuzzy matching, typo
correction, and deduplication.

This vignette demonstrates the main features of the package using data
readily available in R.

------------------------------------------------------------------------

## 1. Basic String Distances

### Levenshtein Distance

The Levenshtein distance counts the minimum number of single-character
edits (insertions, deletions, substitutions) needed to transform one
string into another.

``` r

levenshtein_distance("kitten", "sitting")
#> [1] 3
levenshtein_normalized_similarity("kitten", "sitting")
#> [1] 0.5714286
```

### Comparing Multiple Metrics

Let’s compare how different metrics score the same pair of strings:

``` r

s1 <- "California"
s2 <- "Kalifornia"

data.frame(
  metric = c("Levenshtein", "Damerau-Levenshtein", "Hamming", "Jaro", 
             "Jaro-Winkler", "LCSseq", "OSA", "Indel"),
  distance = c(
    levenshtein_distance(s1, s2),
    damerau_levenshtein_distance(s1, s2),
    hamming_distance(s1, s2),
    round(jaro_distance(s1, s2), 4),
    round(jaro_winkler_distance(s1, s2), 4),
    lcs_seq_distance(s1, s2),
    osa_distance(s1, s2),
    indel_distance(s1, s2)
  ),
  normalized_similarity = c(
    round(levenshtein_normalized_similarity(s1, s2), 4),
    round(damerau_levenshtein_normalized_similarity(s1, s2), 4),
    round(hamming_normalized_similarity(s1, s2), 4),
    round(jaro_normalized_similarity(s1, s2), 4),
    round(jaro_winkler_normalized_similarity(s1, s2), 4),
    round(lcs_seq_normalized_similarity(s1, s2), 4),
    round(osa_normalized_similarity(s1, s2), 4),
    round(indel_normalized_similarity(s1, s2), 4)
  )
)
#>                metric distance normalized_similarity
#> 1         Levenshtein   1.0000                0.9000
#> 2 Damerau-Levenshtein   1.0000                0.9000
#> 3             Hamming   1.0000                0.9000
#> 4                Jaro   0.0667                0.9333
#> 5        Jaro-Winkler   0.0667                0.9333
#> 6              LCSseq   1.0000                0.9000
#> 7                 OSA   1.0000                0.9000
#> 8               Indel   2.0000                0.9000
```

------------------------------------------------------------------------

## 2. Fuzzy Matching with Fuzz Ratios

The `fuzz_*` family of functions provides different strategies for
comparing strings, especially useful when word order or partial matches
matter.

``` r

# Exact content, different case/spacing
fuzz_ratio("New York City", "new york city")
#> [1] 76.92308

# Partial match: one string is contained in the other
fuzz_partial_ratio("York", "New York City")
#> [1] 100

# Word order doesn't matter
fuzz_token_sort_ratio("City of New York", "New York City")
#> [1] 89.65517

# Common tokens
fuzz_token_set_ratio("New York City NY", "New York City")
#> [1] 100

# Weighted ratio (best overall heuristic)
fuzz_WRatio("New York City", "new york city!!")
#> [1] 71.42857
```

### New in v1.1.0: Partial Token Ratios

These combine the benefits of token-based comparison with partial
matching:

``` r

fuzz_partial_token_sort_ratio("Museum of Modern Art", "Modern Art Museum NYC")
#> [1] 94.73684
fuzz_partial_token_set_ratio("Museum of Modern Art", "Modern Art Museum NYC")
#> [1] 100
fuzz_partial_token_ratio("Museum of Modern Art", "Modern Art Museum NYC")
#> [1] 100
```

------------------------------------------------------------------------

## 3. Matching Against a List of Choices

A common task is finding the best match for a query within a list of
options. `RapidFuzz` provides three extract functions for this.

### Using US State Names

``` r

# Misspelled state names
queries <- c("Kalifornia", "Nwe York", "Texs", "Florda", "Pensylvania")
states <- state.name

# Find the best match for each misspelled name
results <- lapply(queries, function(q) {
  best <- extract_best_match(q, states, score_cutoff = 0)
  data.frame(
    query = q,
    best_match = best$choice,
    score = round(best$score, 2)
  )
})

do.call(rbind, results)
#>         query   best_match score
#> 1  Kalifornia   California 90.00
#> 2    Nwe York     New York 87.50
#> 3        Texs        Texas 88.89
#> 4      Florda      Florida 92.31
#> 5 Pensylvania Pennsylvania 95.65
```

### Extract Top-N Matches

``` r

# Find top 5 states similar to "New"
extract_matches("New", states, score_cutoff = 50, limit = 5, scorer = "PartialRatio")
#>          choice score
#> 1 New Hampshire   100
#> 2    New Jersey   100
#> 3    New Mexico   100
#> 4      New York   100
#> 5         Maine    80
```

### Extract All Matches Above a Threshold

``` r

# All states with > 70% similarity to "North"
extract_similar_strings("North", states, score_cutoff = 70)
#>           choice score
#> 1 North Carolina    90
#> 2   North Dakota    90
```

------------------------------------------------------------------------

## 4. Choosing the Right Scorer

The
[`extract_matches()`](https://strategicprojects.github.io/RapidFuzz/reference/extract_matches.md)
function supports 10 different scorers. The best choice depends on your
data:

``` r

query <- "san francisco"
cities <- c("San Francisco", "San Fernando", "Santa Fe", "San Diego",
            "Francisco", "South San Francisco", "San Fran")

scorers <- c("Ratio", "PartialRatio", "TokenSortRatio", "TokenSetRatio",
             "WRatio", "QRatio", "PartialTokenSortRatio",
             "PartialTokenSetRatio", "PartialTokenRatio", "TokenRatio")

results <- lapply(scorers, function(sc) {
  m <- extract_matches(query, cities, score_cutoff = 0, limit = 3, scorer = sc)
  data.frame(scorer = sc, rank1 = m$choice[1], score1 = round(m$score[1], 1))
})

do.call(rbind, results)
#>                   scorer         rank1 score1
#> 1                  Ratio San Francisco    100
#> 2           PartialRatio San Francisco    100
#> 3         TokenSortRatio San Francisco    100
#> 4          TokenSetRatio San Francisco    100
#> 5                 WRatio San Francisco    100
#> 6                 QRatio San Francisco    100
#> 7  PartialTokenSortRatio San Francisco    100
#> 8   PartialTokenSetRatio San Francisco    100
#> 9      PartialTokenRatio San Francisco    100
#> 10            TokenRatio San Francisco    100
```

------------------------------------------------------------------------

## 5. String Preprocessing

The
[`processString()`](https://strategicprojects.github.io/RapidFuzz/reference/processString.md)
function helps normalize strings before comparison:

``` r

# Trim + lowercase
processString("  São Paulo  ", processor = TRUE, asciify = FALSE)
#> [1] "são paulo"

# Trim + lowercase + ASCII transliteration
processString("  São Paulo  ", processor = TRUE, asciify = TRUE)
#> [1] "sao paulo"

# ASCII only
processString("Ñoño", processor = FALSE, asciify = TRUE)
#> [1] "Nono"
```

This is especially useful for matching names with accented characters:

``` r

# Without preprocessing
fuzz_ratio("São Paulo", "sao paulo")
#> [1] 63.15789

# With preprocessing
fuzz_ratio(
  processString("São Paulo", processor = TRUE, asciify = TRUE),
  processString("sao paulo", processor = TRUE, asciify = TRUE)
)
#> [1] 100
```

------------------------------------------------------------------------

## 6. Edit Operations

Edit operations show exactly what transformations are needed to convert
one string into another.

``` r

# Levenshtein edit operations
ops <- get_editops("saturday", "sunday")
ops
#>   src_pos dest_pos    type
#> 1       1        1  delete
#> 2       2        1  delete
#> 3       4        2 replace
```

``` r

# Apply the operations
editops_apply_str(ops, "saturday", "sunday")
#> [1] "saturday"
```

``` r

# LCSseq edit operations
lcs_seq_editops("kitten", "sitting")
#>   operation source_position destination_position
#> 1    insert               0                    0
#> 2    delete               0                    1
#> 3    insert               4                    4
#> 4    delete               4                    5
#> 5    insert               6                    6
```

------------------------------------------------------------------------

## 7. Prefix and Postfix Matching

Useful for comparing strings that share beginnings or endings:

``` r

# Same prefix "inter"
prefix_similarity("international", "internet")
#> [1] 6
prefix_normalized_similarity("international", "internet")
#> [1] 0.4615385

# Same postfix "tion"
postfix_similarity("education", "formation")
#> [1] 5
postfix_normalized_similarity("education", "formation")
#> [1] 0.5555556
```

------------------------------------------------------------------------

## 8. Practical Example: Record Linkage

A real-world scenario: matching messy data against a clean reference
list.

``` r

# Simulated "dirty" records
dirty <- c("J. Smith", "Jane M. Doe", "Bob Johnson Jr", 
           "Alice Wonderland", "Charlie Browne")

# Clean reference list
clean <- c("John Smith", "Jane Mary Doe", "Robert Johnson Junior",
           "Alice Wonder", "Charles Brown", "David Lee")

# Match each dirty record to the best clean record
matches <- lapply(dirty, function(d) {
  best <- extract_best_match(d, clean, score_cutoff = 0)
  data.frame(
    dirty_record = d,
    matched_to = best$choice,
    confidence = round(best$score, 1)
  )
})

do.call(rbind, matches)
#>       dirty_record            matched_to confidence
#> 1         J. Smith            John Smith       77.8
#> 2      Jane M. Doe         Jane Mary Doe       83.3
#> 3   Bob Johnson Jr Robert Johnson Junior       85.5
#> 4 Alice Wonderland          Alice Wonder       85.7
#> 5   Charlie Browne         Charles Brown       88.9
```

------------------------------------------------------------------------

## 9. Performance Comparison with Base R

`RapidFuzz` is implemented in C++ and is significantly faster than pure
R alternatives for string matching tasks.

``` r

# Compare performance: RapidFuzz vs base R adist
s1 <- paste(sample(letters, 100, replace = TRUE), collapse = "")
s2 <- paste(sample(letters, 100, replace = TRUE), collapse = "")

bench <- system.time(
  for (i in 1:1000) levenshtein_distance(s1, s2)
)

bench_base <- system.time(
  for (i in 1:1000) adist(s1, s2)
)

data.frame(
  method = c("RapidFuzz", "base::adist"),
  time_1000_calls = c(bench["elapsed"], bench_base["elapsed"])
)
#>        method time_1000_calls
#> 1   RapidFuzz           0.002
#> 2 base::adist           0.035
```

------------------------------------------------------------------------

## Summary

| Task | Recommended Functions |
|----|----|
| Simple distance/similarity | `levenshtein_*`, `hamming_*` |
| Transpositions matter | `damerau_levenshtein_*`, `osa_*` |
| Fuzzy matching (general) | `fuzz_WRatio`, `fuzz_QRatio` |
| Partial string matching | `fuzz_partial_ratio`, `fuzz_partial_token_*` |
| Word-order independent | `fuzz_token_sort_ratio`, `fuzz_token_set_ratio` |
| Find best match in list | `extract_best_match`, `extract_matches` |
| Names with accents | [`processString()`](https://strategicprojects.github.io/RapidFuzz/reference/processString.md) + any metric |
| Common prefix/suffix | `prefix_*`, `postfix_*` |
| Edit operations detail | `get_editops`, `lcs_seq_editops`, `osa_editops` |
