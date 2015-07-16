#pragma once
#include "Token.h"
#include "MetaTokenType.h"
#include <vector>

class MetaToken
{
public:
	MetaToken(MetaTokenType *, std::vector<MetaToken *> *);
	MetaToken(MetaTokenType *, Token *);

	Token * getBaseToken();
	std::vector<MetaToken *> * getContents();
	MetaTokenType * getType();

	bool isLeaf();

private:
	Token * rawContents;
	std::vector<MetaToken *> * contents;
	MetaTokenType * type;
};
