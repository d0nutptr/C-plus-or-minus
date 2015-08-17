#include "Rule.h"

Rule::Rule(std::string * name)
{
	this->name = name;
	this->tokens = new vector<std::string *>();
}

void Rule::addToken(std::string * token)
{
	tokens->push_back(token);
}