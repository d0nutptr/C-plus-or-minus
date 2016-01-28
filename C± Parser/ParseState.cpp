#include "ParseState.h"

ParseState::ParseState(void)
{
	this->ruleSet = new RuleParseInstanceSet();
	this->nextStates = new std::map<std::string, ParseState *>();
}

void ParseState::addRule(RuleParseInstance * rule)
{
	bool hasRule = false;

	for(int i = 0; i < ruleSet->rules->size(); i ++)
	{
		if(rule->rule == ruleSet->rules->at(i)->rule
			&& rule->index == ruleSet->rules->at(i)->index)
		{
			hasRule = true;
			break;
		}
	}

	if(!hasRule)
	{
		ruleSet->addRule(rule);
	}
}

/**
* get a rule that matches anything on the token stack starting from size()-1 back.
* there cannot be in progress matching rule that has nextToken as the next token to come.
*/
Rule * ParseState::getRuleThatMatches(std::vector<MetaToken *> * tokenStack, const std::string * nextToken)
{
	Rule * result = NULL;

	for(int i = 0; i < ruleSet->rules->size(); i ++)
	{
		RuleParseInstance * ruleInstance = ruleSet->rules->at(i);
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

	//check to make sure that there doesn't exist another rule that
	//we are potentially matching with the nextToken (assuming it's also not null)
	if(result != NULL && nextToken != NULL)
	{
		//list of testing strings
		std::vector<const std::string *> * checkList = new std::vector<const std::string *>();

		//add list of current operating stack
		for(int i = 0; i < tokenStack->size(); i ++)
		{
			checkList->push_back(tokenStack->at(i)->getType()->name);
		}

		//add next token. we'll require that the last two tokens are matched to a rule somehow
		checkList->push_back(nextToken);

		bool potentialRuleMatch = false;

		//check each rule until something shows promise
		for(int i = 0; i < ruleSet->rules->size(); i ++)
		{
			Rule * currentRule = ruleSet->rules->at(i)->rule;

			//we have a minimum of two tokens that absolutely have to match
			//additionally, we dont want to check the rule we want to reduce too
			if(currentRule->tokens->size() > 1 && currentRule != result)
			{
				//keeps track of which token to check in the rule
				int ruleCounter = 0;
				
				//this is the iterator for the following for loop
				//we're doing this outside of the forloop declaration since it's kinda long
				//basically we're not checking anywhere in the list where the rule length isn't even long enough to justify the checking.
				int j = checkList->size() >= currentRule->tokens->size() ? checkList->size() - currentRule->tokens->size() : 0;

				//for each token in the list
				for(; j < checkList->size(); j ++)
				{
					//if we're about to check the last character, then test all the possibilities
					if(j == checkList->size() - 1)
					{
						std::vector<std::string *> * terminals = ruleSet->getAllTerminalsForNonTerminal(currentRule->tokens->at(ruleCounter));

						bool foundMatch = false;

						for(int k = 0; k < terminals->size(); k ++)
						{
							if(*checkList->at(j) == *terminals->at(k))
							{
								foundMatch = true;
								break;
							}
						}

						if(foundMatch)
						{
							ruleCounter ++;
						}
						else
						{
							ruleCounter = 0;
						}
					}
					else
					{
						if(*checkList->at(j) == *currentRule->tokens->at(ruleCounter))
						{
							ruleCounter ++;
						}
						else
						{
							ruleCounter = 0;
						}
					}
				}

				//this only happens if the second last and the last token are matched
				if(ruleCounter >= 2)
				{
					potentialRuleMatch = true;
					break;
				}
			}
		}

		//if we have a potential rule match, fuck the police and dont send anything back. We might have a better rule to apply.
		if(potentialRuleMatch)
		{
			result = NULL;
		}
	}

	return result;
}