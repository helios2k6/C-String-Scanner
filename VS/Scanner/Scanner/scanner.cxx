/*
* scanner.cxx
*
*  Created on: Feb 10, 2012
*      Author: Andrew
*/

#include "Stdafx.h"

#include <string>
#include <vector>
#include "boost/tokenizer.hpp"
#include "boost/lexical_cast.hpp"
#include "scanner.h"

/* External C functions */
extern "C"{
	Scanner * createScanner(const char * string){
		std::string cppString(string);
		std::vector<std::string> tokenizedStrings;

		boost::char_separator<char> customTokenizer(" ;()|\\[]{}!@#$%^&*<>?+=_,\n\t");
		typedef boost::tokenizer<boost::char_separator<char> > Tokenizer;
		Tokenizer tokenizer(cppString, customTokenizer);

		/* Get our string tokens */
		for(Tokenizer::iterator tokenIterator = tokenizer.begin(); tokenIterator != tokenizer.end(); tokenIterator++){
			const std::string currentToken(*tokenIterator);

			tokenizedStrings.push_back(currentToken);
		}

		/* Convert to Token structs */
		unsigned int numberOfTokens = tokenizedStrings.size();
		Token ** tokens = (Token**)calloc(numberOfTokens, sizeof(Token *));

		for(unsigned int index = 0; index < numberOfTokens; index++){
			Token * currentToken = (Token *)malloc(sizeof(Token));
			const std::string& currentString = tokenizedStrings[index];
			unsigned int stringLength = currentString.length();
			char * stringBuffer = (char *)calloc(stringLength + 1, sizeof(char));

			/* Dangerous, but necessary */
			strncpy(stringBuffer, currentString.c_str(), currentString.length());

			currentToken->string = stringBuffer;
			currentToken->length = stringLength;

			tokens[index] = currentToken;
		}

		Scanner * scanner = (Scanner *)malloc(sizeof(Scanner));
		scanner->index = 0;
		scanner->numTokens = numberOfTokens;
		scanner->tokens = tokens;

		return scanner;
	}

	void destroyScanner(Scanner * scanner){
		Token ** tokens;

		tokens = scanner->tokens;
		/* Destroy tokens first */
		for(unsigned int index = 0; index < scanner->numTokens; index++){
			void * currentString = (void *)tokens[index]->string;
			free(currentString);
			free(tokens[index]);
		}

		free(scanner->tokens);

		free(scanner);
	}

	int * nextInt(Scanner * scanner){
		int * result;
		unsigned int savedIndex = scanner->index;

		result = NULL;

		Token ** tokens = scanner->tokens;

		for(unsigned int index = scanner->index; index < scanner->numTokens; index++){
			Token * currentToken = tokens[index];
			scanner->index++;
			try{
				int castResult = boost::lexical_cast<int>(currentToken->string);

				result = (int *)malloc(sizeof(int));
				*result = castResult;
				break;
			}catch(boost::bad_lexical_cast){
				//Do nothing, since we intend to be failing a lot
			}

		}

		if(!result){
			scanner->index = savedIndex;
		}

		return result;
	}

	unsigned int * nextUnsignedInt(Scanner * scanner){
		unsigned int * result;
		unsigned int savedIndex = scanner->index;
		result = NULL;

		Token ** tokens = scanner->tokens;

		for(unsigned int index = scanner->index; index < scanner->numTokens; index++){
			Token * currentToken = tokens[index];
			scanner->index++;
			try{
				unsigned int castResult = boost::lexical_cast<unsigned int>(currentToken->string);

				result = (unsigned int *)malloc(sizeof(unsigned int));
				*result = castResult;

				break;
			}catch(boost::bad_lexical_cast){
				//Do nothing, since we intend to be failing a lot
			}
		}

		if(!result){
			scanner->index = savedIndex;
		}

		return result;
	}
	double * nextDouble(Scanner * scanner){
		double * result;
		unsigned int savedIndex = scanner->index;
		result = NULL;

		Token ** tokens = scanner->tokens;

		for(unsigned int index = scanner->index; index < scanner->numTokens; index++){
			Token * currentToken = tokens[index];
			scanner->index++;
			try{
				double castResult = boost::lexical_cast<double>(currentToken->string);

				result = (double *)malloc(sizeof(double));
				*result = castResult;
				break;
			}catch(boost::bad_lexical_cast){
				//Do nothing, since we intend to be failing a lot
			}
		}

		if(!result){
			scanner->index = savedIndex;
		}

		return result;
	}
	float * nextFloat(Scanner * scanner){
		float * result;
		unsigned int savedIndex = scanner->index;
		result = NULL;

		Token ** tokens = scanner->tokens;

		for(unsigned int index = scanner->index; index < scanner->numTokens; index++){
			Token * currentToken = tokens[index];
			scanner->index++;
			try{
				float castResult = boost::lexical_cast<float>(currentToken->string);

				result = (float *)malloc(sizeof(float));
				*result = castResult;
				break;
			}catch(boost::bad_lexical_cast){
				//Do nothing, since we intend to be failing a lot
			}
		}

		if(!result){
			scanner->index = savedIndex;
		}

		return result;
	}


	/* Check Functions */
	int hasNextInt(Scanner * scanner){
		unsigned int savedScannerIndex = scanner->index;

		int * result = nextInt(scanner);

		scanner->index = savedScannerIndex;

		if(result){
			free(result);
			return 1;
		}

		return 0;
	}

	int hasNextUnsignedInt(Scanner * scanner){
		unsigned int savedScannerIndex = scanner->index;

		unsigned int  * result = nextUnsignedInt(scanner);

		scanner->index = savedScannerIndex;

		if(result){
			free(result);
			return 1;
		}

		return 0;
	}

	int hasNextDouble(Scanner * scanner){
		unsigned int savedScannerIndex = scanner->index;

		double * result = nextDouble(scanner);

		scanner->index = savedScannerIndex;

		if(result){
			free(result);
			return 1;
		}

		return 0;
	}

	int hasNextFloat(Scanner * scanner){
		unsigned int savedScannerIndex = scanner->index;

		float * result = nextFloat(scanner);

		scanner->index = savedScannerIndex;

		if(result){
			free(result);
			return 1;
		}

		return 0;
	}

	/* Utility Functions */
	void rewindScanner(Scanner * scanner){
		scanner->index = 0;
	}
}
