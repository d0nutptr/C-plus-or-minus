#pragma once
#include "Token.h"
#include "MetaTokenType.h"
#include <vector>

class MetaToken
{
public:
	MetaToken(MetaTokenType *, std::vector<MetaToken *> *);
	MetaToken(MetaTokenType *, Token *);
	
	std::vector<MetaToken *> * contents;
	MetaTokenType * type;

	std::string * rawContents;
};

