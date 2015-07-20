#include "MetaTokenType.h"

MetaTokenType::MetaTokenType(const std::string * name, MetaToken * (* containsMetaToken)(std::vector<MetaToken *> *, long, long))
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

MetaTokenType::MetaTokenType(const std::string * name)
{
	this->name = name;
	this->containsMetaToken = NULL;
	this->tryToTranslateTokenToMetaToken = NULL;
}