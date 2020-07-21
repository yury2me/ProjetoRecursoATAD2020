#pragma once

#include "list.h"
#include "map.h"

/**
 * @brief Reads the movies file and adds them to the list.
 * 
 * @param list List to add the values to
 */
void loadm(PtList *list);

/**
 * @brief Gets the first element of a string
 * 
 * @param sequence String to get the from
 * @return char* first element after ','
 */
char* firstElementSelector(char *sequence);

/**
 * @brief This method splits a string into an array given the number of fields and an delimiter
 * 
 * @param string string to transform
 * @param nFields capacity of the array
 * @param delim delimiter
 * @return char** Array of strings
 */
char** split(char *string, int nFields, const char *delim);

/**
 * @brief Removes char from string
 * 
 * @param str String to remove from
 * @param c Char to remove to
 */
void removeChar(char *str, char c);

/**
 * @brief reads the ratings file and adds them to the map.
 * 
 * @param map Map to add to
 */
void loadr(PtMap *map);

/**
 * @brief Shows the top 5 movies with the best rating.
 * 
 * @param list List of movies
 * @param map Map of ratings
 */
void top5(PtList list, PtMap map);

/**
 * @brief Create a New Key object
 * 
 * @param movieId ID of a movie
 * @return MapKey 
 */
MapKey createNewKey(char *movieId);

/**
 * @brief Given an id of a movie shows that movie and shows a list a sorted list of movies from the same director.
 * 
 * @param list List of movies
 */
void sameDir(PtList list);

/**
 * @brief Shows the user a matrix with the principal genders and from 2014 to 2018. 
 * @param list List of movies
 */
void matrix(PtList list);

/**
 * @brief Get the Matrix Cell Value.
 * 
 * @param list List of movies
 * @param year Year to count from
 * @param genre Gender to count from
 * @return int Count
 */
int getMatrixCellValue(PtList list, int year, char *genre);

/**
 * @brief Prints the matrix.
 * 
 * @param m Matrix
 */
void printMatrix(int m[5][8]);

/**
 * @brief Thid method searchs from the top5 in each category.
 * 
 * @param map Map of ratings
 * @param categoryList List of a certain category
 */
void best5Selector(PtMap map, PtList *categoryList);

/**
 * @brief Print top5 List
 * 
 * @param list List to print from
 */
void printTop5List(PtList list);

/**
 * @brief For a given year show the average rating for each gender.
 * 
 * @param list 
 * @param map 
 */
void year(PtList list, PtMap map);

/**
 * @brief Shows a list of movies in the given range.
 * 
 * @param list List of movies
 * @param map Map of ratings
 */
void rating(PtList list, PtMap map);

/**
 * @brief Given a country shows the total of produced movies and the average score.
 * 
 * @param list List of movies
 * @param map Map of ratings
 */
void country(PtList list, PtMap map);

/**
 * @brief Clear values from
 * 
 * @param list List of movies
 * @param map Map of ratings
 */
void clear(PtList list, PtMap map);

/**
 * @brief 
 * 
 * @param list 
 * @param map 
 */
void quitProg(PtList *list, PtMap *map);
