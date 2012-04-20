/*
 * scanner.h
 *
 *  Created on: Feb 7, 2012
 *      Author: Andrew
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
	const char * string;
	unsigned int length;
}Token;

typedef struct{
	Token ** tokens;
	unsigned int index;
	unsigned int numTokens;
}Scanner;

/* Constructors */
Scanner * createScanner(const char * string);

/* Destructor */
void destroyScanner(Scanner * scanner);

/* Next Functions */
int * nextInt(Scanner * scanner);
unsigned int * nextUnsignedInt(Scanner * scanner);
double * nextDouble(Scanner * scanner);
float * nextFloat(Scanner * scanner);

/* Searching */
int searchNextStringToken(Scanner * scanner, const char * string);

/* Check Functions */
int hasNextInt(Scanner * scanner);
int hasNextUnsignedInt(Scanner * scanner);
int hasNextDouble(Scanner * scanner);
int hasNextFloat(Scanner * scanner);
int hasNextStringToken(Scanner * scanner, const char * string);

/* Utility Functions */
void rewindScanner(Scanner * scanner);

#ifdef __cplusplus
}
#endif

#endif /* SCANNER_H_ */
