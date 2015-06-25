#pragma once
#include <string>
#include <vector>
#include "MetaToken.h"

class MetaTokenType
{
public:
	MetaTokenType(std::string, std::vector<MetaToken *> * (* containsMetaToken)(std::vector<MetaToken *> *));
	std::string name;
	std::vector<MetaToken *> * (* containsMetaToken)(std::vector<MetaToken *> *);
};

