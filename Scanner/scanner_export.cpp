#include "Stdafx.h"

#include <string>
#include "scanner.hpp"
#include "scanner_export.hpp"

extern "C"{
	Scanner * createScanner(const char * str){
		scanner::Scanner * scanner = new scanner::Scanner(std::string(str));

		return scanner;
	}

	void destroyScanner(Scanner * scanner){
		delete scanner;
	}

	int * nextInt(Scanner * scanner){
		int * ref = (int *)malloc(sizeof(int));

		if(scanner->tryGetNextInt(ref)){
			return ref;
		}

		free(ref);
		return NULL;
	}

	unsigned int * nextUnsignedInt(Scanner * scanner){
		unsigned int * ref = (unsigned int *)malloc(sizeof(unsigned int));

		if(scanner->tryGetNextUnsignedInt(ref)){
			return ref;
		}

		free(ref);
		return NULL;
	}

	double * nextDouble(Scanner * scanner){
		double * ref = (double *)malloc(sizeof(double));

		if(scanner->tryGetNextDouble(ref)){
			return ref;
		}

		free(ref);
		return NULL;
	}

	float * nextFloat(Scanner * scanner){
		float * ref = (float *)malloc(sizeof(float));

		if(scanner->tryGetNextFloat(ref)){
			return ref;
		}

		free(ref);
		return NULL;
	}

	int searchNextStringToken(Scanner * scanner, const char * str){
		return scanner->searchNextStringToken(std::string(str)) ? 1 : 0;
	}

	int hasNextStringToken(Scanner * scanner, const char * str){
		return scanner->hasNextStringToken(std::string(str)) ? 1 : 0;
	}

	int hasNextInt(Scanner * scanner){
		return scanner->hasNextInt() ? 1 : 0;
	}

	int hasNextUnsignedInt(Scanner * scanner){
		return scanner->hasNextUnsignedInt() ? 1 : 0;
	}

	int hasNextDouble(Scanner * scanner){
		return scanner->hasNextDouble() ? 1 : 0;
	}

	int hasNextFloat(Scanner * scanner){
		return scanner->hasNextFloat() ? 1 : 0;
	}

	void rewindScanner(Scanner * scanner){
		scanner->rewind();
	}

	int tryGetNextInt(Scanner * scanner, int * ref){
		return scanner->tryGetNextInt(ref) ? 1 : 0;
	}

	int tryGetNextUnsignedInt(Scanner * scanner, unsigned int * ref){
		return scanner->tryGetNextUnsignedInt(ref) ? 1 : 0;
	}

	int tryGetNextDouble(Scanner * scanner, double * ref){
		return scanner->tryGetNextDouble(ref) ? 1 : 0;
	}

	int tryGetNextFloat(Scanner * scanner, float * ref){
		return scanner->tryGetNextFloat(ref) ? 1 : 0;
	}
}