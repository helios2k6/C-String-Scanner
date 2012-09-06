#include "Stdafx.h"

#include <string>
#include "scanner_export.h"

extern "C"{
	scanner::Scanner * createScanner(const char * str){
		scanner::Scanner * scanner = new scanner::Scanner(std::string(str));

		return scanner;
	}

	void destroyScanner(scanner::Scanner * scanner){
		delete scanner;
	}

	int * nextInt(scanner::Scanner * scanner){
		int * ref = (int *)malloc(sizeof(int));

		if(scanner->tryGetNextInt(ref)){
			return ref;
		}

		free(ref);
		return NULL;
	}

	unsigned int * nextUnsignedInt(scanner::Scanner * scanner){
		unsigned int * ref = (unsigned int *)malloc(sizeof(unsigned int));

		if(scanner->tryGetNextUnsignedInt(ref)){
			return ref;
		}

		free(ref);
		return NULL;
	}

	double * nextDouble(scanner::Scanner * scanner){
		double * ref = (double *)malloc(sizeof(double));

		if(scanner->tryGetNextDouble(ref)){
			return ref;
		}

		free(ref);
		return NULL;
	}

	float * nextFloat(scanner::Scanner * scanner){
		float * ref = (float *)malloc(sizeof(float));

		if(scanner->tryGetNextFloat(ref)){
			return ref;
		}

		free(ref);
		return NULL;
	}

	int searchNextStringToken(scanner::Scanner * scanner, const char * str){
		return scanner->searchNextStringToken(std::string(str)) ? 1 : 0;
	}

	int hasNextInt(scanner::Scanner * scanner){
		return scanner->hasNextInt() ? 1 : 0;
	}

	int hasNextUnsignedInt(scanner::Scanner * scanner){
		return scanner->hasNextUnsignedInt() ? 1 : 0;
	}

	int hasNextDouble(scanner::Scanner * scanner){
		return scanner->hasNextDouble() ? 1 : 0;
	}

	int hasNextFloat(scanner::Scanner * scanner){
		return scanner->hasNextFloat() ? 1 : 0;
	}

	void rewindScanner(scanner::Scanner * scanner){
		scanner->rewind();
	}

	int tryGetNextInt(scanner::Scanner * scanner, int * ref){
		return scanner->tryGetNextInt(ref) ? 1 : 0;
	}

	int tryGetNextUnsignedInt(scanner::Scanner * scanner, unsigned int * ref){
		return scanner->tryGetNextUnsignedInt(ref) ? 1 : 0;
	}

	int tryGetNextDouble(scanner::Scanner * scanner, double * ref){
		return scanner->tryGetNextDouble(ref) ? 1 : 0;
	}

	int tryGetNextFloat(scanner::Scanner * scanner, float * ref){
		return scanner->tryGetNextFloat(ref) ? 1 : 0;
	}
}