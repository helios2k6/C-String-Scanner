/*
* scanner.cpp
*
*  Created on: Feb 10, 2012
*      Author: Andrew
*/

#include <vector>
#include <string>
#include "scanner.h"
#include "boost/tokenizer.hpp"
#include "boost/lexical_cast.hpp"

boost::char_separator<char> scanner::Scanner::customTokenizer(" ;()|\\[]{}!@#$%^&*<>?+=_,\t\n");

scanner::Scanner::Scanner(const std::string& str) : tokens(), index(0){
	Tokenizer tokenizer(str, customTokenizer);
	tokens.assign(tokenizer.begin(), tokenizer.end());
}

bool scanner::Scanner::hasNextInt() const{

}