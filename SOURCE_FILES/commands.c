
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "commands.h"
#include "list.h"
#include "map.h"

void quitProg(PtList *list, PtMap *map) {
	listDestroy(list);
	mapDestroy(map);
}

void country(PtList list, PtMap map) {
	char countryName[40];
	int lSize, tempSize, totalProducedMovies = 0;
	double score = 0.0;
	PtList temp = listCreate(10);
	PtMovie m = createEmptyMovie();
	PtRating mRat = createEmptyRating();

	listSize(list, &lSize);

	printf("\nIntroduza o nome do país sobre o qual pretende obter informação: ");
	scanf("%s", countryName);

	for (int i=0; i<lSize; i++) {
		listGet(list, i, m);
		if (strcasecmp(countryName, m->country) == 0) {
			listAdd(temp, 0, *m);
		}
	}

	listSize(temp, &tempSize);
	totalProducedMovies = tempSize;

	if (tempSize == 0) {
		printf("\nO país que solicitou não produziu nenhum filme.\n");
	} else if (tempSize > 0) {

		for (int i=0; i<tempSize; i++) {
			listGet(temp, i, m);
			mapGet(map, createNewKey(m->id), mRat);
			score += mRat->score;
		}
		score /= totalProducedMovies;
		score = floor(score * 10) /10;

		printf("\nCOUNTRY: %s\n", countryName);
		printf("TOTAL PRODUCED MOVIES: %d\n", totalProducedMovies);
		printf("AVERAGE SCORE: %g\n", score);
	}

}

void rating(PtList list, PtMap map) {
	int lSize, tempListSize, tLSize = 0;
	double minScore, maxScore, mScore, mJScore, mMaxScore = 0.0;
	PtMovie m = createEmptyMovie();
	PtMovie mI = createEmptyMovie();
	PtMovie mMax = createEmptyMovie();
	PtMovie mJ = createEmptyMovie();
	PtMovie mTemp = createEmptyMovie();
	PtMovie trash = createEmptyMovie();
	PtRating r = createEmptyRating();
	PtRating ratI = createEmptyRating();
	PtRating ratMax = createEmptyRating();
	PtRating ratJ = createEmptyRating();
	PtList listTemp = listCreate(1);

	do {
		printf("\nIntroduza o limite mínimo de pontuação: ");
		scanf("%lf", &minScore);
		if (minScore < 0.0) {
			printf("\nPor favor introduza um número maior ou igual a 0.0\n");
		} else if (minScore >= 10.0) {
			printf("\nPor favor introduza um número menor que 10.0\n");
		}
	} while ((minScore < 0.0) || (minScore >= 10.0));
	// printf("min: %g", minScore); // DEBUG
	do {
		printf("Introduza o limite máximo de pontuação: ");
		scanf("%lf", &maxScore);
		if (maxScore <= 0.0) {
			printf("\nPor favor introduza um número maior que 0.0\n");
		} else if (maxScore > 10.0) {
			printf("\nPor favor introduza um número menor ou igual a 10.0\n");
		}
	} while ((maxScore <= 0.0) || (maxScore > 10));
	// printf("max: %g", maxScore); // DEBUG

	listSize(list, &lSize);

	for (int i=0; i<lSize; i++) {
		listGet(list, i, m);
		mapGet(map, createNewKey(m->id), r);
		mScore = r->score;
		if ((mScore >= minScore) && (mScore <= maxScore)) {
			listAdd(listTemp, 0, *m);
		}
	}

	// Sort movies by score (and, in last case, alphabetically)
	// BubbleSort
	listSize(listTemp, &tempListSize);
	tLSize = tempListSize;
	if (tempListSize > 25) {
		tLSize = 25;
	}
	
	printf("\nScore %g-%g:\n", minScore, maxScore);
	for (int i=0; i<tLSize; i++) {
		int maxIndex = i;
		for (int j=i; j<tempListSize; j++) {
			// Procurar filme com maior pontuação
			listGet(listTemp, i, mI);
			listGet(listTemp, maxIndex, mMax);
			listGet(listTemp, j, mJ);
			mapGet(map, createNewKey(mI->id), ratI);
			mapGet(map, createNewKey(mMax->id), ratMax);
			mapGet(map, createNewKey(mJ->id), ratJ);
			mJScore = ratJ->score;
			mMaxScore = ratMax->score;
			if ((mJScore == mMaxScore) && (strcasecmp(mJ->title, mMax->title) < 0)) { // Ordenar alfabeticamente no caso de terem a mesma pontuação
				maxIndex = j;
			} else if (mJScore > mMaxScore) {
				maxIndex = j;
			}
		}
		// Swap
		listSet(listTemp, i, *mMax, mTemp);
		listSet(listTemp, maxIndex, *mTemp, trash);
		printPtMovie(mMax); // DEBUG
		// printPtRating(ratMax); // DEBUG
	}

}

