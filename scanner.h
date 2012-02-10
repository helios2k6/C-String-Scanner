/*
 * scanner.h
 *
 *  Created on: Feb 7, 2012
 *      Author: Andrew
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include "list.h"

typedef struct{
	list_t tokens;
	unsigned int index;
}Scanner;

/* Constructors */
Scanner * createScanner(const char * string);
Scanner * createScannerWithDeliminators(const char * string, const char * deliminators);

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
void rewind(Scanner * scanner);

#endif /* SCANNER_H_ */
