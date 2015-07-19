#pragma once
#include <string>
#include <vector>
#include "Token.h"

class MetaToken;

class MetaTokenType
{
public:
	MetaTokenType(const std::string *, std::vector<MetaToken *> * (* containsMetaToken)(std::vector<MetaToken *> *));
	MetaTokenType(const std::string *, Token * (* tryToTranslateTokenToMetaToken)(Token *));
	
	std::vector<MetaToken *> * (* containsMetaToken)(std::vector<MetaToken *> *);
	Token * (* tryToTranslateTokenToMetaToken)(Token *);

	const std::string * name;
};

