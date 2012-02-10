/*
 * scanner.c
 *
 *  Created on: Feb 7, 2012
 *      Author: Andrew
 */

#include <stdlib.h>
#include <string.h>
#include "scanner.h"

/* Internal functions */
Token * tokenizeString(const char * string, const char * deliminators);
void destroyTokens(Token * head);

void destroyTokens(Token * head){
	if(head->nextToken){
		destroyTokens(head->nextToken);
	}
	free(head);
}

Token * tokenizeString(const char * string, const char * deliminators){
	Token * head, * lastTokenCreated;
	unsigned int index, beginningOfLastToken, stringLength;

	stringLength = strlen(string);
	head = NULL;
	beginningOfLastToken = 0;

	for(index = 0; index < stringLength; index++){
		char * stringSearchResult;

		stringSearchResult = strchr(string, string[index]);

		if(stringSearchResult){
			//If not NULL, then we know it's a deliminator
			Token * nextToken = (Token *)malloc(sizeof(Token));
			nextToken->length = index - beginningOfLastToken;
			nextToken->string = stringSearchResult + index;
			nextToken->nextToken = NULL;

			if(!head){
				//Very first token created
				head = nextToken;
				lastTokenCreated = nextToken;
			}else{
				lastTokenCreated->nextToken = nextToken;
				lastTokenCreated = nextToken;
			}

			beginningOfLastToken = index;

		}


	}

	return head;
}

Scanner * createScanner(const char * string){
	Scanner * scanner;

	scanner = (Scanner *)malloc(sizeof(Scanner));

	if(scanner != NULL){

	}

	return scanner;
}

void destroyScanner(Scanner * scanner){
	free(scanner->string);
	free(scanner);
}

int hasNextInt(Scanner * scanner){
	return 0;
}
