#pragma once

/**
 * @brief This struct is about a movie object and all the relevant characteristics.
 * 
 */
typedef struct movie {
	char id[15];		// Id format: CCNNNNNNN
	char title[100];	// Movie title
	int year;			// Year production
	char genre[10];		// Main genre
	int duration;		// Duration in minutes
	char country[40];	// Country production
	char director[50];	// Movie director
} Movie;

typedef struct movie Movie;

typedef Movie *PtMovie;
/**
 * @brief Create a Movie object.
 * 
 * @param id ID from movie
 * @param title Title of movie
 * @param year Year of movie's release
 * @param genre Gender of the movie
 * @param duration Duration of the movie
 * @param country Country where the movie was made
 * @param director Director of the movie
 * @return PtMovie Pointer to an movie object
 */
PtMovie createMovie(char *id, char *title, int year, char *genre, 
                    int duration, char *country, char * director);

/**
 * @brief Create a Empty Movie object.
 * 
 * @return PtMovie Pointer to an empty movie object
 */
PtMovie createEmptyMovie();

/**
 * @brief This method creates a copy of a movie.
 * 
 * @param dest Pointer to copy to
 * @param src Pointer to copy from
 */
void copyMovie(PtMovie dest, PtMovie src);

/**
 * @brief This method prints a Movie from a pointer, and all it's charactristics.
 * 
 * @param movie Movie to print
 */
void printPtMovie(PtMovie movie);

/**
 * @brief This method prints a Movie and all it's characteristics.
 * 
 * @param movie Movie to print
 */
void printMovie(Movie movie);