/*
* scanner.cpp
*
*  Created on: Feb 10, 2012
*      Author: Andrew
*/

#include "Stdafx.h"

#include <vector>
#include <string>
#include "scanner.hpp"
#include "boost/tokenizer.hpp"
#include "boost/lexical_cast.hpp"

/* Hidden utility functions */
namespace{
	template<typename Iterator, typename T>
	bool hasNextType(Iterator start, Iterator end){
		Iterator copyItr(start);
		for(; copyItr != end; copyItr++){
			try{
				boost::lexical_cast<T>(*copyItr);
				return true;
			}catch(boost::bad_lexical_cast){
				//Swallow errors
			}
		}
		return false;
	}

	template<typename Iterator, typename T>
	bool getNextType(Iterator start, Iterator end, T * ref){
		Iterator copyItr(start);

		for(; copyItr != end; copyItr++){
			try{
				*ref = boost::lexical_cast<T>(*copyItr);
				start = copyItr;
				start++;
				return true;
			}catch(boost::bad_lexical_cast){
				/* Swallow because we're expecting this a lot */
			}
		}

		return false;
	}

}

boost::char_separator<char> scanner::Scanner::customTokenizer(" ;()|\\[]{}!@#$%^&*<>?+=_,\t\n");

scanner::Scanner::Scanner(const std::string& str) : tokens(), tokenizer(str, customTokenizer){
	tokens.assign(tokenizer.begin(), tokenizer.end());
	currentPosition = tokenizer.begin();
}

bool scanner::Scanner::hasNextInt() const{
	return hasNextType<Tokenizer::iterator, int>(currentPosition, tokenizer.end());
}

bool scanner::Scanner::hasNextUnsignedInt() const{
	return hasNextType<Tokenizer::iterator, unsigned int>(currentPosition, tokenizer.end());
}

bool scanner::Scanner::hasNextFloat() const{
	return hasNextType<Tokenizer::iterator, float>(currentPosition, tokenizer.end());
}

bool scanner::Scanner::hasNextDouble() const{
	return hasNextType<Tokenizer::iterator, double>(currentPosition, tokenizer.end());
}

bool scanner::Scanner::tryGetNextInt(int * ref){
	return getNextType<Tokenizer::iterator, int>(currentPosition, tokenizer.end(), ref);
}

bool scanner::Scanner::tryGetNextUnsignedInt(unsigned int * ref){
	return getNextType<Tokenizer::iterator, unsigned int>(currentPosition, tokenizer.end(), ref);
}

bool scanner::Scanner::tryGetNextFloat(float * ref){
	return getNextType<Tokenizer::iterator, float>(currentPosition, tokenizer.end(), ref);
}

bool scanner::Scanner::tryGetNextDouble(double * ref){
	return getNextType<Tokenizer::iterator, double>(currentPosition, tokenizer.end(), ref);
}

bool scanner::Scanner::searchNextStringToken(const std::string& str){
	Tokenizer::iterator copyItr(currentPosition);
	Tokenizer::iterator resultItr = std::find_if(copyItr, tokenizer.end(), std::bind2nd(std::equal_to<std::string>(), str));

	if(resultItr != tokenizer.end()){
		currentPosition = resultItr;
		currentPosition++;
		return true;
	}

	return false;
}

void scanner::Scanner::rewind(){
	currentPosition = tokenizer.begin();
}