// A football team: identification and accumulated stats. Standings (goal difference, points)
// are not stored; they are always computed from the accessors below.

#ifndef TEAM_H
#define TEAM_H

typedef struct team Team;

// Returns a new team with the given id and name, and the 5 stats (wins, draws, losses,
//   goals_scored, goals_conceded) set to zero.
// Ownership: the caller (or the collection that stores it) frees it with team_free.
Team *team_create(int id, const char *name);

// Returns the id of t.
int team_id(Team *t);

// Returns the name of t (read-only).
const char *team_name(Team *t);

// Returns the number of wins of t.
int team_wins(Team *t);

// Returns the number of draws of t.
int team_draws(Team *t);

// Returns the number of losses of t.
int team_losses(Team *t);

// Returns the number of goals scored by t.
int team_goals_scored(Team *t);

// Returns the number of goals conceded by t.
int team_goals_conceded(Team *t);

// Frees the team t.
void team_free(Team *t);

#endif
