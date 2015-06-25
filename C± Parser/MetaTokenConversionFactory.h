#pragma once
#include <vector>
#include "MetaTokenType.h"
#include "MetaToken.h"
#include "Token.h"

class MetaTokenConversionFactory
{
public:
	static std::vector<MetaToken *> * convertTokensToMetaTokens(std::vector<Token *> *);
private:
	MetaTokenConversionFactory(void);
};

