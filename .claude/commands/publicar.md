---
description: Commita e publica (push) as mudanças de um diretório específico do repositório
argument-hint: <dir> ex: docs/01_intro
---

Você vai commitar e publicar (push) **apenas** as mudanças dentro do
diretório `$ARGUMENTS`. Ao contrário do `/gerar`, este comando não abre
diálogo — é uma ação direta, mas cada passo abaixo existe para evitar
publicar algo indevido (arquivo errado, segredo, repositório em estado
inesperado). Não pule passos.

Se `$ARGUMENTS` estiver vazio, pergunte ao usuário qual diretório publicar
antes de continuar.

## 1. Escopo

- Confirme que `$ARGUMENTS` existe no repositório (working tree ou índice).
  Se não existir, avise o usuário e pare.
- Rode `git status --porcelain -- "$ARGUMENTS"` e `git diff -- "$ARGUMENTS"`
  (mudanças rastreadas) para levantar exatamente o que está
  modificado/novo **dentro desse diretório** — inclusive arquivos
  untracked (novos) dentro dele.
- Se não houver nada modificado/novo dentro de `$ARGUMENTS`, informe ao
  usuário que não há nada para publicar e pare — não crie commit vazio.
- **Não toque em nada fora de `$ARGUMENTS`.** É comum o repositório ter
  outras mudanças em andamento em paralelo (outros módulos, reorganizações
  do professor) — rode `git status` geral só para ter contexto de que
  existe mais coisa solta no repo, mas isso não faz parte deste commit.

## 2. Revisão antes de commitar

- Liste os arquivos que serão incluídos (modificados + novos, só dentro de
  `$ARGUMENTS`) e dê uma passada visual no diff/conteúdo dos novos —
  confirme que nada ali parece um segredo/credencial fora de lugar (baixo
  risco neste repo, que é só material didático estático, mas confira mesmo
  assim).
- Se algo dentro de `$ARGUMENTS` parecer incompleto ou quebrado à primeira
  vista (ex.: um HTML visivelmente truncado), avise o usuário antes de
  prosseguir em vez de publicar assim mesmo.

## 3. Commit

- Stage **só** o diretório: `git add -- "$ARGUMENTS"`.
- Confira com `git status` que nada fora de `$ARGUMENTS` foi staged.
- Escreva uma mensagem de commit curta e direta, no estilo já usado neste
  repositório (ver `git log --oneline` — mensagens curtas, no imperativo,
  ex.: "added ava.html", "update material", "added quiz for intro").
  Baseie a mensagem no que de fato mudou dentro de `$ARGUMENTS` (quais
  peças: `index.html`, `quiz/`, `ava.html`, `ep.html`, `FIGS.md`, `figs/`,
  etc.) — não um texto genérico tipo "update files".
- Siga o protocolo padrão de commits: **nunca** `git commit --amend`,
  `--no-verify` ou `--no-gpg-sign`; se um hook falhar, corrija o problema e
  crie um novo commit.

## 4. Push

- Antes de publicar, rode `git fetch` e confira se a branch local está à
  frente, atrás ou divergiu da remota (`git status` / `git rev-list
  --left-right --count HEAD...@{upstream}`).
  - Se a branch local estiver **atrás** ou **divergida**, **não force
    push** e não tente resolver sozinho — avise o usuário do conflito e
    pare, deixando o commit local intacto para ele decidir como
    prosseguir.
  - Se estiver só à frente (caso comum), prossiga.
- `git push` (com `-u origin <branch>` se a branch local ainda não tiver
  upstream configurado). Nunca `--force`/`--force-with-lease` a menos que o
  usuário peça explicitamente.

## 5. Relatório final

Resuma para o usuário, em poucas linhas:
- Quais arquivos entraram no commit (dentro de `$ARGUMENTS`).
- O hash e a mensagem do commit.
- Se o push teve sucesso (e o link do repositório/branch), ou o motivo de
  ter parado antes do push (nada para publicar, conflito com remoto, hook
  falhou, etc.).
- Se notou mudanças relevantes em outros lugares do repo que **não**
  entraram nesta publicação (fora de `$ARGUMENTS`), mencione brevemente
  para o usuário não esquecer delas — sem tocar nelas.
