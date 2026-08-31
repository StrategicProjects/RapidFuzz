# RapidFuzz (pacote R)

Wrapper R (Rcpp) da biblioteca header-only [rapidfuzz-cpp](https://github.com/rapidfuzz/rapidfuzz-cpp),
publicado no CRAN. Site em https://strategicprojects.github.io/RapidFuzz/ — GitHub Pages
servido de `main:/docs` (build legacy): reconstruir o pkgdown e dar push já publica.

## Como atualizar a lib C++ empacotada

O workflow `.github/workflows/check-upstream.yml` roda toda segunda 09:00 UTC e abre uma
issue quando sai release nova upstream (compara com a versão anotada no `Note:` do
DESCRIPTION — formato `source code (vX.Y.Z)`, não mudar esse formato sem ajustar o workflow).

Passos da atualização (feitos assim na 3.3.3 → 3.3.4, 2026-08-31):

1. Baixar o tarball da release e substituir `src/rapidfuzz/` inteiro, **preservando
   `src/rapidfuzz/rapidfuzz_all.hpp`** (header custom nosso, não existe upstream):
   `rsync -a --delete --exclude rapidfuzz_all.hpp <release>/rapidfuzz/ src/rapidfuzz/`
2. Atualizar a versão da lib em **4 lugares**: `DESCRIPTION` (campo Note), `R/zzz.R`
   (mensagem de startup), `README.Rmd` (2 menções) e `README.md`.
3. Bump de `Version:` e `Date:` no DESCRIPTION + entrada no `NEWS.md` + `cran-comments.md`.
4. Badge "devel version" no README.Rmd/README.md é hardcoded — atualizar junto.
5. `R CMD INSTALL --preclean .` + smoke test, depois `R CMD build` e
   `R CMD check --as-cran` no tarball.
6. `pkgdown::build_site()` para regenerar `docs/`.

## Armadilhas conhecidas

- A cópia local dos headers pode divergir do tarball da release só em comentários Doxygen
  (a 3.3.3 empacotada era snapshot do branch dev). Diferenças de comentário são seguras de
  sobrescrever; conferir com `diff -ru` antes.
- `.Rbuildignore` precisa cobrir `.github`, `.DS_Store` e `CLAUDE.md` — senão vira NOTE
  no check do CRAN ("hidden files").
- No check local, o NOTE "HTML Tidy antigo" é do ambiente (macOS), não aparece no CRAN.
- Não commitar `.DS_Store` (há alguns já modificados no working tree — deixar de fora).
- Commits de release ganham `CRAN-SUBMISSION` atualizado pelo devtools — commitar junto.

## Estado (2026-08-31)

v1.1.1 (rapidfuzz-cpp v3.3.4) submetida ao CRAN em 2026-08-31, aguardando aceitação.
Badges de CRAN status/downloads atualizam sozinhos após aceite; depois do aceite, rodar
`pkgdown::build_news()` para o site mostrar a data de release.
