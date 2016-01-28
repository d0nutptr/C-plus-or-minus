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

void RuleParseInstanceSet::addRule(RuleParseInstance * rule)
{
	rules->push_back(rule);
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

std::vector<std::string *> * RuleParseInstanceSet::getAllTerminalsForNonTerminal(std::string * name)
{
	std::vector<std::string *> * result = new std::vector<std::string *>();

	std::vector<std::string *> * tempStorage = new std::vector<std::string *>();

	tempStorage->push_back(name);
	result->push_back(name);

	for(int i = 0; i < tempStorage->size(); i++)
	{
		std::vector<RuleParseInstance *> * definitions = getRuleInstanceDefinition(tempStorage->at(i));

		//nonterminal
		if(definitions->size() > 0)
		{
			for(int j = 0; j < definitions->size(); j ++)
			{
				RuleParseInstance * instance = definitions->at(j);
				std::string * potentialNewTokenName = instance->rule->tokens->at(0);

				bool exists = false;

				//to prevent duplicates
				for(int k = 0; k < tempStorage->size(); k ++)
				{
					if(*tempStorage->at(k) == *potentialNewTokenName)
					{
						exists = true;
						break;
					}
				}

				if(!exists)
				{
					tempStorage->push_back(potentialNewTokenName);
					result->push_back(potentialNewTokenName);
				}
			}
		}
		//terminals
		else
		{
			result->push_back(tempStorage->at(i));
		}
	}

	return result;
}