#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

PtMovie createMovie(char *id, char *title, int year, char *genre, 
                    int duration, char *country, char * director) {
    PtMovie m = (PtMovie) malloc(sizeof(Movie));
    strcpy(m->id, id);
    strcpy(m->title, title);
    m->year = year;
    strcpy(m->genre, genre);
    m->duration = duration;
    strcpy(m->country, country);
    strcpy(m->director, director);
    return m;
}


PtMovie createEmptyMovie() {
    return createMovie("0", "0", 0, "0", 0, "0", "0");
}


void copyMovie(PtMovie dest, PtMovie src) {
    dest = (PtMovie) malloc(sizeof(Movie));
    strcpy(dest->id, src->id);
    strcpy(dest->title, src->title);
    dest->year = src->year;
    strcpy(dest->genre, src->genre);
    dest->duration = src->duration;
    strcpy(dest->country, src->country);
    strcpy(dest->director, src->director);
}


void printPtMovie(PtMovie movie) {
    printf("id: %-9s | ", movie->id);
    printf("title: %-34s | ", movie->title);
    printf("year: %-4d | ", movie->year);
    printf("genre: %-10s | ", movie->genre);
    printf("duration: %-3d | ", movie->duration);
    printf("country: %-13s | ", movie->country);
    printf("director: %s\n", movie->director);
}


void printMovie(Movie movie) {
    printf("id: %-9s | ", movie.id);
    printf("title: %-34s | ", movie.title);
    printf("year: %-4d | ", movie.year);
    printf("genre: %-10s | ", movie.genre);
    printf("duration: %-3d | ", movie.duration);
    printf("country: %-13s | ", movie.country);
    printf("director: %s\n", movie.director);

    // printf("\n%s\n", movie.title);
    // printf("\tId: %s\n", movie.id);
    // printf("\tYear: %d\n", movie.year);
    // printf("\tGenre: %s\n", movie.genre);
    // printf("\tDuration: %dmin\n", movie.duration);
    // printf("\tCountry: %s\n", movie.country);
    // printf("\tDirector: %s\n\n", movie.director);
}