void year(PtList list, PtMap map) {
	int year = 0;

	printf("Introduza o ano sobre o qual pretende obter informação: ");
	scanf("%d", &year);

	PtList action = listCreate(5);
	PtList animation = listCreate(5);
	PtList comedy = listCreate(5);
	PtList drama = listCreate(5);
	PtList horror = listCreate(5);
	PtList musical = listCreate(5);
	PtList romance = listCreate(5);
	PtList thriller = listCreate(5);

	int lSize;
	listSize(list, &lSize);

	for (int i=0; i<lSize; i++) {
		Movie m;
		listGet(list, i, &m);
		if ((strcasecmp(m.genre, "ACTION") == 0) && (m.year == year)) {
			listAdd(action, 0, m);
		} else if ((strcasecmp(m.genre, "ANIMATION") == 0) && (m.year == year)) {
			listAdd(animation, 0, m);
		} else if ((strcasecmp(m.genre, "COMEDY") == 0) && (m.year == year)) {
			listAdd(comedy, 0, m);
		} else if ((strcasecmp(m.genre, "DRAMA") == 0) && (m.year == year)) {
			listAdd(drama, 0, m);
		} else if ((strcasecmp(m.genre, "HORROR") == 0) && (m.year == year)) {
			listAdd(horror, 0, m);
		} else if ((strcasecmp(m.genre, "MUSICAL") == 0) && (m.year == year)) {
			listAdd(musical, 0, m);
		} else if ((strcasecmp(m.genre, "ROMANCE") == 0) && (m.year == year)) {
			listAdd(romance, 0, m);
		} else if ((strcasecmp(m.genre, "THRILLER") == 0) && (m.year == year)) {
			listAdd(thriller, 0, m);
		}
	}

	char* categoryListsNames[] = {"ACTION", "ANIMATION", "COMEDY", "DRAMA", "HORROR", "MUSICAL", "ROMANCE", "THRILLER"};
	PtList categoryLists[] = {action, animation, comedy, drama, horror, musical, romance, thriller};
	int categoryListsSize = 8;

	double score = 0.0;
	int totalProducedMovies = 0;

	printf("\n%d\n", year);

	for (int i=0; i<categoryListsSize; i++) {
		score = 0.0;
		totalProducedMovies = 0;
		listSize(categoryLists[i], &totalProducedMovies);

		for (int j=0; j<totalProducedMovies; j++) {
			PtMovie m = createEmptyMovie();
			PtRating r = createEmptyRating();
			listGet(categoryLists[i], j, m);
			mapGet(map, createNewKey(m->id), r);
			score += r->score;
		}
		score /= totalProducedMovies;
		score = floor(score * 10) / 10;
		// score = ceil(score * 10) / 10;
		
		printf("\t%s: \n", categoryListsNames[i]);
		printf("\t\tAverage Score: %g\n", score);
		printf("\t\tTotal Produced Movies: %d\n", totalProducedMovies);
	}

	listDestroy(&action);
	listDestroy(&animation);
	listDestroy(&comedy);
	listDestroy(&drama);
	listDestroy(&horror);
	listDestroy(&musical);
	listDestroy(&romance);
	listDestroy(&thriller);
}

void printMatrix(int m[5][8]) {
	int year = 2014;
	printf("\n");
	printf("          | DRAMA | HORROR | COMEDY | ANIMATION | THRILLER | ACTION | ROMANCE | MUSICAL \n");
	for (int i=0; i<5; i++) {
		printf("%d      | %- 5d | %- 6d | %- 6d | %- 9d | %- 8d | %- 6d | %- 7d | %- 7d \n", year++, m[i][0], m[i][1], m[i][2], m[i][3], m[i][4], m[i][5], m[i][6], m[i][7]);
	}
	printf("\n");
}

