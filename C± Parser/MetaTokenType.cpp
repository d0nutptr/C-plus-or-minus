#include "MetaTokenType.h"

MetaTokenType::MetaTokenType(const std::string * name, Token * (* tryToTranslateTokenToMetaToken)(Token *))
{
	this->name = name;
	this->tryToTranslateTokenToMetaToken = tryToTranslateTokenToMetaToken;
}

MetaTokenType::MetaTokenType(const std::string * name)
{
	this->name = name;
	this->tryToTranslateTokenToMetaToken = NULL;
}