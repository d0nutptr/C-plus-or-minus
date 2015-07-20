#include "CPMParserFactory.h"
#include "TokenNames.h"

Parser * CPMParserFactory::generateCPMParser(std::vector<MetaToken *> * metaTokens)
{
	Parser * parser = new Parser();

	parser->addMetaTokenType(new MetaTokenType(TOKEN_PROGRAM, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > (start + length))
		{
			std::vector<MetaToken *> * checkTokens = new std::vector<MetaToken *>();
			bool passesCheck = true;

			//check if all tokens are of the valid type in the range
			for(long i = start; i < (start + length); i ++)
			{
				MetaToken * token = tokens->at(i);
				const string * type = token->getType()->name;

				if(type == TOKEN_IMPORT_STATEMENT
					|| type == TOKEN_FUNCTION_STATEMENT
					|| type == TOKEN_CLASS_DEFINITION
					|| type == TOKEN_CLASS_STATEMENT)
				{
					checkTokens->push_back(token);
				}
				else
				{
					passesCheck = false;
					break;
				}
			}

			//if the tokens were all valid in the range given
			if(passesCheck)
			{
				result = new MetaToken(new MetaTokenType(TOKEN_PROGRAM), checkTokens);
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_IMPORT_STATEMENT, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() < start + length)
		{
			//requires 3 components
			if(length == 3)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);

				if(tokenOne->getType()->name == TOKEN_IMPORT
					&& tokenTwo->getType()->name == TOKEN_STRING_LITERAL
					&& tokenThree->getType()->name == TOKEN_SEMI_COLON)
				{
					std::vector<MetaToken *> * importTokens = new std::vector<MetaToken *>();
					importTokens->push_back(tokenOne);
					importTokens->push_back(tokenTwo);
					importTokens->push_back(tokenThree);

					result = new MetaToken(new MetaTokenType(TOKEN_IMPORT_STATEMENT), importTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_FUNCTION_STATEMENT, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() < start + length)
		{
			if(length == 1)
			{
				if(tokens->at(start)->getType()->name == TOKEN_LOOP
					|| tokens->at(start)->getType()->name == TOKEN_CONDITIONAL)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokens->at(start));

					result = new MetaToken(new MetaTokenType(TOKEN_FUNCTION_STATEMENT), resultTokens);
				}
			}
			else if(length == 2)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);

				if((tokenOne->getType()->name == TOKEN_VARIABLE_DECLARATION
					&& tokenTwo->getType()->name == TOKEN_SEMI_COLON)

					|| (tokenOne->getType()->name == TOKEN_ASSIGNMENT_STATEMENT
					&& tokenTwo->getType()->name == TOKEN_SEMI_COLON)

					|| (tokenOne->getType()->name == TOKEN_RETURN_STATEMENT
					&& tokenTwo->getType()->name == TOKEN_SEMI_COLON)

					|| (tokenOne->getType()->name == TOKEN_EXPRESSION
					&& tokenTwo->getType()->name == TOKEN_SEMI_COLON))
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);

					result = new MetaToken(new MetaTokenType(TOKEN_FUNCTION_STATEMENT), resultTokens);
				}
			}
		}

		return result;
	}));

	return parser;
}