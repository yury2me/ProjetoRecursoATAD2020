#pragma once

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

PtMovie createMovie(char *id, char *title, int year, char *genre, 
                    int duration, char *country, char * director);

PtMovie createEmptyMovie();

void copyMovie(PtMovie dest, PtMovie src);

void printPtMovie(PtMovie movie);

void printMovie(Movie movie);