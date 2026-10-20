#include "team.h"
#include <stdlib.h>

// TODO: defina aqui os campos de "struct teamvec" -- pense no que o TAD
// precisa guardar para saber quantos times tem e quanto espaço ainda sobra
// struct teamvec {
//     ...
// };

// TODO: implemente tv_create -- aloca o TAD e um vetor inicial pequeno (ex.: 4 times)
TeamVec *tv_create(void) {

}

// TODO: implemente tv_insert -- se o vetor estiver cheio, dobre a capacidade
// (realloc) antes de inserir o novo time
void tv_insert(TeamVec *tv, Team t) {

}

// TODO: implemente tv_size -- retorna o número de times atualmente guardados
int tv_size(TeamVec *tv) {

}

// TODO: implemente tv_get -- retorna o time na posição i
Team tv_get(TeamVec *tv, int i) {

}

// TODO: implemente tv_free -- libera o vetor interno e depois o TAD
void tv_free(TeamVec *tv) {

}
