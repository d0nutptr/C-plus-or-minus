#pragma once
#include <string>

class TokenType
{
public:
	TokenType(const std::string *, std::string * (*function)(std::string *));
	const std::string * name;
	std::string * (*isTypeOfToken)(std::string *);
};