int getMatrixCellValue(PtList list, int year, char *genre) {
	int counter = 0;
	int lSize;
	Movie m;

	listSize(list, &lSize);

	for (int i=0; i<lSize; i++) {
		listGet(list, i, &m);
		if ((m.year == year) && (strcasecmp(m.genre, genre) == 0)) {
			counter++;
			// printMovie(m); // DEBUG
		} else {
			continue;
		}
	}
	return counter;
}

void matrix(PtList list) {
	int matrix[5][8];
	char* genres[1][8] = {"DRAMA", "HORROR", "COMEDY", "ANIMATION", "THRILLER", "ROMANCE", "ACTION", "MUSICAL"};

	// Populate Matrix
	for (int year=2014; year<2019; year++) {
		for (int genre=0; genre<8; genre++) {
			matrix[year-2014][genre] = getMatrixCellValue(list, year, genres[0][genre]);
		}
	}

	// printMatrix
	printMatrix(matrix);

	// int counter = 0;
	// for (int i=0; i<5; i++) {
	// 	for (int j=0; j<8; j++) {
	// 		counter += matrix[i][j];
	// 	}
	// }
	// printf("Contagem matrix: %d \n", counter);

}

void sameDir(PtList list) { // Funciona normalmente para vários diretores à exceção de Scorsese ???? Se a ordenação for ascendente funciona
	char movieId[15];
	Movie movieIdMovie;
	Movie directorMovie;
	PtList directorMovies = listCreate(1);
	int directorMoviesSize;
	int lSize;
	int movieIdRank;
	
	printf("Por favor indique o movieId: ");
	fgets(movieId, 15, stdin);
	movieId[strlen(movieId) - 1] = '\0'; // Retirar caractere '\n'

	listSize(list, &lSize);

	for (int i=0; i<lSize; i++) {
		listGet(list, i, &movieIdMovie);
		if (strcasecmp(movieIdMovie.id, movieId) == 0) {
			movieIdRank = i;
			printf("\nFOUND\n"); // DEBUG
			break;
		}
	}

	for (int i=0; i<lSize; i++) {
		listGet(list, i, &directorMovie);
		if ((strcmp(movieIdMovie.director, directorMovie.director) == 0) && (i != movieIdRank)) { // Não incluír movie fornecido por user
			listAdd(directorMovies, 0, directorMovie);
		}
	}

	printf("Following Movie: ");
	printMovie(movieIdMovie);
	

	if (listIsEmpty(directorMovies)) {
		printf("\n\nNo other films by the same director.\n");
	} else {
		listSize(directorMovies, &directorMoviesSize);

		// Sort directorMovies by year descending
		// Selection Sort
		Movie temp;
		Movie mMax;
		Movie mJ;
		Movie mI;

		Movie trash;

		for (int i=0; i<directorMoviesSize; i++) {
			int maxYearRank = i;
			for (int j=i; j<directorMoviesSize; j++) {
				// Procurar qual o maior elemento
				listGet(directorMovies, i, &mI);
				listGet(directorMovies, maxYearRank, &mMax);
				listGet(directorMovies, j, &mJ);
				if (mMax.year < mJ.year) { // Ordenação Decrescente
					maxYearRank = j;
				}
			}
			// Swap
			listSet(directorMovies, i, mMax, &temp);
			listSet(directorMovies, maxYearRank, temp, &trash);
		}

		printf("\nOther movies directed by %s: \n", movieIdMovie.director);
		for (int i=0; i<directorMoviesSize; i++) {
			listGet(directorMovies, i, &directorMovie);
			printf("- ");
			printMovie(directorMovie);
		}
		// listPrint(directorMovies);
	}

}

