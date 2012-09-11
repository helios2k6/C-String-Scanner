#include <string>
#include <iostream>
#include <assert.h>
#include "scanner.hpp"
#include "boost/timer/timer.hpp"

#define NUMER_OF_TESTS 1000

using namespace std;
using namespace scanner;

namespace{
	static string testString1("1 2 3 4");
	static string testString2("-1 -2 -3 -4");
	static string testString3("1.0 2.0 3.0 4.0");
}

void unitTest1();
void unitTest2();

void timingTest();

int main(){
	cout << "Starting Unit Tests" << endl;
	unitTest1();
	unitTest2();
	cout << "All Unit Tests Passed" << endl;
	cout << "Running Timing Tests" <<endl;
	timingTest();
	cout << "End of Timing Tests" << endl;

}

void unitTest1(){
	Scanner scanner(testString1);
	int counter = 0;

	while(scanner.hasNextInt()){
		int * t = (int *)malloc(sizeof(int));
		scanner.tryGetNextInt(t);
		counter++;

		assert(*t == counter);

		free(t);
	}

	assert(counter == 4);
}

void unitTest2(){
	string temp("hello world");
	Scanner scanner(temp);

	int * t = (int *)malloc(sizeof(int));
	unsigned int * r = (unsigned int *)malloc(sizeof(unsigned int));
	float * e = (float *)malloc(sizeof(float));
	double * w = (double *)malloc(sizeof(double));

	assert(!scanner.hasNextInt());
	assert(!scanner.hasNextUnsignedInt());
	assert(!scanner.hasNextFloat());
	assert(!scanner.hasNextDouble());

	assert(!scanner.tryGetNextInt(t));
	assert(!scanner.tryGetNextUnsignedInt(r)); 
	assert(!scanner.tryGetNextFloat(e));
	assert(!scanner.tryGetNextDouble(w));

	free(t);
	free(r);
	free(e);
	free(w);
}

void timingTest(){
	int * t = (int *)malloc(sizeof(int));
	unsigned int * r = (unsigned int *)malloc(sizeof(unsigned int));
	float * e = (float *)malloc(sizeof(float));
	double * w = (double *)malloc(sizeof(double));

	boost::timer::cpu_timer timer;

	string temp("Some work that has to be done 1 2 3 4 5 6 -1 -2 -3 -4 -5 2.0 3.0 -4.0 -5.0");
	Scanner scanner(temp);

	timer.start();
	for(long i = 0; i < NUMER_OF_TESTS; i++)
	{
		scanner.tryGetNextDouble(w);
	}
	timer.stop();


	free(t);
	free(r);
	free(e);
	free(w);

	cout << "Time to run " << NUMER_OF_TESTS << " tests: " << timer.format();
}