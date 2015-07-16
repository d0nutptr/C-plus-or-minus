#include "MetaToken.h"

MetaToken::MetaToken(MetaTokenType * type, std::vector<MetaToken *> * contents)
{
	this->type = type;
	this->contents = contents;
	this->rawContents = NULL;
}

MetaToken::MetaToken(MetaTokenType * type, Token * baseToken)
{
	this->type = type;
	this->contents = NULL;
	this->rawContents = baseToken;
}

bool MetaToken::isLeaf()
{
	return (this->rawContents != NULL);
}

Token * MetaToken::getBaseToken()
{
	return this->rawContents;
}

std::vector<MetaToken *> * MetaToken::getContents()
{
	return this->contents;
}

MetaTokenType * MetaToken::getType()
{
	return this->type;
}