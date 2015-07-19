#include "Parser.h"

Parser::Parser()
{
}

void Parser::addMetaTokenType(MetaTokenType * type)
{
	this->types->push_back(type);
}

std::vector<MetaToken *> * Parser::parse(std::vector<MetaToken *> * tokens)
{
	return NULL;
}