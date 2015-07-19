#pragma once
#include "Parser.h"

class CPMParserFactory
{
public:
	static Parser * generateCPMParser(std::vector<MetaToken *> * metaTokens);
};

