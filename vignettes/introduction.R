## ----include = FALSE----------------------------------------------------------
knitr::opts_chunk$set(
  collapse = TRUE,
  comment = "#>"
)

## ----setup--------------------------------------------------------------------
library(RapidFuzz)

## -----------------------------------------------------------------------------
levenshtein_distance("kitten", "sitting")
levenshtein_normalized_similarity("kitten", "sitting")

## -----------------------------------------------------------------------------
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

## -----------------------------------------------------------------------------
# Exact content, different case/spacing
fuzz_ratio("New York City", "new york city")

# Partial match: one string is contained in the other
fuzz_partial_ratio("York", "New York City")

# Word order doesn't matter
fuzz_token_sort_ratio("City of New York", "New York City")

# Common tokens
fuzz_token_set_ratio("New York City NY", "New York City")

# Weighted ratio (best overall heuristic)
fuzz_WRatio("New York City", "new york city!!")

## -----------------------------------------------------------------------------
fuzz_partial_token_sort_ratio("Museum of Modern Art", "Modern Art Museum NYC")
fuzz_partial_token_set_ratio("Museum of Modern Art", "Modern Art Museum NYC")
fuzz_partial_token_ratio("Museum of Modern Art", "Modern Art Museum NYC")

## -----------------------------------------------------------------------------
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

## -----------------------------------------------------------------------------
# Find top 5 states similar to "New"
extract_matches("New", states, score_cutoff = 50, limit = 5, scorer = "PartialRatio")

## -----------------------------------------------------------------------------
# All states with > 70% similarity to "North"
extract_similar_strings("North", states, score_cutoff = 70)

## -----------------------------------------------------------------------------
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

## -----------------------------------------------------------------------------
# Trim + lowercase
processString("  São Paulo  ", processor = TRUE, asciify = FALSE)

# Trim + lowercase + ASCII transliteration
processString("  São Paulo  ", processor = TRUE, asciify = TRUE)

# ASCII only
processString("Ñoño", processor = FALSE, asciify = TRUE)

## -----------------------------------------------------------------------------
# Without preprocessing
fuzz_ratio("São Paulo", "sao paulo")

# With preprocessing
fuzz_ratio(
  processString("São Paulo", processor = TRUE, asciify = TRUE),
  processString("sao paulo", processor = TRUE, asciify = TRUE)
)

## -----------------------------------------------------------------------------
# Levenshtein edit operations
ops <- get_editops("saturday", "sunday")
ops

## -----------------------------------------------------------------------------
# Apply the operations
editops_apply_str(ops, "saturday", "sunday")

## -----------------------------------------------------------------------------
# LCSseq edit operations
lcs_seq_editops("kitten", "sitting")

## -----------------------------------------------------------------------------
# Same prefix "inter"
prefix_similarity("international", "internet")
prefix_normalized_similarity("international", "internet")

# Same postfix "tion"
postfix_similarity("education", "formation")
postfix_normalized_similarity("education", "formation")

## -----------------------------------------------------------------------------
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

## -----------------------------------------------------------------------------
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

