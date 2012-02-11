/*
 * scanner.cxx
 *
 *  Created on: Feb 10, 2012
 *      Author: Andrew
 */

#include <string>
#include <vector>
#include "boost/tokenizer.hpp"
#include "boost/lexical_cast.hpp"
extern "C"{
#include "scanner.h"
}

/* External C functions */
extern "C"{
Scanner * createScanner(const char * string){
	std::string cppString(string);
	std::vector<std::string> tokenizedStrings;

	boost::char_separator<char> customTokenizer(" ;()|\\[]{}!@#$%^&*<>?+-", ".");
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
		const std::string& currentString = tokenizedStrings[index];
		Token * currentToken = (Token *)malloc(sizeof(Token));
		currentToken->string = currentString.c_str();
		currentToken->length = currentString.length();

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

	result = NULL;

	Token ** tokens = scanner->tokens;

	for(unsigned int index = scanner->index; index < scanner->numTokens; index++){
		Token * currentToken = tokens[index];
		try{
			int castResult = boost::lexical_cast<int>(currentToken->string);

			result = (int *)malloc(sizeof(int));
			*result = castResult;

			scanner->index = index;
		}catch(boost::bad_lexical_cast& c){
			//Do nothing, since we intend to be failing a lot
		}
	}

	return result;
}


}
