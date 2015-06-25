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
	this->rawContents = new std::string(baseToken->getName());
}