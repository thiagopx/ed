#include "team.h"
#include "teamlist.h"
#include <stdio.h>

// Este arquivo não pode depender da implementação escolhida em config.mk:
// use apenas as funções de team.h e teamlist.h.

int main(void) {
    TeamList *tl = tl_create();

    // TODO: leia teams.csv (uma linha por time, no formato id,nome), crie
    // cada time com team_create e insira-o com tl_append

    // TODO: imprima a tabela de classificação (ID, Time, V, E, D, GM, GS, S,
    // PG) na ordem em que os times foram lidos, usando tl_size e tl_get

    tl_free(tl);
    return 0;
}
