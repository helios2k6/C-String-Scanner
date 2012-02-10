/*
 * scanner.c
 *
 *  Created on: Feb 7, 2012
 *      Author: Andrew
 */

#include <stdlib.h>
#include <string.h>
#include "scanner.h"
#include "list.h"

/* Internal functions */
typedef struct{
	char * substring;
	unsigned int length;
}Token;

list_t tokenizeString(const char * string, const char * deliminators);

list_t tokenizeString(const char * string, const char * deliminators){
	list_t tokens;
	const unsigned int lengthOfString = strlen(string);
	unsigned int index, lastBeginningIndex;
	int lookingForBeginningOfNextSubstring = 1;

	Token * currentToken;

	tokens = list_init();

	lastBeginningIndex = -1;

	for(index = 0; index < lengthOfString; index++){
		char currentChar = string[index];
		char * resultOfDeliminatorSearch = strchr(deliminators, currentChar);

		if(lookingForBeginningOfNextSubstring){
			/*
			 * We're looking the beginning of the next substring. When we
			 * find it, create a new token and look for the deliminator
			 */
			if(resultOfDeliminatorSearch != NULL){
				currentToken = (Token *)malloc(sizeof(Token));
				lastBeginningIndex = index;

				currentToken->substring = string+index;

				/* Use zero so that we just store the address */
				list_insert_after(tokens, currentToken, 0);

				lookingForBeginningOfNextSubstring = 0;
			}
		}else{
			/*
			 * We're looking for the deliminator. Once we find it, we can
			 * set the length of the current Token
			 */
			if(resultOfDeliminatorSearch == NULL){
				currentToken->length = index - lastBeginningIndex;
				lookingForBeginningOfNextSubstring = 1;
			}
		}
	}


	return tokens;
}


Scanner * createScanner(const char * string){
	Scanner * scanner;

	scanner = (Scanner *)malloc(sizeof(Scanner));

	char defaultDeliminators[] = " ";

	if(scanner != NULL){
		scanner->index = 0;
		scanner->tokens = tokenizeString(string, &defaultDeliminators);
	}

	return scanner;
}

Scanner * createScannerWithDeliminators(const char * string, const char * deliminators){
	Scanner * scanner;

	scanner = (Scanner *)malloc(sizeof(Scanner));

	if(scanner != NULL){
		scanner->index = 0;
		scanner->tokens = tokenizeString(string, deliminators);
	}

	return scanner;
}

void destroyScanner(Scanner * scanner){
	void * tokenItem;

	tokenItem = list_remove_front(scanner->tokens);

	while(tokenItem){
		free(tokenItem);
		tokenItem = list_remove_front(scanner->tokens);
	}

	list_free(scanner->tokens, LIST_NODEALLOC);

	free(scanner);
}

int * nextInt(Scanner * scanner){
	int * foundToken, savedScannerIndex, anyNumberFound;

	foundToken = NULL;
	savedScannerIndex = scanner->index;
	anyNumberFound = 0;

	//NULL Check
	unsigned int index, numberOfTokens;
	list_t list = scanner->tokens;

	numberOfTokens = list_size(list);

	list_mvfront(list);

	for(index = 0; index < numberOfTokens; index++){
		if(index >= scanner->index){
			Token * currentToken = (Token *)list_curr(list);
			int foundNumber = strtol(currentToken->substring);

			if(foundNumber){
				foundToken = (int *)malloc(sizeof(int));
				*foundToken = foundNumber;
				anyNumberFound = 1;
				break;
			}
		}

		list_mvnext(list);
		scanner->index++;
	}

	/* If we never found a suitable number, then  */
	if(!anyNumberFound){
		scanner->index = savedScannerIndex;
	}

	return foundToken;
}

