#include "Token.h"

Token::Token(std::string * value, TokenType * type)
{
	this->type = type;
	this->value = value;
}

std::string * Token::getName()
{
	return this->value;
}

TokenType * Token::getType()
{
	return this->type;
}