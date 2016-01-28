#include "RuleParseInstance.h"

RuleParseInstance::RuleParseInstance(Rule * rule, int index)
{
	this->rule = rule;
	this->index = index;
}

std::string * RuleParseInstance::getNextToken()
{
	std::string * result = NULL;

	if(index >= 0 && index < rule->tokens->size())
	{
		result = rule->tokens->at(index);
	}

	return result;
}