void top5(PtList list, PtMap map) {
	PtList action = listCreate(5);
	PtList animation = listCreate(5);
	PtList comedy = listCreate(5);
	PtList drama = listCreate(5);
	PtList horror = listCreate(5);
	PtList musical = listCreate(5);
	PtList romance = listCreate(5);
	PtList thriller = listCreate(5);

	PtList noCategory = listCreate(5); // DEBUG

	// listPrint(list); // DEBUG

	int lSize;
	listSize(list, &lSize);
	// printf("\nlistSize: %d\n", lSize); // DEBUG

	// int counter = 0; // DEBUG

	for (int i=0; i<lSize; i++) {
		Movie m;
		listGet(list, i, &m);
		// printf("Rank %d: ", counter++); // DEBUG
		// printMovie(m); // DEBUG
		if (strcasecmp(m.genre, "ACTION") == 0) {
			listAdd(action, 0, m);
		} else if (strcasecmp(m.genre, "ANIMATION") == 0) {
			listAdd(animation, 0, m);
		} else if (strcasecmp(m.genre, "COMEDY") == 0) {
			listAdd(comedy, 0, m);
		} else if (strcasecmp(m.genre, "DRAMA") == 0) {
			listAdd(drama, 0, m);
		} else if (strcasecmp(m.genre, "HORROR") == 0) {
			listAdd(horror, 0, m);
		} else if (strcasecmp(m.genre, "MUSICAL") == 0) {
			listAdd(musical, 0, m);
		} else if (strcasecmp(m.genre, "ROMANCE") == 0) {
			listAdd(romance, 0, m);
		} else if (strcasecmp(m.genre, "THRILLER") == 0) {
			listAdd(thriller, 0, m);
		} else {
			listAdd(noCategory, 0, m);
		}
	}

	int actionListSize; // DEBUG
	int animationListSize; // DEBUG
	int comedyListSize; // DEBUG
	int dramaListSize; // DEBUG
	int horrorListSize; // DEBUG
	int musicalListSize; // DEBUG
	int romanceListSize; // DEBUG
	int thrillerListSize; // DEBUG
	int noCategoryListSize; // DEBUG

	listSize(action, &actionListSize); // DEBUG
	listSize(animation, &animationListSize); // DEBUG
	listSize(comedy, &comedyListSize); // DEBUG
	listSize(drama, &dramaListSize); // DEBUG
	listSize(horror, &horrorListSize); // DEBUG
	listSize(musical, &musicalListSize); // DEBUG
	listSize(romance, &romanceListSize); // DEBUG
	listSize(thriller, &thrillerListSize); // DEBUG
	listSize(noCategory, &noCategoryListSize); // DEBUG

	printf("\nAction List Size: %d\n", actionListSize); // DEBUG
	printf("Animation List Size: %d\n", animationListSize); // DEBUG
	printf("Comedy List Size: %d\n", comedyListSize); // DEBUG
	printf("Drama List Size: %d\n", dramaListSize); // DEBUG
	printf("Horror List Size: %d\n", horrorListSize); // DEBUG
	printf("Musical List Size: %d\n", musicalListSize); // DEBUG
	printf("Romance List Size: %d\n", romanceListSize); // DEBUG
	printf("Thriller List Size: %d\n", thrillerListSize); // DEBUG
	printf("NoCategory List Size: %d\n\n", noCategoryListSize); // DEBUG

	// listPrint(list); // DEBUG
	// mapPrint(map); // DEBUG

	char* categoryListsNames[] = {"ACTION", "ANIMATION", "COMEDY", "DRAMA", "HORROR", "MUSICAL", "ROMANCE", "THRILLER"};
	PtList categoryLists[] = {action, animation, comedy, drama, horror, musical, romance, thriller};
	int categoryListsSize = 8;

	for (int i=0; i<categoryListsSize; i++) {
		printf("\n%s: \n", categoryListsNames[i]);
		best5Selector(map, &categoryLists[i]);
		printTop5List(categoryLists[i]);
	}

	listDestroy(&action);
	listDestroy(&animation);
	listDestroy(&comedy);
	listDestroy(&drama);
	listDestroy(&horror);
	listDestroy(&musical);
	listDestroy(&romance);
	listDestroy(&thriller);
	listDestroy(&noCategory);
}

void printTop5List(PtList list) {
	PtMovie m = createEmptyMovie();
	for (int i=0; i<5; i++) {
		listGet(list, i, m);
		printf("%d - ", i+1);
		printPtMovie(m);
	}
}

