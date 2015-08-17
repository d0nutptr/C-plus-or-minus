#include "ParseState.h"

ParseState::ParseState(void)
{
	this->ruleSet = new std::vector<RuleParseInstance *>();
	this->nextStates = new std::map<std::string, ParseState *>();
}

void ParseState::addRule(RuleParseInstance * rule)
{
	bool hasRule = false;

	for(int i = 0; i < ruleSet->size(); i ++)
	{
		if(rule->rule == ruleSet->at(i)->rule
			&& rule->index == ruleSet->at(i)->index)
		{
			hasRule = true;
			break;
		}
	}

	if(!hasRule)
	{
		ruleSet->push_back(rule);
	}
}

/**
* get a rule that matches anything on the token stack starting from size()-1 back.
*/
Rule * ParseState::getRuleThatMatches(std::vector<MetaToken *> * tokenStack)
{
	Rule * result = NULL;

	for(int i = 0; i < ruleSet->size(); i ++)
	{
		RuleParseInstance * ruleInstance = ruleSet->at(i);
		int tokenCount = ruleInstance->rule->tokens->size();
		int index = ruleInstance->index;

		//if this rule is at the end of indexing and the tokenstack has enough items to potentially match
		if(index == tokenCount && tokenStack->size() >= tokenCount)
		{
			bool isMatching = true;

			for(int j = 0; j < tokenCount; j ++)
			{
				MetaToken * token = tokenStack->at(tokenStack->size() - 1 - j);
				std::string * ruleName = ruleInstance->rule->tokens->at(ruleInstance->rule->tokens->size() - 1 - j);

				if(*token->getType()->name != *ruleName)
				{
					isMatching = false;
					break;
				}
			}

			if(isMatching)
			{
				result = ruleInstance->rule;
				break;
			}
		}
	}

	return result;
}