#include "TokenType.h"

TokenType::TokenType(const std::string * _name, std::string * (* function)(std::string * param1)) : name(_name)
{
	this->isTypeOfToken = function;
}