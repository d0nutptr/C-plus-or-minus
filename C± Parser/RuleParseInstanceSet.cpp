#include "RuleParseInstanceSet.h"

RuleParseInstanceSet::RuleParseInstanceSet(void)
{
	rules = new std::vector<RuleParseInstance *>();
}

void RuleParseInstanceSet::addRule(Rule * rule)
{
	//less than or equal since there's +1 instances than number of tokens
	for(int i = 0; i <= rule->tokens->size(); i ++)
	{
		RuleParseInstance * instance = new RuleParseInstance(rule, i);
		rules->push_back(instance);
	}
}

/**
* returns a set of all definitions for a token
*/
std::vector<RuleParseInstance *> * RuleParseInstanceSet::getRuleInstanceDefinition(const std::string * token)
{
	std::vector<RuleParseInstance *> * results = new std::vector<RuleParseInstance *>();

	for(int i = 0; i < rules->size(); i++)
	{
		if(*rules->at(i)->rule->name == *token
			&& rules->at(i)->index == 0)
		{
			results->push_back(rules->at(i));
		}
	}

	return results;
}

/**
* returns the next RuleParseInstance in the series. NULL if it doesn't exist
*/
RuleParseInstance * RuleParseInstanceSet::getNextRuleInstance(RuleParseInstance * instance)
{
	RuleParseInstance * result = NULL;

	for(int i = 0; i < rules->size(); i ++)
	{
		RuleParseInstance * test = rules->at(i);

		if(test->rule == instance->rule
			&& test->index == (instance->index + 1))
		{
			result = test;
			break;
		}
	}

	return result;
}