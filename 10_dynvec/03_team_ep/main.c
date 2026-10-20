#include "team.h"
#include "teamvec.h"
#include <stdio.h>

int main(void) {
    FILE *f = fopen("teams.csv", "rt");
    if (f == NULL)
        return 1;

    TeamVec *tv = tv_create();

    int id, wins, draws, losses, goals_scored, goals_conceded;
    char name[50];
    while (fscanf(f, "%d,%49[^,],%d,%d,%d,%d,%d", &id, name, &wins, &draws,
                  &losses, &goals_scored, &goals_conceded) == 7) {
        Team *t = team_create(id, name, wins, draws, losses, goals_scored,
                               goals_conceded);
        tv_insert(tv, t);
    }
    fclose(f);

    printf("ID  Time            V   E   D   GM  GS  S   PG\n");
    for (int i = 0; i < tv_size(tv); i++) {
        Team *t = tv_get(tv, i);
        int goal_diff = team_goals_scored(t) - team_goals_conceded(t);
        int points = 3 * team_wins(t) + team_draws(t);
        printf("%-3d %-15s %-3d %-3d %-3d %-3d %-3d %-3d %-3d\n",
               team_id(t), team_name(t), team_wins(t), team_draws(t),
               team_losses(t), team_goals_scored(t), team_goals_conceded(t),
               goal_diff, points);
    }

    tv_free(tv);
    return 0;
}
