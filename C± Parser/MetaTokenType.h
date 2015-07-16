#pragma once
#include <string>
#include <vector>
#include "MetaToken.h"

class MetaTokenType
{
public:
	MetaTokenType(std::string, std::vector<MetaToken *> * (* containsMetaToken)(std::vector<MetaToken *> *));
	MetaTokenType(std::string, Token * (* tryToTranslateTokenToMetaToken)(Token *));
	
	std::vector<MetaToken *> * (* containsMetaToken)(std::vector<MetaToken *> *);
	Token * (* tryToTranslateTokenToMetaToken)(Token *);

	std::string name;
};

