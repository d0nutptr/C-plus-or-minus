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
	std::vector<MetaToken *> * metaTokens = new std::vector<MetaToken *>();

	for(int i = 0; i < tokens->size(); i ++)
	{
		if(tokens->at(i)->getType()
	}
}
