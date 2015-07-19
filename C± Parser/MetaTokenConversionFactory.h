#pragma once
#include <vector>
#include "MetaTokenType.h"
#include "MetaToken.h"
#include "Token.h"

class MetaTokenConversionFactory
{
public:
	std::vector<MetaToken *> * convertTokensToMetaTokens(std::vector<Token *> *);
	MetaTokenConversionFactory(void);
private:
	std::vector<MetaTokenType *> * metaTokenTypes;
	static Token * checkIfTypeNameMatches(Token *, const std::string *);
};

