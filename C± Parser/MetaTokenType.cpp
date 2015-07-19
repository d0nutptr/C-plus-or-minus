#include "MetaTokenType.h"

MetaTokenType::MetaTokenType(const std::string * name, std::vector<MetaToken *> * (* containsMetaToken)(std::vector<MetaToken *> *))
{
	this->name = name;
	this->containsMetaToken = containsMetaToken;
	this->tryToTranslateTokenToMetaToken = NULL;
}

MetaTokenType::MetaTokenType(const std::string * name, Token * (* tryToTranslateTokenToMetaToken)(Token *))
{
	this->name = name;
	this->containsMetaToken = NULL;
	this->tryToTranslateTokenToMetaToken = tryToTranslateTokenToMetaToken;
}