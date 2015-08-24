#pragma once
#include <vector>
#include "ParseState.h"
#include "ParseResult.h"
#include "MetaTokenType.h"
#include "RuleParseInstanceSet.h"

class Parser
{
public:
	Parser(void);
	void addMetaTokenType(MetaTokenType *);
	ParseResult * parse(std::vector<MetaToken *> *);
	bool areStatesEquivalent(ParseState * stateOne, ParseState * stateTwo);
	ParseState * getEquivalentState(ParseState * state);

	std::vector<ParseState *> * states;
	RuleParseInstanceSet * ruleSet;
private:
	std::vector<MetaTokenType *> * types;
};