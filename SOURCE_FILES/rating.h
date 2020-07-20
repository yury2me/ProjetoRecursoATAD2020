#pragma once

/**
 * @brief This struct is about the rating of a movie and it's statistics.
 * 
 */
typedef struct rating {
	char movieId[15];	// Movie ID
	int maleVotes;		// Total of male votes
	int femaleVotes;	// Total of female votes
	int votes[10];		// Votes by scale
	double score;		// Weighted average
} Rating;

typedef struct rating Rating;

typedef Rating *PtRating;

/**
 * @brief Create a Rating object.
 * 
 * @param movieId ID of the movie
 * @param maleVotes Number of male votes
 * @param femaleVotes Number of female votes
 * @param votes Number of votes
 * @param score Score of the ratings
 * @return PtRating Pointer to a rating
 */
PtRating createRating(char *movieId, int maleVotes, int femaleVotes, 
					  int *votes, double score);

/**
 * @brief Create a Empty Rating object.
 * 
 * @return PtRating Pointer to a empty rating
 */
PtRating createEmptyRating();

/**
 * @brief This method creates a copy of a rating.
 * 
 * @param dest Pointer to copy to
 * @param src Pointer to copy from
 */
void copyRating(PtRating dest, PtRating src);

/**
 * @brief This method calculates the score of the movie.
 * 
 * @param votes Weighted votes
 * @return double Score
 */
double calculateScore(int *votes);

/**
 * @brief This method prints a rating from a pointer.
 * 
 * @param rating Rating to print
 */
void printPtRating(PtRating rating);

/**
 * @brief This method prints a rating and all it's characteristics.
 * 
 * @param rating Rating to print
 */
void printRating(Rating rating);