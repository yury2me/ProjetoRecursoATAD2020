#pragma once

typedef struct rating {
	char movieId[15];	// Movie ID
	int maleVotes;		// Total of male votes
	int femaleVotes;	// Total of female votes
	int votes[10];		// Votes by scale
	double score;		// Weighted average
} Rating;

typedef struct rating Rating;

typedef Rating *PtRating;

PtRating createRating(char *movieId, int maleVotes, int femaleVotes, 
					  int *votes, double score);

PtRating createEmptyRating();

void copyRating(PtRating dest, PtRating src);

double calculateScore(int *votes);

void printPtRating(PtRating rating);

void printRating(Rating rating);