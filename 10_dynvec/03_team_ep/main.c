#include "team.h"
#include <stdio.h>

int main(void) {
    FILE *f = fopen("teams.csv", "rt");
    if (f == NULL)
        return 1;

    TeamVec *tv = tv_create();
    Team t;
    while (fscanf(f, "%d,%49[^,],%d,%d,%d,%d,%d", &t.id, t.name, &t.wins,
                  &t.draws, &t.losses, &t.goals_scored, &t.goals_conceded) == 7)
        tv_insert(tv, t);
    fclose(f);

    printf("ID  Time            V   E   D   GM  GS  S   PG\n");
    for (int i = 0; i < tv_size(tv); i++) {
        Team t = tv_get(tv, i);
        int goal_diff = t.goals_scored - t.goals_conceded;
        int points = 3 * t.wins + t.draws;
        printf("%-3d %-15s %-3d %-3d %-3d %-3d %-3d %-3d %-3d\n",
               t.id, t.name, t.wins, t.draws, t.losses,
               t.goals_scored, t.goals_conceded, goal_diff, points);
    }

    tv_free(tv);
    return 0;
}