void best5Selector(PtMap map, PtList *categoryList) {
	int categoryListSize;
	listSize(*categoryList, &categoryListSize);

	PtList temp = listCreate(5);

	PtMovie m = createEmptyMovie();
	PtMovie bestMovie;
	int bestMovieRank;

	PtRating mRating = createEmptyRating();
	double mScore = 0.0;
	PtRating bestRating;
	double bestScore;

	for (int i=0; i<5; i++) {
		bestMovie = createEmptyMovie();
		bestRating = createEmptyRating();
		bestScore = 0.0;

		for (int j=0; j<categoryListSize; j++) {
			listGet(*categoryList, j, m);
			mapGet(map, createNewKey(m->id), mRating);
			mScore = mRating->score;
			
			if (mScore >= bestScore) {
				bestScore = mScore;
				bestRating = mRating;
				bestMovie = m;
				bestMovieRank = j;
				// printPtMovie(bestMovie); // DEBUG
				// printPtRating(bestRating); // DEBUG
			}
		}
		
		listRemove(*categoryList, bestMovieRank, bestMovie);
		listAdd(temp, i, *bestMovie);
		// printPtMovie(bestMovie); // DEBUG
		// printPtRating(bestRating); // DEBUG
	}
	// listPrint(temp); // DEBUG
	*categoryList = temp;
	listDestroy(&temp);

	// Sort movies with same score by year descending
	// SelectionSort
	Movie mtemp;
	Movie mMax;
	Movie mJ;
	Movie mI;
	PtRating mMaxRat = createEmptyRating();
	PtRating mJRat = createEmptyRating();
	double mMaxRatScore = 0.0;
	double mJRatScore = 0.0;

	Movie trash;

	for (int i=0; i<5; i++) {
		int maxYearRank = i;
		for (int j=i; j<5; j++) {
			// Procurar qual o maior elemento
			listGet(*categoryList, i, &mI);
			listGet(*categoryList, maxYearRank, &mMax);
			listGet(*categoryList, j, &mJ);
			mapGet(map, createNewKey(mMax.id), mMaxRat);
			mapGet(map, createNewKey(mJ.id), mJRat);
			mMaxRatScore = mMaxRat->score;
			mJRatScore = mJRat->score;
			if ((mMax.year < mJ.year) && (mMaxRatScore == mJRatScore)) { // Ordenação Decrescente
				maxYearRank = j;
			}
		}
		// Swap
		listSet(*categoryList, i, mMax, &mtemp);
		listSet(*categoryList, maxYearRank, mtemp, &trash);
	}
}

void loadr(PtMap *map) {
	char ratingsFileName[20] = "ratings.csv"; // DEBUG

	// char ratingsFileName[20];
	// printf("Por favor indique o nome do ficheiro de pontuações: ");
	// fgets(ratingsFileName, 20, stdin);
	// ratingsFileName[strlen(ratingsFileName) - 1] = '\0'; // Retirar caractere '\n'
	// strcat(ratingsFileName, ".csv"); // Acrescentar extensão .csv a ratingsFileName

	// PtMap tempMap = NULL;
	// tempMap = mapCreate(10);
	*map = mapCreate(10);

	FILE *file = fopen(ratingsFileName, "r");
	if (file == NULL) {
		printf("\nFile not found\n\n");
		return;
	}
	char line[120];
	fgets(line, sizeof(line), file); // Descartar linha com nome dos campos
	while (fgets(line, sizeof(line), file)) {
		char **tokens;
		char movieId[15];
		char *movieIdCpy;
		int maleVotes;
		int femaleVotes;
		int votes[10];
		double score;

		// printf("%s", line); // DEBUG

		tokens = split(line, 13, ";");

		strcpy(movieId, tokens[0]);
		maleVotes = atoi(tokens[1]);
		femaleVotes = atoi(tokens[2]);

		removeChar(tokens[12], '\n'); // Remover caractere '\n' do elemento final da line
		for (int i=0; i<10; i++) {
			votes[i] = atoi(tokens[i+3]);
		}
		
		score = calculateScore(votes);

		
		PtRating r = createRating(movieId, maleVotes, femaleVotes, votes, score);
		// printf("%s\n", movieId); // DEBUG
		// mapPut(tempMap, createNewKey(movieId), *r);
		mapPut(*map, createNewKey(movieId), *r);

		// printPtRating(r); // DEBUG

		// printf("%d\n", ++ratingCounter); // DEBUG
		// usleep(50000); // DEBUG
	}
	// mapPrint(tempMap); // DEBUG
	// int size; // DEBUG
	// mapSize(tempMap, &size); // DEBUG
	
	// *map = tempMap;
	// mapDestroy(&tempMap);

	// mapPrint(*map); // DEBUG
	int size;
	mapSize(*map, &size);
	printf("\nForam importadas %d pontuações em memória com sucesso!!\n", size);
}

