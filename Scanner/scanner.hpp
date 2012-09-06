/*
 * scanner.hpp
 *
 *  Created on: Feb 7, 2012
 *      Author: Andrew
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include <vector>
#include <string>
#include "boost/tokenizer.hpp"
#include "boost/lexical_cast.hpp"

namespace scanner{
	typedef boost::tokenizer<boost::char_separator<char> > Tokenizer;
	class Scanner{
	public: 
		Scanner(const std::string& str);

		bool hasNextInt() const;
		bool hasNextUnsignedInt() const;
		bool hasNextDouble() const;
		bool hasNextFloat() const;

		bool tryGetNextInt(int * ref);
		bool tryGetNextUnsignedInt(unsigned int * ref);
		bool tryGetNextDouble(double * ref);
		bool tryGetNextFloat(float * ref);

		bool searchNextStringToken(const std::string& str);

		void rewind();

	private:
		std::vector<std::string> tokens;
		Tokenizer tokenizer;
		Tokenizer::iterator currentPosition;

		/* Private static boost tokenizer */
		static boost::char_separator<char> customTokenizer;
	};
}

#endif /* SCANNER_H_ */
