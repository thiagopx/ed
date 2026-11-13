#include "team.h"
#include <stdlib.h>
#include <string.h>

// TODO: define the fields of "struct team" here
// struct team {
//     ...
// };

Team *team_create(int id, const char *name) {
    // TODO: allocate the team, copy id and name, and set the 5 stats to zero
}

int team_id(Team *t) {
    // TODO: implement this accessor (and the ones below, one per field)
}

const char *team_name(Team *t) {

}

int team_wins(Team *t) {

}

int team_draws(Team *t) {

}

int team_losses(Team *t) {

}

int team_goals_scored(Team *t) {

}

int team_goals_conceded(Team *t) {

}

void team_free(Team *t) {
    // TODO: implement team_free
}
