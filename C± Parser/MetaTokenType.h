#pragma once
#include <string>
#include <vector>
#include "Token.h"

class MetaToken;

class MetaTokenType
{
public:
	MetaTokenType(const std::string *, Token * (* tryToTranslateTokenToMetaToken)(Token *));
	MetaTokenType(const std::string *);

	Token * (* tryToTranslateTokenToMetaToken)(Token *);

	const std::string * name;
};

