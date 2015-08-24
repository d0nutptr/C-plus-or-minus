#include "CPMParserFactory.h"
#include "RuleParseInstanceSet.h"
#include <iostream>
#include <fstream>

CPMParserFactory::CPMParserFactory(void){}

Parser * CPMParserFactory::generateCPMParser()
{
	Parser * parser = new Parser();
	RuleParseInstanceSet * set = new RuleParseInstanceSet();

	char bufferChar;
	std::string rules = "";

	std::ifstream inputStream;
	inputStream.open("bnfrules.txt");

	if(inputStream.is_open())
	{
		while (inputStream.get(bufferChar))
		{
			rules += bufferChar;
		}

		inputStream.close();
	}

	std::string * currentRuleName = new std::string("N/A");

	//while there are rules left
	while(rules.size() != 0)
	{
		std::string line = rules.substr(0, rules.find("\n"));
		rules = rules.substr(rules.find("\n") + 1);

		if(line.at(0) == '\t')
		{
			//removes tab
			line = line.substr(1);
			
			Rule * rule = new Rule(currentRuleName);

			while(line.size() != 0)
			{
				std::string * token;

				if(line.find(" ") != std::string::npos)
				{
					token = new std::string(line.substr(0, line.find(" ")));
					line = line.substr(line.find(" ") + 1);
				}
				else
				{
					token = new std::string(line);
					line = "";
				}

				rule->addToken(token);
			}
			
			set->addRule(rule);
		}
		else
		{
			currentRuleName = new std::string(line);
		}
	}

	parser->ruleSet = set;

	std::vector<RuleParseInstance *> * programDef = parser->ruleSet->getRuleInstanceDefinition(TOKEN_PROGRAM);

	ParseState * state = generateParseState(programDef, parser->ruleSet);
	parser->states->push_back(state);

	beginAutomatonGeneration(state, parser);

	return parser;
}

ParseState * CPMParserFactory::generateParseState(std::vector<RuleParseInstance *> * baseStates, RuleParseInstanceSet * ruleSet)
{
	ParseState * state = new ParseState();

	for(int i = 0; i < baseStates->size(); i ++)
	{
		state->addRule(baseStates->at(i));
	}

	for(int i = 0; i < state->ruleSet->rules->size(); i ++)
	{
		std::string * nextToken = state->ruleSet->rules->at(i)->getNextToken();

		//we might have nonterminals if this isn't null, otherwise NULL means end of token line. If it's terminal, it won't have a definition and won't get added :)
		if(nextToken != NULL)
		{
			std::vector<RuleParseInstance *> * tokenDefinitions = ruleSet->getRuleInstanceDefinition(nextToken);

			for(int j = 0; j < tokenDefinitions->size(); j++)
			{
				RuleParseInstance * instance = tokenDefinitions->at(j);
				state->addRule(instance);
			}
		}
	}

	return state;
}

void CPMParserFactory::beginAutomatonGeneration(ParseState * state, Parser * parser)
{
	for(int i = 0; i < state->ruleSet->rules->size(); i ++)
	{
		std::string * tokenName = state->ruleSet->rules->at(i)->getNextToken();

		//we haven't used this tokenname already and it actually exists
		if(tokenName != NULL && state->nextStates->count(*tokenName) == 0)
		{
			std::vector<RuleParseInstance *> * currentMatchingRules = new std::vector<RuleParseInstance *>();

			//add all rules that have tokenName as their nextToken
			for(int j = 0; j < state->ruleSet->rules->size(); j ++)
			{
				if(state->ruleSet->rules->at(j)->getNextToken() != NULL
					&& *state->ruleSet->rules->at(j)->getNextToken() == *tokenName)
				{
					currentMatchingRules->push_back(state->ruleSet->rules->at(j));
				}
			}

			std::vector<RuleParseInstance *> * newRules = new std::vector<RuleParseInstance *>();

			//create a list of the next token for each instance
			for(int j = 0; j < currentMatchingRules->size(); j ++)
			{
				RuleParseInstance * instance = currentMatchingRules->at(j);

				if(instance->getNextToken() != NULL)
				{
					newRules->push_back(parser->ruleSet->getNextRuleInstance(instance));
				}
			}

			ParseState * newState = generateParseState(newRules, parser->ruleSet);
			ParseState * potentiallyExistingState = parser->getEquivalentState(newState);

			//if there is an equivelant state in the parser already, use it
			if(potentiallyExistingState != NULL)
			{
				//Loop back to something that already exists in the parser!
				state->nextStates->emplace(*tokenName, potentiallyExistingState);
			}
			else
			{
				//adding a new state to the parser
				state->nextStates->emplace(*tokenName, newState);
				parser->states->push_back(newState);

				beginAutomatonGeneration(newState, parser);
			}
		}
	}
}