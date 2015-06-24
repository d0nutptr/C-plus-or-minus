#pragma once
#include <string>

class TokenType
{
public:
	TokenType(std::string, std::string * (*function)(std::string *));
	std::string name;
	std::string * (*isTypeOfToken)(std::string *);
};