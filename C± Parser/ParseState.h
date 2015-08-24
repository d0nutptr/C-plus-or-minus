#pragma once
#include <map>
#include <vector>
#include <string>
#include "RuleParseInstanceSet.h"
#include "MetaTokenType.h"
#include "MetaToken.h"

class ParseState
{
public:
	ParseState();
	RuleParseInstanceSet * ruleSet;
	std::map<std::string, ParseState *> * nextStates;

	void addRule(RuleParseInstance *);
	Rule * getRuleThatMatches(std::vector<MetaToken *> * tokenStack, const std::string * nextToken);
};

