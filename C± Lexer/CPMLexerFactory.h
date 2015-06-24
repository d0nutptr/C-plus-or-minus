#pragma once
#include <string>
#include "Lexer.h"

class CPMLexerFactory
{
public:
	static Lexer * generateCPMLexer(std::string file);
private:
	static std::string * checkSimpleStartingString(std::string * source, std::string str);
	static bool isANumber(char);
	static bool isAValidIDCharacter(char character, bool acceptNum);
};

