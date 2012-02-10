/*
 * scanner.h
 *
 *  Created on: Feb 7, 2012
 *      Author: Andrew
 */

#ifndef SCANNER_H_
#define SCANNER_H_

typedef struct{
	char * string;
	unsigned int length;
	struct Token * nextToken;
}Token;

typedef struct{
	char * string;
	Token * tokens;
	unsigned int index;
}Scanner;

/* Constructors */
Scanner * createScanner(const char * string);

/* Destructor */
void destroyScanner(Scanner * scanner);

/* External Functions */

/* Next Functions */
int * nextInt(Scanner * scanner);
unsigned int * nextUnsignedInt(Scanner * scanner);
double * nextDouble(Scanner * scanner);
float * nextFloat(Scanner * scanner);

/* Check Functions */
int hasNextInt(Scanner * scanner);
int hasNextUnsignedInt(Scanner * scanner);
int hasNextDouble(Scanner * scanner);
int hasNextFloat(Scanner * scanner);

/* Utility Functions */
void setDeliminiators(Scanner * scanner, const char * deliminators);
void rewind(Scanner * scanner);

#endif /* SCANNER_H_ */
