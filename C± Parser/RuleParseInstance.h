#pragma once
#include "Rule.h"

class RuleParseInstance
{
public:
	RuleParseInstance(Rule * rule, int index);
	Rule * rule;
	int index;

	std::string * getNextToken();
};

