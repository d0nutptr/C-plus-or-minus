#pragma once
#include <string>
#include "TokenType.h"

class Token
{
public:
	Token(std::string *, TokenType *);
	std::string * getName();
	TokenType * getType();
private:
	std::string * value;
	TokenType * type;
};
