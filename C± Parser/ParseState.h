#pragma once
#include <map>
#include <vector>
#include <string>
#include "RuleParseInstance.h"
#include "MetaTokenType.h"
#include "MetaToken.h"

class ParseState
{
public:
	ParseState();
	std::vector<RuleParseInstance *> * ruleSet;
	std::map<std::string, ParseState *> * nextStates;

	void addRule(RuleParseInstance *);
	Rule * getRuleThatMatches(std::vector<MetaToken *> * tokenStack);
};