MapKey createNewKey(char *movieId) {
	MapKey mK;
	strcpy(mK.key, movieId);
	return mK;
}

void loadm(PtList *list) {
	char moviesFileName[20] = "movies.csv"; // DEBUG

	// char moviesFileName[20];
	// printf("\nPor favor indique o nome do ficheiro de filmes: ");
	// fgets(moviesFileName, 20, stdin);
	// moviesFileName[strlen(moviesFileName) - 1] = '\0'; // Retirar caractere '\n'
	// strcat(moviesFileName, ".csv"); // Acrescentar extensão .csv a moviesFileName

	// PtList tempList = NULL;
	// tempList = listCreate(10);
	*list = listCreate(10);


	FILE *file = fopen(moviesFileName, "r");
	if (file == NULL) {
		printf("\nFile not found\n\n");
		return;
	}
	char line[315];
	int movieCounter = 0;
	fgets(line, sizeof(line), file); // Descartar linha com nome dos campos
	while (fgets(line, sizeof(line), file)) {
		char **tokens;
		char id[11];
		char title[100];
		int year;
		char genre[100];
		int duration;
		char country[100];
		char director[50];

		tokens = split(line, 7, ";");

		strcpy(id, tokens[0]);
		// printf("\n%s\n", id); // DEBUG

		strcpy(title, tokens[1]);
		// printf("%s\n", title); // DEBUG
		
		year = atoi(tokens[2]);
		// printf("%d\n", year); // DEBUG

		strcpy(genre, firstElementSelector(tokens[3]));
		// printf("%s\n", genre); // DEBUG

		duration = atoi(tokens[4]);
		// printf("%d\n", duration); // DEBUG

		strcpy(country, firstElementSelector(tokens[5]));
		// printf("%s\n", country); // DEBUG

		strcpy(director, firstElementSelector(tokens[6]));
		removeChar(director, '\n'); // Remover caractere '\n' do elemento final da line
		// printf("%s\n", director); // DEBUG

		PtMovie m = createMovie(id, title, year, genre, duration, country, director);
		listAdd(*list, movieCounter++, *m);

		// printMovie(*m); // DEBUG
	}
	// *list = tempList;
	// listDestroy(&tempList);

	// listPrint(*list); // DEBUG
	int size;
	listSize(*list, &size); // DEBUG
	printf("\nForam importados %d filmes em memória com sucesso!!\n", size); // DEBUG
}

void removeChar(char *str, char c) {
	int strSize = strlen(str);
	for (int i=0; i<strSize; i++) {
		if (str[i] == c) {
			str[i] = str[i+1];
		}
	}
}

char** split(char *string, int nFields, const char *delim) {
    char **tokens = (char**) malloc(sizeof(char*) * nFields);
    int index = 0;
    int len = strlen(string);
    
    tokens[index++] = &string[0];
    for(int i=0; i < len; i++) {
        if( string[i] == delim[0] ) {
            string[i] = '\0';
            if( i < len - 1 ) {
                tokens[index++] = &string[i] + 1;
            }           
        }
    }
    return tokens;
}

char* firstElementSelector(char *sequence) {
	return strtok(sequence, ",");
}

void clear(PtList list, PtMap map){
	int sizeList = 0;
    listSize(list, &sizeList);

	if(sizeList > 0){
		printf("Number of records deleted from Movies - %d\n",sizeList);
		listClear(list);
	}else{
		printf("There were no records from Movies to be deleted\n");
	}

	int sizeMap = 0;
    mapSize(map, &sizeMap);
	if(sizeList>0){
		printf("Number of records deleted from Ratings - %d\n",sizeMap);
		mapClear(map);
	}else{
		printf("There were no records from Ratings to be deleted\n");
	}
}
