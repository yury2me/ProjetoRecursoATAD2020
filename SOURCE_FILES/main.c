/* PROJETO RECURSO  ATAD 2019-20
* Identificação do Aluno:
*
*      Numero: 180221123 | Nome: Iúri Tomé
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "commands.h"
#include "list.h"
#include "map.h"

typedef char String[255];

/* definicao de prototipos de funcoes, definidas depois do main() */
/**
 * @brief Checks if the strings are the same
 * 
 * @param str1 string to compare
 * @param str2 string to compare
 * @return int 0 if equal
 */
int equalsStringIgnoreCase(char str1[], char str2[]);

/**
 * @brief This function prints the commands menu.
 * 
 */
void printCommandsMenu();

/*
* Descrição do Programa
*/
int main(int argc, char** argv) {

	/* declaracao de variaveis */
	PtList list = NULL;
	PtMap map = NULL;

	/* interpretador de comandos */
	char command[20]; // DEBUG
	
	// char command[20];
	int quit = 0;

	setlocale(LC_ALL, "PT");
	while (!quit) {
		
		printCommandsMenu();
		fgets(command, sizeof(command), stdin);
		/* descartar 'newline'. Utilizar esta técnica sempre que for lida uma
		* string para ser utilizada, e.g., nome de ficheiro, chave, etc.. */
		command[strlen(command) - 1] = '\0';
        
		if (equalsStringIgnoreCase(command, "QUIT")) {
			quitProg(&list, &map);
			quit = 1; /* vai provocar a saída do interpretador */				
		}
		else if (equalsStringIgnoreCase(command, "LOADM")) {
			loadm(&list);
		}
		else if (equalsStringIgnoreCase(command, "LOADR")) {
			loadr(&map);
		}
		else if (equalsStringIgnoreCase(command, "CLEAR")) {
			clear(list, map);
		}
		else if (equalsStringIgnoreCase(command, "TOP5")) {
			top5(list, map);
		}
		else if (equalsStringIgnoreCase(command, "RATING")) {
			rating(list, map);
		}
		else if (equalsStringIgnoreCase(command, "SAMEDIR")) {
			sameDir(list);
		}
		else if (equalsStringIgnoreCase(command, "VOTERS")) {
			printf("Comando VOTERS nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "COUNTRY")) {
			country(list, map);
		}
		else if (equalsStringIgnoreCase(command, "YEAR")) {
			year(list, map);
		}
		else if (equalsStringIgnoreCase(command, "MATRIX")) {
			matrix(list);
		}	
		else if (equalsStringIgnoreCase(command, "PREDICTION")) {
			printf("Comando PREDICTION nao implementado.\n");
		}
		else {
			printf("%s : Comando não encontrado.\n", command);
		}
	}

	/* libertar memória e apresentar mensagem de saída. */

	return (EXIT_SUCCESS);
}

int equalsStringIgnoreCase(char *str1, char *str2) {
	return (strcasecmp(str1, str2) == 0);
}

void printCommandsMenu() {
	printf("\n=======================================================");
	printf("\n                     PROJECT: IMDB                     ");
	printf("\n=======================================================");
	printf("\nBase Commands\t- LOADM\n\t\t- LOADR\n\t\t- CLEAR\n");
	printf("\nCommands\t- TOP5\n\t\t- RATING\n\t\t- SAMEDIR\n\t\t- VOTERS\n\t\t- COUNTRY\n\t\t- YEAR\n\t\t- MATRIX\n\t\t- PREDICTION\n");
	printf("\nExit Command\t- QUIT\n\n");
	printf("COMMAND> ");
}
