# Introduction to RapidFuzz

[`library`](https://rdrr.io/r/base/library.html)`(``RapidFuzz``)`` ``#> ``RapidFuzz`` v1.1.1 - High-performance string matching powered by rapidfuzz-cpp v3.3.4`

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

[`levenshtein_distance`](https://strategicprojects.github.io/RapidFuzz/reference/levenshtein_distance.md)`(``"kitten"``, ``"sitting"``)`` ``#> [1] 3`` `[`levenshtein_normalized_similarity`](https://strategicprojects.github.io/RapidFuzz/reference/levenshtein_normalized_similarity.md)`(``"kitten"``, ``"sitting"``)`` ``#> [1] 0.5714286`

### Comparing Multiple Metrics

Let’s compare how different metrics score the same pair of strings:

`s1`` ``<-`` ``"California"`` ``s2`` ``<-`` ``"Kalifornia"`` `` `[`data.frame`](https://rdrr.io/r/base/data.frame.html)`(`` `` metric ``=`` `[`c`](https://rdrr.io/r/base/c.html)`(``"Levenshtein"``, ``"Damerau-Levenshtein"``, ``"Hamming"``, ``"Jaro"``, `` `` ``"Jaro-Winkler"``, ``"LCSseq"``, ``"OSA"``, ``"Indel"``)``,`` `` distance ``=`` `[`c`](https://rdrr.io/r/base/c.html)`(`` `` `[`levenshtein_distance`](https://strategicprojects.github.io/RapidFuzz/reference/levenshtein_distance.md)`(``s1``, ``s2``)``,`` `` `[`damerau_levenshtein_distance`](https://strategicprojects.github.io/RapidFuzz/reference/damerau_levenshtein_distance.md)`(``s1``, ``s2``)``,`` `` `[`hamming_distance`](https://strategicprojects.github.io/RapidFuzz/reference/hamming_distance.md)`(``s1``, ``s2``)``,`` `` `[`round`](https://rdrr.io/r/base/Round.html)`(`[`jaro_distance`](https://strategicprojects.github.io/RapidFuzz/reference/jaro_distance.md)`(``s1``, ``s2``)``, ``4``)``,`` `` `[`round`](https://rdrr.io/r/base/Round.html)`(`[`jaro_winkler_distance`](https://strategicprojects.github.io/RapidFuzz/reference/jaro_winkler_distance.md)`(``s1``, ``s2``)``, ``4``)``,`` `` `[`lcs_seq_distance`](https://strategicprojects.github.io/RapidFuzz/reference/lcs_seq_distance.md)`(``s1``, ``s2``)``,`` `` `[`osa_distance`](https://strategicprojects.github.io/RapidFuzz/reference/osa_distance.md)`(``s1``, ``s2``)``,`` `` `[`indel_distance`](https://strategicprojects.github.io/RapidFuzz/reference/indel_distance.md)`(``s1``, ``s2``)`` `` ``)``,`` `` normalized_similarity ``=`` `[`c`](https://rdrr.io/r/base/c.html)`(`` `` `[`round`](https://rdrr.io/r/base/Round.html)`(`[`levenshtein_normalized_similarity`](https://strategicprojects.github.io/RapidFuzz/reference/levenshtein_normalized_similarity.md)`(``s1``, ``s2``)``, ``4``)``,`` `` `[`round`](https://rdrr.io/r/base/Round.html)`(`[`damerau_levenshtein_normalized_similarity`](https://strategicprojects.github.io/RapidFuzz/reference/damerau_levenshtein_normalized_similarity.md)`(``s1``, ``s2``)``, ``4``)``,`` `` `[`round`](https://rdrr.io/r/base/Round.html)`(`[`hamming_normalized_similarity`](https://strategicprojects.github.io/RapidFuzz/reference/hamming_normalized_similarity.md)`(``s1``, ``s2``)``, ``4``)``,`` `` `[`round`](https://rdrr.io/r/base/Round.html)`(`[`jaro_normalized_similarity`](https://strategicprojects.github.io/RapidFuzz/reference/jaro_normalized_similarity.md)`(``s1``, ``s2``)``, ``4``)``,`` `` `[`round`](https://rdrr.io/r/base/Round.html)`(`[`jaro_winkler_normalized_similarity`](https://strategicprojects.github.io/RapidFuzz/reference/jaro_winkler_normalized_similarity.md)`(``s1``, ``s2``)``, ``4``)``,`` `` `[`round`](https://rdrr.io/r/base/Round.html)`(`[`lcs_seq_normalized_similarity`](https://strategicprojects.github.io/RapidFuzz/reference/lcs_seq_normalized_similarity.md)`(``s1``, ``s2``)``, ``4``)``,`` `` `[`round`](https://rdrr.io/r/base/Round.html)`(`[`osa_normalized_similarity`](https://strategicprojects.github.io/RapidFuzz/reference/osa_normalized_similarity.md)`(``s1``, ``s2``)``, ``4``)``,`` `` `[`round`](https://rdrr.io/r/base/Round.html)`(`[`indel_normalized_similarity`](https://strategicprojects.github.io/RapidFuzz/reference/indel_normalized_similarity.md)`(``s1``, ``s2``)``, ``4``)`` `` ``)`` ``)`` ``#> metric distance normalized_similarity`` ``#> 1 Levenshtein 1.0000 0.9000`` ``#> 2 Damerau-Levenshtein 1.0000 0.9000`` ``#> 3 Hamming 1.0000 0.9000`` ``#> 4 Jaro 0.0667 0.9333`` ``#> 5 Jaro-Winkler 0.0667 0.9333`` ``#> 6 LCSseq 1.0000 0.9000`` ``#> 7 OSA 1.0000 0.9000`` ``#> 8 Indel 2.0000 0.9000`

------------------------------------------------------------------------

## 2. Fuzzy Matching with Fuzz Ratios

The `fuzz_*` family of functions provides different strategies for
comparing strings, especially useful when word order or partial matches
matter.

`# Exact content, different case/spacing`` `[`fuzz_ratio`](https://strategicprojects.github.io/RapidFuzz/reference/fuzz_ratio.md)`(``"New York City"``, ``"new york city"``)`` ``#> [1] 76.92308`` `` ``# Partial match: one string is contained in the other`` `[`fuzz_partial_ratio`](https://strategicprojects.github.io/RapidFuzz/reference/fuzz_partial_ratio.md)`(``"York"``, ``"New York City"``)`` ``#> [1] 100`` `` ``# Word order doesn't matter`` `[`fuzz_token_sort_ratio`](https://strategicprojects.github.io/RapidFuzz/reference/fuzz_token_sort_ratio.md)`(``"City of New York"``, ``"New York City"``)`` ``#> [1] 89.65517`` `` ``# Common tokens`` `[`fuzz_token_set_ratio`](https://strategicprojects.github.io/RapidFuzz/reference/fuzz_token_set_ratio.md)`(``"New York City NY"``, ``"New York City"``)`` ``#> [1] 100`` `` ``# Weighted ratio (best overall heuristic)`` `[`fuzz_WRatio`](https://strategicprojects.github.io/RapidFuzz/reference/fuzz_WRatio.md)`(``"New York City"``, ``"new york city!!"``)`` ``#> [1] 71.42857`

### New in v1.1.0: Partial Token Ratios

These combine the benefits of token-based comparison with partial
matching:

[`fuzz_partial_token_sort_ratio`](https://strategicprojects.github.io/RapidFuzz/reference/fuzz_partial_token_sort_ratio.md)`(``"Museum of Modern Art"``, ``"Modern Art Museum NYC"``)`` ``#> [1] 94.73684`` `[`fuzz_partial_token_set_ratio`](https://strategicprojects.github.io/RapidFuzz/reference/fuzz_partial_token_set_ratio.md)`(``"Museum of Modern Art"``, ``"Modern Art Museum NYC"``)`` ``#> [1] 100`` `[`fuzz_partial_token_ratio`](https://strategicprojects.github.io/RapidFuzz/reference/fuzz_partial_token_ratio.md)`(``"Museum of Modern Art"``, ``"Modern Art Museum NYC"``)`` ``#> [1] 100`

------------------------------------------------------------------------

## 3. Matching Against a List of Choices

A common task is finding the best match for a query within a list of
options. `RapidFuzz` provides three extract functions for this.

### Using US State Names

`# Misspelled state names`` ``queries`` ``<-`` `[`c`](https://rdrr.io/r/base/c.html)`(``"Kalifornia"``, ``"Nwe York"``, ``"Texs"``, ``"Florda"``, ``"Pensylvania"``)`` ``states`` ``<-`` ``state.name`` `` ``# Find the best match for each misspelled name`` ``results`` ``<-`` `[`lapply`](https://rdrr.io/r/base/lapply.html)`(``queries``, ``function``(``q``)`` ``{`` `` ``best`` ``<-`` `[`extract_best_match`](https://strategicprojects.github.io/RapidFuzz/reference/extract_best_match.md)`(``q``, ``states``, score_cutoff ``=`` ``0``)`` `` `[`data.frame`](https://rdrr.io/r/base/data.frame.html)`(`` `` query ``=`` ``q``,`` `` best_match ``=`` ``best``$``choice``,`` `` score ``=`` `[`round`](https://rdrr.io/r/base/Round.html)`(``best``$``score``, ``2``)`` `` ``)`` ``}``)`` `` `[`do.call`](https://rdrr.io/r/base/do.call.html)`(``rbind``, ``results``)`` ``#> query best_match score`` ``#> 1 Kalifornia California 90.00`` ``#> 2 Nwe York New York 87.50`` ``#> 3 Texs Texas 88.89`` ``#> 4 Florda Florida 92.31`` ``#> 5 Pensylvania Pennsylvania 95.65`

### Extract Top-N Matches

`# Find top 5 states similar to "New"`` `[`extract_matches`](https://strategicprojects.github.io/RapidFuzz/reference/extract_matches.md)`(``"New"``, ``states``, score_cutoff ``=`` ``50``, limit ``=`` ``5``, scorer ``=`` ``"PartialRatio"``)`` ``#> choice score`` ``#> 1 New Hampshire 100`` ``#> 2 New Jersey 100`` ``#> 3 New Mexico 100`` ``#> 4 New York 100`` ``#> 5 Maine 80`

### Extract All Matches Above a Threshold

`# All states with > 70% similarity to "North"`` `[`extract_similar_strings`](https://strategicprojects.github.io/RapidFuzz/reference/extract_similar_strings.md)`(``"North"``, ``states``, score_cutoff ``=`` ``70``)`` ``#> choice score`` ``#> 1 North Carolina 90`` ``#> 2 North Dakota 90`

------------------------------------------------------------------------

## 4. Choosing the Right Scorer

The
[`extract_matches()`](https://strategicprojects.github.io/RapidFuzz/reference/extract_matches.md)
function supports 10 different scorers. The best choice depends on your
data:

`query`` ``<-`` ``"san francisco"`` ``cities`` ``<-`` `[`c`](https://rdrr.io/r/base/c.html)`(``"San Francisco"``, ``"San Fernando"``, ``"Santa Fe"``, ``"San Diego"``,`` `` ``"Francisco"``, ``"South San Francisco"``, ``"San Fran"``)`` `` ``scorers`` ``<-`` `[`c`](https://rdrr.io/r/base/c.html)`(``"Ratio"``, ``"PartialRatio"``, ``"TokenSortRatio"``, ``"TokenSetRatio"``,`` `` ``"WRatio"``, ``"QRatio"``, ``"PartialTokenSortRatio"``,`` `` ``"PartialTokenSetRatio"``, ``"PartialTokenRatio"``, ``"TokenRatio"``)`` `` ``results`` ``<-`` `[`lapply`](https://rdrr.io/r/base/lapply.html)`(``scorers``, ``function``(``sc``)`` ``{`` `` ``m`` ``<-`` `[`extract_matches`](https://strategicprojects.github.io/RapidFuzz/reference/extract_matches.md)`(``query``, ``cities``, score_cutoff ``=`` ``0``, limit ``=`` ``3``, scorer ``=`` ``sc``)`` `` `[`data.frame`](https://rdrr.io/r/base/data.frame.html)`(``scorer ``=`` ``sc``, rank1 ``=`` ``m``$``choice``[``1``]``, score1 ``=`` `[`round`](https://rdrr.io/r/base/Round.html)`(``m``$``score``[``1``]``, ``1``)``)`` ``}``)`` `` `[`do.call`](https://rdrr.io/r/base/do.call.html)`(``rbind``, ``results``)`` ``#> scorer rank1 score1`` ``#> 1 Ratio San Francisco 100`` ``#> 2 PartialRatio San Francisco 100`` ``#> 3 TokenSortRatio San Francisco 100`` ``#> 4 TokenSetRatio San Francisco 100`` ``#> 5 WRatio San Francisco 100`` ``#> 6 QRatio San Francisco 100`` ``#> 7 PartialTokenSortRatio San Francisco 100`` ``#> 8 PartialTokenSetRatio San Francisco 100`` ``#> 9 PartialTokenRatio San Francisco 100`` ``#> 10 TokenRatio San Francisco 100`

------------------------------------------------------------------------

## 5. String Preprocessing

The
[`processString()`](https://strategicprojects.github.io/RapidFuzz/reference/processString.md)
function helps normalize strings before comparison:

`# Trim + lowercase`` `[`processString`](https://strategicprojects.github.io/RapidFuzz/reference/processString.md)`(``" São Paulo "``, processor ``=`` ``TRUE``, asciify ``=`` ``FALSE``)`` ``#> [1] "são paulo"`` `` ``# Trim + lowercase + ASCII transliteration`` `[`processString`](https://strategicprojects.github.io/RapidFuzz/reference/processString.md)`(``" São Paulo "``, processor ``=`` ``TRUE``, asciify ``=`` ``TRUE``)`` ``#> [1] "sao paulo"`` `` ``# ASCII only`` `[`processString`](https://strategicprojects.github.io/RapidFuzz/reference/processString.md)`(``"Ñoño"``, processor ``=`` ``FALSE``, asciify ``=`` ``TRUE``)`` ``#> [1] "Nono"`

This is especially useful for matching names with accented characters:

`# Without preprocessing`` `[`fuzz_ratio`](https://strategicprojects.github.io/RapidFuzz/reference/fuzz_ratio.md)`(``"São Paulo"``, ``"sao paulo"``)`` ``#> [1] 63.15789`` `` ``# With preprocessing`` `[`fuzz_ratio`](https://strategicprojects.github.io/RapidFuzz/reference/fuzz_ratio.md)`(`` `` `[`processString`](https://strategicprojects.github.io/RapidFuzz/reference/processString.md)`(``"São Paulo"``, processor ``=`` ``TRUE``, asciify ``=`` ``TRUE``)``,`` `` `[`processString`](https://strategicprojects.github.io/RapidFuzz/reference/processString.md)`(``"sao paulo"``, processor ``=`` ``TRUE``, asciify ``=`` ``TRUE``)`` ``)`` ``#> [1] 100`

------------------------------------------------------------------------

## 6. Edit Operations

Edit operations show exactly what transformations are needed to convert
one string into another.

`# Levenshtein edit operations`` ``ops`` ``<-`` `[`get_editops`](https://strategicprojects.github.io/RapidFuzz/reference/get_editops.md)`(``"saturday"``, ``"sunday"``)`` ``ops`` ``#> src_pos dest_pos type`` ``#> 1 1 1 delete`` ``#> 2 2 1 delete`` ``#> 3 4 2 replace`

`# Apply the operations`` `[`editops_apply_str`](https://strategicprojects.github.io/RapidFuzz/reference/editops_apply_str.md)`(``ops``, ``"saturday"``, ``"sunday"``)`` ``#> [1] "saturday"`

`# LCSseq edit operations`` `[`lcs_seq_editops`](https://strategicprojects.github.io/RapidFuzz/reference/lcs_seq_editops.md)`(``"kitten"``, ``"sitting"``)`` ``#> operation source_position destination_position`` ``#> 1 insert 0 0`` ``#> 2 delete 0 1`` ``#> 3 insert 4 4`` ``#> 4 delete 4 5`` ``#> 5 insert 6 6`

------------------------------------------------------------------------

## 7. Prefix and Postfix Matching

Useful for comparing strings that share beginnings or endings:

`# Same prefix "inter"`` `[`prefix_similarity`](https://strategicprojects.github.io/RapidFuzz/reference/prefix_similarity.md)`(``"international"``, ``"internet"``)`` ``#> [1] 6`` `[`prefix_normalized_similarity`](https://strategicprojects.github.io/RapidFuzz/reference/prefix_normalized_similarity.md)`(``"international"``, ``"internet"``)`` ``#> [1] 0.4615385`` `` ``# Same postfix "tion"`` `[`postfix_similarity`](https://strategicprojects.github.io/RapidFuzz/reference/postfix_similarity.md)`(``"education"``, ``"formation"``)`` ``#> [1] 5`` `[`postfix_normalized_similarity`](https://strategicprojects.github.io/RapidFuzz/reference/postfix_normalized_similarity.md)`(``"education"``, ``"formation"``)`` ``#> [1] 0.5555556`

------------------------------------------------------------------------

## 8. Practical Example: Record Linkage

A real-world scenario: matching messy data against a clean reference
list.

`# Simulated "dirty" records`` ``dirty`` ``<-`` `[`c`](https://rdrr.io/r/base/c.html)`(``"J. Smith"``, ``"Jane M. Doe"``, ``"Bob Johnson Jr"``, `` `` ``"Alice Wonderland"``, ``"Charlie Browne"``)`` `` ``# Clean reference list`` ``clean`` ``<-`` `[`c`](https://rdrr.io/r/base/c.html)`(``"John Smith"``, ``"Jane Mary Doe"``, ``"Robert Johnson Junior"``,`` `` ``"Alice Wonder"``, ``"Charles Brown"``, ``"David Lee"``)`` `` ``# Match each dirty record to the best clean record`` ``matches`` ``<-`` `[`lapply`](https://rdrr.io/r/base/lapply.html)`(``dirty``, ``function``(``d``)`` ``{`` `` ``best`` ``<-`` `[`extract_best_match`](https://strategicprojects.github.io/RapidFuzz/reference/extract_best_match.md)`(``d``, ``clean``, score_cutoff ``=`` ``0``)`` `` `[`data.frame`](https://rdrr.io/r/base/data.frame.html)`(`` `` dirty_record ``=`` ``d``,`` `` matched_to ``=`` ``best``$``choice``,`` `` confidence ``=`` `[`round`](https://rdrr.io/r/base/Round.html)`(``best``$``score``, ``1``)`` `` ``)`` ``}``)`` `` `[`do.call`](https://rdrr.io/r/base/do.call.html)`(``rbind``, ``matches``)`` ``#> dirty_record matched_to confidence`` ``#> 1 J. Smith John Smith 77.8`` ``#> 2 Jane M. Doe Jane Mary Doe 83.3`` ``#> 3 Bob Johnson Jr Robert Johnson Junior 85.5`` ``#> 4 Alice Wonderland Alice Wonder 85.7`` ``#> 5 Charlie Browne Charles Brown 88.9`

------------------------------------------------------------------------

## 9. Performance Comparison with Base R

`RapidFuzz` is implemented in C++ and is significantly faster than pure
R alternatives for string matching tasks.

`# Compare performance: RapidFuzz vs base R adist`` ``s1`` ``<-`` `[`paste`](https://rdrr.io/r/base/paste.html)`(`[`sample`](https://rdrr.io/r/base/sample.html)`(``letters``, ``100``, replace ``=`` ``TRUE``)``, collapse ``=`` ``""``)`` ``s2`` ``<-`` `[`paste`](https://rdrr.io/r/base/paste.html)`(`[`sample`](https://rdrr.io/r/base/sample.html)`(``letters``, ``100``, replace ``=`` ``TRUE``)``, collapse ``=`` ``""``)`` `` ``bench`` ``<-`` `[`system.time`](https://rdrr.io/r/base/system.time.html)`(`` `` ``for`` ``(``i`` ``in`` ``1``:``1000``)`` `[`levenshtein_distance`](https://strategicprojects.github.io/RapidFuzz/reference/levenshtein_distance.md)`(``s1``, ``s2``)`` ``)`` `` ``bench_base`` ``<-`` `[`system.time`](https://rdrr.io/r/base/system.time.html)`(`` `` ``for`` ``(``i`` ``in`` ``1``:``1000``)`` `[`adist`](https://rdrr.io/r/utils/adist.html)`(``s1``, ``s2``)`` ``)`` `` `[`data.frame`](https://rdrr.io/r/base/data.frame.html)`(`` `` method ``=`` `[`c`](https://rdrr.io/r/base/c.html)`(``"RapidFuzz"``, ``"base::adist"``)``,`` `` time_1000_calls ``=`` `[`c`](https://rdrr.io/r/base/c.html)`(``bench``[``"elapsed"``]``, ``bench_base``[``"elapsed"``]``)`` ``)`` ``#> method time_1000_calls`` ``#> 1 RapidFuzz 0.003`` ``#> 2 base::adist 0.051`

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
