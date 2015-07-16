#pragma once
#include <vector>
#include "MetaToken.h"
#include "MetaTokenType.h"
#include "MetaTokenConversionFactory.h"

class Parser
{
public:
	Parser(void);
	void addMetaTokenType(MetaTokenType * type);
	std::vector<MetaToken *> * convertTokensToMetaTokens(std::vector<Token *> * tokens);
	std::vector<MetaToken *> * parse(std::vector<MetaToken *> * tokens);
private:
	std::vector<MetaTokenType *> * types;
};

