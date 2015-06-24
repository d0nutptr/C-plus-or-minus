#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Token.h"

class Lexer
{
public:
	Lexer(char *);
	void beginLexing(std::vector<Token *> *);
	void addTokenType(TokenType *);
private:
	char * sourceLocation;
	std::string source;
	std::vector<TokenType *> tokenTypes;
};

