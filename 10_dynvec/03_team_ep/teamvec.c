#include "teamvec.h"
#include <stdlib.h>

// TODO: define the fields of "struct teamvec" here -- think about what the TAD needs to store
// to know how many teams it has and how much room is still left
// struct teamvec {
//     ...
// };

TeamVec *tv_create(void) {
    // TODO: allocate the TAD and a small initial array (e.g., 4 teams)
}

void tv_insert(TeamVec *tv, Team *t) {
    // TODO: if the array is full, double its capacity (realloc) before inserting the new team
}

int tv_size(TeamVec *tv) {
    // TODO: return the number of teams currently stored
}

Team *tv_get(TeamVec *tv, int i) {
    // TODO: return the team at position i
}

void tv_free(TeamVec *tv) {
    // TODO: free each stored team, the internal array and then the TAD
}
