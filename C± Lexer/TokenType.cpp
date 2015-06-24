#include "TokenType.h"

TokenType::TokenType(std::string name, std::string * (* function)(std::string * param1))
{
	this->name = name;
	this->isTypeOfToken = function;
}