#pragma once
#include "RuleParseInstance.h"
#include <vector>

class RuleParseInstanceSet
{
public:
	RuleParseInstanceSet();

	std::vector<RuleParseInstance *> * rules;
	void addRule(Rule * rule);
	void addRule(RuleParseInstance * rule);

	std::vector<RuleParseInstance *> * getRuleInstanceDefinition(const std::string * token);
	RuleParseInstance * getNextRuleInstance(RuleParseInstance * instance);
	std::vector<std::string *> * getAllTerminalsForNonTerminal(std::string * name);
};

