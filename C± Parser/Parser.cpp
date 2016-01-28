#include "Parser.h"
#include "TokenNames.h"
#include "ParseResult.h"
#include <iostream>

Parser::Parser()
{
	this->types = new std::vector<MetaTokenType *>();
	this->states = new std::vector<ParseState *>();
	this->ruleSet = new RuleParseInstanceSet();
}

void Parser::addMetaTokenType(MetaTokenType * type)
{
	this->types->push_back(type);
}

ParseResult * Parser::parse(std::vector<MetaToken *> * tokens)
{
	ParseResult * result = NULL;

	std::vector<MetaToken *> * operatingStack = new std::vector<MetaToken *>();
	std::vector<ParseState *> * stateStack = new std::vector<ParseState *>();

	//initial state
	stateStack->push_back(states->at(0));

	while(!(operatingStack->size() == 1
		&& *operatingStack->at(0)->getType()->name == *TOKEN_PROGRAM
		&& tokens->size() == 0))
	{
		//get the latest state
		ParseState * state = stateStack->at(stateStack->size() - 1);

		//get the next token that we can read in
		MetaToken * nextToken = tokens->size() > 0 ? tokens->at(0) : NULL;

		//try to get a rule that can compress this down
		Rule * rule = state->getRuleThatMatches(operatingStack, nextToken != NULL ? nextToken->getType()->name : NULL);

		if(rule == NULL)
		{
			//consume a character
			std::string * nextTokenString = new std::string(*nextToken->getType()->name);

			if(state->nextStates->find(*nextTokenString) == state->nextStates->end())
			{
				result = new ParseResult(operatingStack);
				break;
			}

			ParseState * newState = state->nextStates->at(*nextTokenString);

			stateStack->push_back(newState);
			operatingStack->push_back(tokens->at(0));
			tokens->erase(tokens->begin());
		}
		else
		{
			//reduce the tokens into a new metatoken based on rule
			MetaTokenType * newType = new MetaTokenType(rule->name);
			std::vector<MetaToken *> * newTokenContents = new std::vector<MetaToken *>();

			//reduce a token
			//remove the states from the state machine
			for(int i = 0; i < rule->tokens->size(); i ++)
			{
				//remove last element
				stateStack->pop_back();
				
				//add the element at the end, to the front of this new stack
				newTokenContents->insert(newTokenContents->begin(), operatingStack->back());

				//remove the old element
				operatingStack->pop_back();
			}
			
			MetaToken * newToken = new MetaToken(newType, newTokenContents);

			//add new element to the beginning of the read stack
			tokens->insert(tokens->begin(), newToken);
		}
	}

	if(result == NULL)
	{
		result = new ParseResult(operatingStack->at(0));
	}

	return result;
}

bool Parser::areStatesEquivalent(ParseState * stateOne, ParseState * stateTwo)
{
	bool result = false;

	//same number of rules
	if(stateOne->ruleSet->rules->size() == stateTwo->ruleSet->rules->size())
	{
		result = true;

		//contain the same exact rules
		for(int i = 0; i < stateOne->ruleSet->rules->size(); i ++)
		{
			RuleParseInstance * rule = stateOne->ruleSet->rules->at(i);

			bool found = false;

			for(int j = 0; j < stateTwo->ruleSet->rules->size(); j ++)
			{
				if(rule == stateTwo->ruleSet->rules->at(j))
				{
					found = true;
					break;
				}
			}

			//if we didn't find a matching rule in setTwo, leave
			if(!found)
			{
				result = false;
				break;
			}
		}
	}

	return result;
}

//gets the state that's already wired up in the parser if they are the same
ParseState * Parser::getEquivalentState(ParseState * state)
{
	ParseState * resultState = NULL;

	for(int i = 0; i < states->size(); i ++)
	{
		if(areStatesEquivalent(states->at(i), state))
		{
			resultState = states->at(i);
		}
	}

	return resultState;
}