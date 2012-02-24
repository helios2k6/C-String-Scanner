/*
 * testDriver.cxx
 *
 *  Created on: Feb 11, 2012
 *      Author: Andrew
 */


#include <iostream>
#include <fstream>
#include <assert.h>
#include <iterator>
#include <string>
#include <cstring>
#include "scanner.h"

#define PRECISION 0.001

#define STANDARD_STRING "1212 2 222 1 H A1 9"
#define STANDARD_DOUBLE_STRING "1.0 kk fd 32 2.2 fl 3l"
#define TEST_FILE_1 "AutoGen_Example.txt"
#define TEST_FILE_2 "Input_Example.txt"

void unitTest1();
void unitTest2();
void unitTest3();
void unitTest4();
void unitTest5();
void unitTest6();

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

void unitTest6(){
	std::ifstream testFile1(TEST_FILE_1);
	std::ifstream testFile2(TEST_FILE_2);

	//Test First File
	while(testFile1.good()){
		std::string mystring;

		std::getline(testFile1, mystring);

		const char * ptrToCharString = mystring.c_str();
		char * copyOfString = (char *)malloc(sizeof(char) * mystring.length() + 1);

		strcpy(copyOfString, ptrToCharString);

		Scanner * scanner = createScanner((const char *)copyOfString);

		destroyScanner(scanner);

		std::cout << mystring << std::endl;
	}

	//Test Second File
	while(testFile2.good()){
		std::string mystring;

		std::getline(testFile2, mystring);

		std::cout << mystring << std::endl;
	}

	testFile1.close();
	testFile2.close();

}

int main(){

	std::cout << "Starting Unit Testing of Scanner" << std::endl;

	std::cout << "Running Unit Test 1" << std::endl;

	unitTest1();

	std::cout << "Running Unit Test 2" << std::endl;

	unitTest2();

	std::cout << "Running Unit Test 3" << std::endl;

	unitTest3();

	std::cout << "Running Unit Test 4" << std::endl;

	unitTest4();

	std::cout << "Running Unit Test 5" << std::endl;

	unitTest5();

	std::cout << "Running Unit Test 6" << std::endl;

	unitTest6();

	std::cout << "All Unit Tests Passed" << std::endl;


	return 0;
}
