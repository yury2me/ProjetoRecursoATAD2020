#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "rating.h"

PtRating createRating(char *movieId, int maleVotes, int femaleVotes, 
					  int *votes, double score) {
PtRating r = (PtRating) malloc(sizeof(Rating));
strcpy(r->movieId, movieId);
r->maleVotes = maleVotes;
r->femaleVotes = femaleVotes;
if (votes == NULL) {
    for (int i=0; i<10; i++) {
        r->votes[i] = 0;
    }
} else {
    for (int i=0; i<10; i++) {
        r->votes[i] = votes[i];
    }
}
r->score = score;
return r;
}

PtRating createEmptyRating() {
    return createRating("tt00", 0, 0, NULL, 0.0);
}

void copyRating(PtRating dest, PtRating src) {
    dest = (PtRating) malloc(sizeof(Rating));
    strcpy(dest->movieId, src->movieId);
    dest->maleVotes = src->maleVotes;
    dest->femaleVotes = src->femaleVotes;
    for (int i=0; i<10; i++) {
        dest->votes[i] = src->votes[i];
    }
    dest->score = src->score;
}

double calculateScore(int *votes) {
	double numVotes = 0;
	double score = 0;
	for (int i=0; i<10; i++) {
		numVotes += votes[i];
		score += votes[i] * (10 - i);
	}
	score /= numVotes;
    score = ceil(score * 10) / 10;
	return score;
}

void printPtRating(PtRating rating) {
    printf("%s\n", rating->movieId);
    printf("\tMale votes: : %d\n", rating->maleVotes);
    printf("\tFemale votes: %d\n", rating->femaleVotes);
    printf("\tScore: %.1f\n\n", rating->score);
    printf("\t10: %d\n", rating->votes[0]);
    printf("\t 9: %d\n", rating->votes[1]);
    printf("\t 9: %d\n", rating->votes[2]);
    printf("\t 7: %d\n", rating->votes[3]);
    printf("\t 6: %d\n", rating->votes[4]);
    printf("\t 5: %d\n", rating->votes[5]);
    printf("\t 4: %d\n", rating->votes[6]);
    printf("\t 3: %d\n", rating->votes[7]);
    printf("\t 2: %d\n", rating->votes[8]);
    printf("\t 1: %d\n\n", rating->votes[9]);
}

void printRating(Rating rating) {
    printf("%s\n", rating.movieId);
    printf("\tMale votes: : %d\n", rating.maleVotes);
    printf("\tFemale votes: %d\n", rating.femaleVotes);
    printf("\tScore: %.1f\n\n", rating.score);
    printf("\t10: %d\n", rating.votes[0]);
    printf("\t 9: %d\n", rating.votes[1]);
    printf("\t 9: %d\n", rating.votes[2]);
    printf("\t 7: %d\n", rating.votes[3]);
    printf("\t 6: %d\n", rating.votes[4]);
    printf("\t 5: %d\n", rating.votes[5]);
    printf("\t 4: %d\n", rating.votes[6]);
    printf("\t 3: %d\n", rating.votes[7]);
    printf("\t 2: %d\n", rating.votes[8]);
    printf("\t 1: %d\n\n", rating.votes[9]);
}