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

	parser->addMetaTokenType(new MetaTokenType(TOKEN_VARIABLE_DECLARATION, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 2)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);

				if(tokenOne->getType()->name == TOKEN_TYPE
					&& tokenTwo->getType()->name == TOKEN_ID)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);

					result = new MetaToken(new MetaTokenType(TOKEN_VARIABLE_DECLARATION), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_TYPE, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 1)
			{
				MetaToken * token = tokens->at(start);

				if(token->getType()->name == TOKEN_PRIMITIVE_TYPE
					|| token->getType()->name == TOKEN_ARRAY_TYPE
					|| token->getType()->name == TOKEN_ID)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(token);

					result = new MetaToken(new MetaTokenType(TOKEN_TYPE), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_PRIMITIVE_TYPE, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 1)
			{
				MetaToken * token = tokens->at(start);

				if(token->getType()->name == TOKEN_INT_TYPE
					|| token->getType()->name == TOKEN_DOUBLE_TYPE
					|| token->getType()->name == TOKEN_BOOLEAN_TYPE
					|| token->getType()->name == TOKEN_CHAR_TYPE
					|| token->getType()->name == TOKEN_VOID_TYPE)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(token);

					result = new MetaToken(new MetaTokenType(TOKEN_PRIMITIVE_TYPE), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_ARRAY_TYPE, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 3)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);

				if(tokenOne->getType()->name == TOKEN_TYPE
					&& tokenTwo->getType()->name == TOKEN_OPEN_BRACKET
					&& tokenThree->getType()->name == TOKEN_CLOSE_BRACKET)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);

					result = new MetaToken(new MetaTokenType(TOKEN_ARRAY_TYPE), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_ASSIGNMENT_STATEMENT, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 3)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);

				//if this seems too verbose, get over it
				//i'm being verbose to make it easier to edit later and append to if need be
				if((tokenOne->getType()->name == TOKEN_ID
					&& tokenTwo->getType()->name == TOKEN_ASSIGNMENT_OPERATOR
					&& tokenThree->getType()->name == TOKEN_VALUE)
					|| (tokenOne->getType()->name == TOKEN_VARIABLE_DECLARATION
					&& tokenTwo->getType()->name == TOKEN_ASSIGNMENT_OPERATOR
					&& tokenThree->getType()->name == TOKEN_VALUE))
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);

					result = new MetaToken(new MetaTokenType(TOKEN_ASSIGNMENT_STATEMENT), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_EXPRESSION, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 1)
			{
				MetaToken * tokenOne = tokens->at(start);

				if(tokenOne->getType()->name == TOKEN_FUNCTION_CALL
					|| tokenOne->getType()->name == TOKEN_INSTANTIATION)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);

					result = new MetaToken(new MetaTokenType(TOKEN_EXPRESSION), resultTokens);
				}
			}
			else if(length == 2)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);

				if((tokenOne->getType()->name == TOKEN_PREUNARY_OPERATOR
					&& tokenTwo->getType()->name == TOKEN_VALUE)
					|| (tokenOne->getType()->name == TOKEN_VALUE
					&& tokenTwo->getType()->name == TOKEN_POSTUNARY_OPERATOR))
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);

					result = new MetaToken(new MetaTokenType(TOKEN_EXPRESSION), resultTokens);
				}
			}
			else if(length == 3)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);

				if((tokenOne->getType()->name == TOKEN_OPEN_PARAN
					&& tokenTwo->getType()->name == TOKEN_VALUE
					&& tokenThree->getType()->name == TOKEN_CLOSE_PARAN)
					|| (tokenOne->getType()->name == TOKEN_VALUE
					&& tokenTwo->getType()->name == TOKEN_BINARY_OPERATOR
					&& tokenThree->getType()->name == TOKEN_VALUE))
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);

					result = new MetaToken(new MetaTokenType(TOKEN_EXPRESSION), resultTokens);
				}
			}
			else if(length == 5)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);
				MetaToken * tokenFour = tokens->at(start + 3);
				MetaToken * tokenFive = tokens->at(start + 4);

				if(tokenOne->getType()->name == TOKEN_VALUE
					&& tokenTwo->getType()->name == TOKEN_QUESTION
					&& tokenThree->getType()->name == TOKEN_VALUE
					&& tokenFour->getType()->name == TOKEN_COLON
					&& tokenFive->getType()->name == TOKEN_VALUE)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);
					resultTokens->push_back(tokenFour);
					resultTokens->push_back(tokenFive);

					result = new MetaToken(new MetaTokenType(TOKEN_EXPRESSION), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_VALUE, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 1)
			{
				MetaToken * token = tokens->at(start);

				if(token->getType()->name == TOKEN_NULL
					|| token->getType()->name == TOKEN_SUPER
					|| token->getType()->name == TOKEN_THIS
					|| token->getType()->name == TOKEN_EXPRESSION
					|| token->getType()->name == TOKEN_PRIMITIVE_LITERAL
					|| token->getType()->name == TOKEN_ID)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(token);

					result = new MetaToken(new MetaTokenType(TOKEN_VALUE), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_PRIMITIVE_LITERAL, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 1)
			{
				MetaToken * token = tokens->at(start);

				if(token->getType()->name == TOKEN_INT_LITERAL
					|| token->getType()->name == TOKEN_DOUBLE_LITERAL
					|| token->getType()->name == TOKEN_CHAR_LITERAL
					|| token->getType()->name == TOKEN_STRING_LITERAL
					|| token->getType()->name == TOKEN_BOOLEAN_LITERAL)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(token);

					result = new MetaToken(new MetaTokenType(TOKEN_VALUE), resultTokens);
				}
			}
		}

		return result;
	}));

	return parser;
}