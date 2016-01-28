#pragma once
#include <string>
#include <vector>
#include "Token.h"

class Lexer
{
public:
	Lexer(char *);
	void beginLexing(std::vector<Token *> *);
	void addTokenType(TokenType *);
private:
	std::string * source;
	std::vector<TokenType *> * tokenTypes;
};

