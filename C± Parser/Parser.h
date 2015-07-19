#pragma once
#include <vector>
#include "MetaToken.h"
#include "MetaTokenType.h"

class Parser
{
public:
	Parser(void);
	void addMetaTokenType(MetaTokenType *);
	std::vector<MetaToken *> * parse(std::vector<MetaToken *> *);
private:
	std::vector<MetaTokenType *> * types;
};