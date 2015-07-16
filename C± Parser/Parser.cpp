#include "Parser.h"

Parser::Parser(void)
{
}

void Parser::addMetaTokenType(MetaTokenType * type)
{
	this->types->push_back(type);
}

std::vector<MetaToken *> * convertTokensToMetaTokens(std::vector<Token *> * tokens)
{
	return NULL; //TODO: implement
}
