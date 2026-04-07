# RapidFuzz 1.1.0

## Major Changes

* Updated the bundled `rapidfuzz-cpp` C++ library from v3.0.x to **v3.3.3**, bringing
  performance improvements and bug fixes from upstream:
    - Fixed `WRatio` for a length ratio of exactly 8.0.
    - Added C++11 and C++14 compatibility in the upstream library.
    - Improved calculation of minimum score inside `partial_ratio` to skip more alignments.
    - Fixed incorrect score calculation for SIMD implementations of Levenshtein and OSA on 32-bit systems.
    - Banded implementation of LCS/Indel for faster runtime with `score_cutoff`.

## New Features

* Added three new fuzzy matching functions from the upstream library:
    - `fuzz_partial_token_sort_ratio()`: combines token sorting with partial ratio matching.
    - `fuzz_partial_token_set_ratio()`: combines token set comparison with partial ratio matching.
    - `fuzz_partial_token_ratio()`: returns the maximum of `partial_token_set_ratio` and `partial_token_sort_ratio`.

* `extract_matches()` now supports additional scorers: `"TokenSortRatio"`,
  `"TokenSetRatio"`, `"TokenRatio"`, `"QRatio"`, `"PartialTokenSortRatio"`,
  `"PartialTokenSetRatio"`, and `"PartialTokenRatio"`, in addition to the existing
  `"WRatio"`, `"Ratio"`, and `"PartialRatio"`.

## Improvements

* Added `{cli}` package integration for formatted startup messages.
* Updated package documentation and website.

## Authors

* Added Marcos Wasilew and Carlos Amorin as package authors.

---

# RapidFuzz 1.0

* Initial CRAN submission.
