#ifndef TEAM_H
#define TEAM_H

// Opaque type: a single football team's identification and accumulated
// stats. Standings (goal difference, points) are not stored -- they are
// always computed from the accessors below when needed.
typedef struct team Team;

// TODO: implemente team_create -- aloca o time, copia id/name e zera as 5
// estatísticas (wins, draws, losses, goals_scored, goals_conceded)
Team *team_create(int id, const char *name);

// TODO: implemente os acessos abaixo (um por campo)
int team_id(Team *t);
const char *team_name(Team *t);
int team_wins(Team *t);
int team_draws(Team *t);
int team_losses(Team *t);
int team_goals_scored(Team *t);
int team_goals_conceded(Team *t);

// TODO: implemente team_free
void team_free(Team *t);

#endif
