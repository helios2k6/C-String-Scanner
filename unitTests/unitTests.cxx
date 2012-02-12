/*
 * testDriver.cxx
 *
 *  Created on: Feb 11, 2012
 *      Author: Andrew
 */


#include <iostream>
#include <assert.h>
#include "scanner.h"

#define PRECISION 0.001

#define STANDARD_STRING "1212 2 222 1 H A1 9"
#define STANDARD_DOUBLE_STRING "1.0 kk fd 32 2.2 fl 3l"

void unitTest1();
void unitTest2();
void unitTest3();
void unitTest4();
void unitTest5();

void unitTest1(){
	Scanner * scanner = createScanner("Hello World!");
	void * result;

	result = nextInt(scanner);
	assert(result == NULL);

	result = nextDouble(scanner);
	assert(result == NULL);

	result = nextUnsignedInt(scanner);
	assert(result == NULL);

	result = nextFloat(scanner);
	assert(result == NULL);

	assert(scanner->index == 0);

	destroyScanner(scanner);
}

void unitTest2(){
	void * result;
	Scanner * scanner = createScanner(STANDARD_STRING);

	for(int i = 0; i < 5; i++){
		result = nextInt(scanner);
		assert(result != NULL);
		free(result);
	}

	result = nextInt(scanner);
	assert(result == NULL);

	assert(scanner->index = scanner->numTokens);

	rewindScanner(scanner);
	assert(scanner->index == 0);

}

void unitTest3(){
	Scanner * scanner = createScanner(STANDARD_STRING);

	int * resulti = nextInt(scanner);
	assert(resulti != NULL);
	assert(*resulti == 1212);
	free(resulti);

	unsigned int * resultu = nextUnsignedInt(scanner);
	assert(resultu != NULL);
	assert(*resultu == 2);
	free(resultu);

	float * resultf = nextFloat(scanner);
	assert(resultf != NULL);
	assert((*resultf - 222) < PRECISION);
	free(resultf);

	double * resultd = nextDouble(scanner);
	assert(resultd != NULL);
	assert((*resultd - 1) < PRECISION);
	free(resultd);

	int * resulti2 = nextInt(scanner);
	assert(resulti2 != NULL);
	assert((*resulti2 == 9));
	free(resulti2);

	destroyScanner(scanner);
}

void unitTest4(){
	Scanner * scanner = createScanner(STANDARD_DOUBLE_STRING);
	void * result = NULL;

	for(int i = 0; i < 3; i++){
		result = nextDouble(scanner);
		assert(result != NULL);
		free(result);
	}

	result = nextDouble(scanner);

	assert(result == NULL);

}

void unitTest5(){
	Scanner * scanner = createScanner(STANDARD_DOUBLE_STRING);
	int * result = NULL;

	result = nextInt(scanner);

	assert(*result == 32);

	free(result);

	result = nextInt(scanner);

	assert(result == NULL);

	destroyScanner(scanner);
}

int main(){
	{
		using namespace std;

		cout << "Starting Unit Testing of Scanner" << endl;

		cout << "Running Unit Test 1" << endl;

		unitTest1();

		cout << "Running Unit Test 2" << endl;

		unitTest2();

		cout << "Running Unit Test 3" << endl;

		unitTest3();

		cout << "Running Unit Test 4" << endl;

		unitTest4();

		cout << "Running Unit Test 5" << endl;

		unitTest5();

		cout << "All Unit Tests Passed" << endl;

	}

	return 0;
}
