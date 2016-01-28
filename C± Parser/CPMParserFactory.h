#pragma once
#include "Parser.h"

class CPMParserFactory
{
public:
	static Parser * generateCPMParser();
private:
	static ParseState * generateParseState(std::vector<RuleParseInstance *> * baseStates, RuleParseInstanceSet * ruleSet);
	static void beginAutomatonGeneration(ParseState * state, Parser * parser);
	CPMParserFactory(void);
};

