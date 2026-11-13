#include "team.h"
#include "teamlist.h"
#include <stdio.h>

// This file must not depend on the implementation chosen in config.mk:
// use only the functions of team.h and teamlist.h.

int main(void) {
    TeamList *tl = tl_create();

    // TODO: read teams.csv (one line per team, in the format id,name), create
    // each team with team_create and insert it with tl_append

    // TODO: print the standings table (ID, Time, V, E, D, GM, GS, S, PG) in the
    // order the teams were read, using tl_size and tl_get

    tl_free(tl);
    return 0;
}
