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

	parser->addMetaTokenType(new MetaTokenType(TOKEN_FUNCTION_CALL, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 3)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);

				if(tokenOne->getType()->name == TOKEN_ID
					&& tokenTwo->getType()->name == TOKEN_OPEN_PARAN
					&& tokenThree->getType()->name == TOKEN_CLOSE_PARAN)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);

					result = new MetaToken(new MetaTokenType(TOKEN_FUNCTION_CALL), resultTokens);
				}
			}
			else if(length == 4)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);
				MetaToken * tokenFour = tokens->at(start + 3);
				
				if(tokenOne->getType()->name == TOKEN_ID
					&& tokenTwo->getType()->name == TOKEN_OPEN_PARAN
					&& tokenThree->getType()->name == TOKEN_PARAMETER_LIST
					&& tokenFour->getType()->name == TOKEN_CLOSE_PARAN)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);
					resultTokens->push_back(tokenFour);

					result = new MetaToken(new MetaTokenType(TOKEN_FUNCTION_CALL), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_PARAMETER_LIST, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			//if the token count is odd then it's likely in the form (parameter[, parameter[, parameter[, ..]]])
			if(length % 2 == 1)
			{
				bool valid = true;

				std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();

				for(int i = 0; i < length; i ++)
				{
					MetaToken * token = tokens->at(start + i);

					//even (parameter)
					if(i % 2 == 0)
					{
						if(token->getType()->name != TOKEN_PARAMETER)
						{
							valid = false;
							break;
						}
					}
					//odd (comma)
					else
					{
						if(token->getType()->name != TOKEN_COMMA)
						{
							valid = false;
							break;
						}
					}

					resultTokens->push_back(token);
				}

				if(valid)
				{
					result = new MetaToken(new MetaTokenType(TOKEN_PARAMETER_LIST), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_PARAMETER, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 1)
			{
				MetaToken * token = tokens->at(start);

				if(token->getType()->name == TOKEN_VALUE)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(token);

					result = new MetaToken(new MetaTokenType(TOKEN_PARAMETER), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_INSTANTIATION, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 4)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);
				MetaToken * tokenFour = tokens->at(start + 3);

				if(tokenOne->getType()->name == TOKEN_NEW
					&& tokenTwo->getType()->name == TOKEN_ID
					&& tokenThree->getType()->name == TOKEN_OPEN_PARAN
					&& tokenFour->getType()->name == TOKEN_CLOSE_PARAN)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);
					resultTokens->push_back(tokenFour);

					result = new MetaToken(new MetaTokenType(TOKEN_INSTANTIATION), resultTokens);
				}
			}
			else if(length == 5)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);
				MetaToken * tokenFour = tokens->at(start + 3);
				MetaToken * tokenFive = tokens->at(start + 4);

				if(tokenOne->getType()->name == TOKEN_NEW
					&& tokenTwo->getType()->name == TOKEN_ID
					&& tokenThree->getType()->name == TOKEN_OPEN_PARAN
					&& tokenFour->getType()->name == TOKEN_PARAMETER_LIST
					&& tokenFive->getType()->name == TOKEN_CLOSE_PARAN)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);
					resultTokens->push_back(tokenFour);
					resultTokens->push_back(tokenFive);

					result = new MetaToken(new MetaTokenType(TOKEN_INSTANTIATION), resultTokens);
				}

			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_PREUNARY_OPERATOR, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 1)
			{
				MetaToken * token = tokens->at(start);

				if(token->getType()->name == TOKEN_BANG)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(token);
					
					result = new MetaToken(new MetaTokenType(TOKEN_PREUNARY_OPERATOR), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_POSTUNARY_OPERATOR, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 1)
			{
				MetaToken * token = tokens->at(start);

				if(token->getType()->name == TOKEN_MINUSMINUS
					|| token->getType()->name == TOKEN_PLUSPLUS)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(token);
					
					result = new MetaToken(new MetaTokenType(TOKEN_PREUNARY_OPERATOR), resultTokens);
				}
			}
			else if(length == 3)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);

				if(tokenOne->getType()->name == TOKEN_OPEN_BRACE
					&& tokenTwo->getType()->name == TOKEN_VALUE
					&& tokenThree->getType()->name == TOKEN_CLOSE_BRACE)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);
					
					result = new MetaToken(new MetaTokenType(TOKEN_PREUNARY_OPERATOR), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_BINARY_OPERATOR, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 1)
			{
				MetaToken * token = tokens->at(start);

				if(token->getType()->name == TOKEN_PLUS
					|| token->getType()->name == TOKEN_MINUS
					|| token->getType()->name == TOKEN_MULTIPLY
					|| token->getType()->name == TOKEN_DIVIDE
					|| token->getType()->name == TOKEN_MOD
					|| token->getType()->name == TOKEN_POWER
					|| token->getType()->name == TOKEN_IS_EQUALS
					|| token->getType()->name == TOKEN_IS_GREATER_THAN_OR_EQUALS
					|| token->getType()->name == TOKEN_IS_GREATER_THAN
					|| token->getType()->name == TOKEN_IS_LESS_THAN_OR_EQUALS
					|| token->getType()->name == TOKEN_IS_LESS_THAN
					|| token->getType()->name == TOKEN_IS_NOT_EQUALS
					|| token->getType()->name == TOKEN_AND
					|| token->getType()->name == TOKEN_OR
					|| token->getType()->name == TOKEN_INSTANCEOF
					|| token->getType()->name == TOKEN_XOR
					|| token->getType()->name == TOKEN_ACCESS_OPERATOR)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(token);
					
					result = new MetaToken(new MetaTokenType(TOKEN_BINARY_OPERATOR), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_RETURN_STATEMENT, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 1)
			{
				MetaToken * token = tokens->at(start);

				if(token->getType()->name == TOKEN_RETURN)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(token);
					
					result = new MetaToken(new MetaTokenType(TOKEN_RETURN_STATEMENT), resultTokens);
				}
			}
			else if(length == 2)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);

				if(tokenOne->getType()->name == TOKEN_RETURN
					&& tokenTwo->getType()->name == TOKEN_VALUE)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					
					result = new MetaToken(new MetaTokenType(TOKEN_RETURN_STATEMENT), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_LOOP, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 1)
			{
				MetaToken * token = tokens->at(start);

				if(token->getType()->name == TOKEN_FOR_LOOP
					|| token->getType()->name == TOKEN_WHILE_LOOP)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(token);
					
					result = new MetaToken(new MetaTokenType(TOKEN_LOOP), resultTokens);
				}
			}
		}

		return result;
	}));

	//please keep this closed at all times.. it's ... it's really bad.. and i was too tired to give a shit to fix it..
	parser->addMetaTokenType(new MetaTokenType(TOKEN_FOR_LOOP, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			//for, (, ;, cond, ;, ), {, }
			if(length >= 8 && length < 12)
			{
				std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
				int currentToken = 0;

				MetaToken * processingToken = tokens->at(start + currentToken);
				
				if(processingToken->getType()->name == TOKEN_FOR)
				{
					resultTokens->push_back(processingToken);

					currentToken ++;
					processingToken = tokens->at(start + currentToken);

					if(processingToken->getType()->name == TOKEN_OPEN_PARAN)
					{
						resultTokens->push_back(processingToken);

						currentToken ++;
						processingToken = tokens->at(start + currentToken);

						if(processingToken->getType()->name == TOKEN_ASSIGNMENT_STATEMENT)
						{
							resultTokens->push_back(processingToken);

							currentToken ++;
							processingToken = tokens->at(start + currentToken);
						}
						
						if(processingToken->getType()->name == TOKEN_SEMI_COLON)
						{
							resultTokens->push_back(processingToken);

							currentToken ++;
							processingToken = tokens->at(start + currentToken);

							if(processingToken->getType()->name == TOKEN_VALUE)
							{
								resultTokens->push_back(processingToken);

								currentToken ++;
								processingToken = tokens->at(start + currentToken);

								if(processingToken->getType()->name == TOKEN_SEMI_COLON)
								{
									resultTokens->push_back(processingToken);

									currentToken ++;
									processingToken = tokens->at(start + currentToken);

									if(processingToken->getType()->name == TOKEN_EXPRESSION)
									{
										resultTokens->push_back(processingToken);

										currentToken ++;
										processingToken = tokens->at(start + currentToken);
									}

									if(processingToken->getType()->name == TOKEN_CLOSE_PARAN)
									{
										resultTokens->push_back(processingToken);

										currentToken ++;
										processingToken = tokens->at(start + currentToken);

										if(processingToken->getType()->name == TOKEN_OPEN_BRACE)
										{
											resultTokens->push_back(processingToken);

											currentToken ++;
											processingToken = tokens->at(start + currentToken);

											if(processingToken->getType()->name == TOKEN_FUNCTION_STATEMENTS)
											{
												resultTokens->push_back(processingToken);

												currentToken ++;
												processingToken = tokens->at(start + currentToken);
											}

											if(processingToken->getType()->name == TOKEN_CLOSE_BRACE)
											{
												resultTokens->push_back(processingToken);

												result = new MetaToken(new MetaTokenType(TOKEN_FOR_LOOP), resultTokens);
											}
										}
									}
								}
							}
						}
					}
				}
			}
			
			if(result == NULL && length >= 8 && length < 10)
			{
				if(tokens->at(start)->getType()->name == TOKEN_FOR
					&& tokens->at(start + 1)->getType()->name == TOKEN_OPEN_PARAN
					&& tokens->at(start + 2)->getType()->name == TOKEN_VARIABLE_DECLARATION
					&& tokens->at(start + 3)->getType()->name == TOKEN_IN
					&& tokens->at(start + 4)->getType()->name == TOKEN_VALUE
					&& tokens->at(start + 5)->getType()->name == TOKEN_CLOSE_PARAN
					&& tokens->at(start + 6)->getType()->name == TOKEN_OPEN_BRACE
					&& ((tokens->at(start + 7)->getType()->name == TOKEN_FUNCTION_STATEMENTS
					&& tokens->at(start + 8)->getType()->name == TOKEN_CLOSE_BRACE)
					|| tokens->at(start + 7)->getType()->name == TOKEN_CLOSE_BRACE))
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();

					for(int i = 0; i < length; i ++)
					{
						resultTokens->push_back(tokens->at(start + i));
					}

					result = new MetaToken(new MetaTokenType(TOKEN_FOR_LOOP), resultTokens);
				}
			}
		}

		return result;

	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_FUNCTION_STATEMENTS, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
			bool valid = true;

			for(int i = 0; i < length; i ++)
			{
				if(tokens->at(start + i)->getType()->name == TOKEN_FUNCTION_STATEMENT)
				{
					resultTokens->push_back(tokens->at(start + i));
				}
				else
				{
					valid = false;
					break;
				}
			}

			if(valid)
			{
				result = new MetaToken(new MetaTokenType(TOKEN_FUNCTION_STATEMENTS), resultTokens);
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_WHILE_LOOP, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length >= 6 && length < 8)
			{
				if(tokens->at(start)->getType()->name == TOKEN_WHILE
					&& tokens->at(start + 1)->getType()->name == TOKEN_OPEN_PARAN
					&& tokens->at(start + 2)->getType()->name == TOKEN_VALUE
					&& tokens->at(start + 3)->getType()->name == TOKEN_CLOSE_PARAN
					&& tokens->at(start + 4)->getType()->name == TOKEN_OPEN_BRACE
					&& ((tokens->at(start + 5)->getType()->name == TOKEN_FUNCTION_STATEMENTS
					&& tokens->at(start + 6)->getType()->name == TOKEN_CLOSE_BRACE)
					|| tokens->at(start + 5)->getType()->name == TOKEN_CLOSE_BRACE))
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();

					for(int i = 0; i < length; i ++)
					{
						resultTokens->push_back(tokens->at(start + i));
					}

					result = new MetaToken(new MetaTokenType(TOKEN_WHILE_LOOP), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_CONDITIONAL, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 7)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);
				MetaToken * tokenFour = tokens->at(start + 3);
				MetaToken * tokenFive = tokens->at(start + 4);
				MetaToken * tokenSix = tokens->at(start + 5);
				MetaToken * tokenSeven = tokens->at(start + 6);

				if(tokenOne->getType()->name == TOKEN_IF
					&& tokenTwo->getType()->name == TOKEN_OPEN_PARAN
					&& tokenThree->getType()->name == TOKEN_VALUE
					&& tokenFour->getType()->name == TOKEN_CLOSE_PARAN
					&& tokenFive->getType()->name == TOKEN_OPEN_BRACE
					&& tokenSix->getType()->name == TOKEN_FUNCTION_STATEMENTS
					&& tokenSeven->getType()->name == TOKEN_CLOSE_BRACE)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);
					resultTokens->push_back(tokenFour);
					resultTokens->push_back(tokenFive);
					resultTokens->push_back(tokenSix);
					resultTokens->push_back(tokenSeven);

					result = new MetaToken(new MetaTokenType(TOKEN_CONDITIONAL), resultTokens);
				}
			}
			else if(length == 5)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);
				MetaToken * tokenFour = tokens->at(start + 3);
				MetaToken * tokenFive = tokens->at(start + 4);
				

				if(tokenOne->getType()->name == TOKEN_IF
					&& tokenTwo->getType()->name == TOKEN_OPEN_PARAN
					&& tokenThree->getType()->name == TOKEN_VALUE
					&& tokenFour->getType()->name == TOKEN_CLOSE_PARAN
					&& tokenFive->getType()->name == TOKEN_FUNCTION_STATEMENTS)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);
					resultTokens->push_back(tokenFour);
					resultTokens->push_back(tokenFive);

					result = new MetaToken(new MetaTokenType(TOKEN_CONDITIONAL), resultTokens);
				}
			}
			else if(length == 2)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);

				if(tokenOne->getType()->name == TOKEN_ELSE
					&& tokenTwo->getType()->name == TOKEN_FUNCTION_STATEMENT)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					
					result = new MetaToken(new MetaTokenType(TOKEN_CONDITIONAL), resultTokens);
				}

			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_CLASS_DEFINITION, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;

		if(tokens->size() > start + length)
		{
			if(length == 3)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);

				if(tokenOne->getType()->name == TOKEN_CLASS
					&& tokenTwo->getType()->name == TOKEN_ID
					&& tokenThree->getType()->name == TOKEN_CLASS_BLOCK)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);

					result = new MetaToken(new MetaTokenType(TOKEN_CLASS_DEFINITION), resultTokens);
				}
			}
			else if(length == 4)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);
				MetaToken * tokenFour = tokens->at(start + 3);

				if(tokenOne->getType()->name == TOKEN_CLASS
					&& tokenTwo->getType()->name == TOKEN_PARTIAL
					&& tokenThree->getType()->name == TOKEN_ID
					&& tokenFour->getType()->name == TOKEN_CLASS_BLOCK)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);
					resultTokens->push_back(tokenFour);

					result = new MetaToken(new MetaTokenType(TOKEN_CLASS_DEFINITION), resultTokens);
				}
			}
			else if(length == 5)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);
				MetaToken * tokenFour = tokens->at(start + 3);
				MetaToken * tokenFive = tokens->at(start + 4);

				if(tokenOne->getType()->name == TOKEN_CLASS
					&& tokenTwo->getType()->name == TOKEN_ID
					&& tokenThree->getType()->name == TOKEN_COLON
					&& tokenFour->getType()->name == TOKEN_ID
					&& tokenFive->getType()->name == TOKEN_CLASS_BLOCK)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);
					resultTokens->push_back(tokenFour);
					resultTokens->push_back(tokenFive);

					result = new MetaToken(new MetaTokenType(TOKEN_CLASS_DEFINITION), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_CLASS_BLOCK, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;
		
		if(tokens->size() > start + length)
		{
			if(length == 3)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);

				if(tokenOne->getType()->name == TOKEN_OPEN_BRACE
					&& tokenTwo->getType()->name == TOKEN_CLASS_STATEMENTS
					&& tokenThree->getType()->name == TOKEN_CLOSE_BRACE)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();

					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);

					result = new MetaToken(new MetaTokenType(TOKEN_CLASS_BLOCK), resultTokens);
				}
			}
			else if(length == 2)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);

				if(tokenOne->getType()->name == TOKEN_OPEN_BRACE
					&& tokenTwo->getType()->name == TOKEN_CLOSE_BRACE)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();

					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);

					result = new MetaToken(new MetaTokenType(TOKEN_CLASS_BLOCK), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_CLASS_STATEMENTS, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;
		
		if(tokens->size() > start + length)
		{
			if(length > 0)
			{
				bool valid = true;
				std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();

				for(int i = 0; i < length; i ++)
				{
					if(tokens->at(i)->getType()->name != TOKEN_CLASS_STATEMENT_OR_CONSTRUCTOR)
					{
						valid = false;
						break;
					}

					resultTokens->push_back(tokens->at(i));
				}

				if(valid)
				{
					result = new MetaToken(new MetaTokenType(TOKEN_CLASS_STATEMENTS), resultTokens);
				}
			}
		}
		
		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_CLASS_STATEMENT_OR_CONSTRUCTOR, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;
		
		if(tokens->size() > start + length)
		{
			if(length == 1)
			{
				MetaToken * token = tokens->at(start);

				if(token->getType()->name == TOKEN_CLASS_STATEMENT
					|| token->getType()->name == TOKEN_CONSTRUCTOR)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(token);

					result = new MetaToken(new MetaTokenType(TOKEN_CLASS_STATEMENT_OR_CONSTRUCTOR), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_CLASS_STATEMENT, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;
		
		if(tokens->size() > start + length)
		{
			if(length == 1)
			{
				MetaToken * token = tokens->at(start);

				if(token->getType()->name == TOKEN_FUNCTION_DEFINITION)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(token);

					result = new MetaToken(new MetaTokenType(TOKEN_CLASS_STATEMENT), resultTokens);
				}
			}
			else if(length == 2)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);

				if((tokenOne->getType()->name == TOKEN_VARIABLE_DECLARATION
					|| tokenOne->getType()->name == TOKEN_ASSIGNMENT_STATEMENT)
					&& tokenTwo->getType()->name == TOKEN_SEMI_COLON)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);

					result = new MetaToken(new MetaTokenType(TOKEN_CLASS_STATEMENT), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_FUNCTION_DEFINITION, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;
		
		if(tokens->size() > start + length)
		{
			if(length == 7)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);
				MetaToken * tokenFour = tokens->at(start + 3);
				MetaToken * tokenFive = tokens->at(start + 4);
				MetaToken * tokenSix = tokens->at(start + 5);
				MetaToken * tokenSeven = tokens->at(start + 6);

				if(tokenOne->getType()->name == TOKEN_FUNCTION
					&& tokenTwo->getType()->name == TOKEN_TYPE
					&& tokenThree->getType()->name == TOKEN_ID
					&& tokenFour->getType()->name == TOKEN_OPEN_PARAN
					&& tokenFive->getType()->name == TOKEN_CLOSE_PARAN
					&& tokenSix->getType()->name == TOKEN_OPEN_BRACE
					&& tokenSeven->getType()->name == TOKEN_CLOSE_BRACE)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);
					resultTokens->push_back(tokenFour);
					resultTokens->push_back(tokenFive);
					resultTokens->push_back(tokenSix);
					resultTokens->push_back(tokenSeven);

					result = new MetaToken(new MetaTokenType(TOKEN_FUNCTION_DEFINITION), resultTokens);
				}
			}
			else if(length == 8)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);
				MetaToken * tokenFour = tokens->at(start + 3);
				MetaToken * tokenFive = tokens->at(start + 4);
				MetaToken * tokenSix = tokens->at(start + 5);
				MetaToken * tokenSeven = tokens->at(start + 6);
				MetaToken * tokenEight = tokens->at(start + 7);

				if((tokenOne->getType()->name == TOKEN_FUNCTION
					&& tokenTwo->getType()->name == TOKEN_TYPE
					&& tokenThree->getType()->name == TOKEN_ID
					&& tokenFour->getType()->name == TOKEN_OPEN_PARAN
					&& tokenFive->getType()->name == TOKEN_PARAMETER_DEFINITION_LIST
					&& tokenSix->getType()->name == TOKEN_CLOSE_PARAN
					&& tokenSeven->getType()->name == TOKEN_OPEN_BRACE
					&& tokenEight->getType()->name == TOKEN_CLOSE_BRACE)
					||
					(tokenOne->getType()->name == TOKEN_FUNCTION
					&& tokenTwo->getType()->name == TOKEN_TYPE
					&& tokenThree->getType()->name == TOKEN_ID
					&& tokenFour->getType()->name == TOKEN_OPEN_PARAN
					&& tokenFive->getType()->name == TOKEN_CLOSE_PARAN
					&& tokenSix->getType()->name == TOKEN_OPEN_BRACE
					&& tokenSeven->getType()->name == TOKEN_FUNCTION_STATEMENTS
					&& tokenEight->getType()->name == TOKEN_CLOSE_BRACE))
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);
					resultTokens->push_back(tokenFour);
					resultTokens->push_back(tokenFive);
					resultTokens->push_back(tokenSix);
					resultTokens->push_back(tokenSeven);
					resultTokens->push_back(tokenEight);

					result = new MetaToken(new MetaTokenType(TOKEN_FUNCTION_DEFINITION), resultTokens);
				}
			}
			else if(length == 9)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);
				MetaToken * tokenFour = tokens->at(start + 3);
				MetaToken * tokenFive = tokens->at(start + 4);
				MetaToken * tokenSix = tokens->at(start + 5);
				MetaToken * tokenSeven = tokens->at(start + 6);
				MetaToken * tokenEight = tokens->at(start + 7);
				MetaToken * tokenNine = tokens->at(start + 8);

				if(tokenOne->getType()->name == TOKEN_FUNCTION
					&& tokenTwo->getType()->name == TOKEN_TYPE
					&& tokenThree->getType()->name == TOKEN_ID
					&& tokenFour->getType()->name == TOKEN_OPEN_PARAN
					&& tokenFive->getType()->name == TOKEN_PARAMETER_DEFINITION_LIST
					&& tokenSix->getType()->name == TOKEN_CLOSE_PARAN
					&& tokenSeven->getType()->name == TOKEN_OPEN_BRACE
					&& tokenEight->getType()->name == TOKEN_FUNCTION_STATEMENTS
					&& tokenNine->getType()->name == TOKEN_CLOSE_BRACE)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);
					resultTokens->push_back(tokenFour);
					resultTokens->push_back(tokenFive);
					resultTokens->push_back(tokenSix);
					resultTokens->push_back(tokenSeven);
					resultTokens->push_back(tokenEight);
					resultTokens->push_back(tokenNine);

					result = new MetaToken(new MetaTokenType(TOKEN_FUNCTION_DEFINITION), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_PARAMETER_DEFINITION_LIST, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;
		
		if(tokens->size() > start + length)
		{
			if(length % 2 == 1)
			{
				std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
				bool valid = true;

				for(int i = 0; i < length; i ++)
				{
					MetaToken * token = tokens->at(start + i);

					if((i % 2 == 0 && token->getType()->name == TOKEN_PARAMETER_DEFINITION)
						|| (i % 2 == 1 && token->getType()->name == TOKEN_COMMA))
					{
						resultTokens->push_back(token);
					}
					else
					{
						valid = false;
						break;
					}
				}

				if(valid)
				{
					result = new MetaToken(new MetaTokenType(TOKEN_PARAMETER_DEFINITION_LIST), resultTokens);
				}
			}
		}

		return result;
	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_PARAMETER_DEFINITION, [](std::vector<MetaToken *> * tokens, long start, long length)
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

					result = new MetaToken(new MetaTokenType(TOKEN_PARAMETER_DEFINITION), resultTokens);
				}
			}
		}

		return result;

	}));

	parser->addMetaTokenType(new MetaTokenType(TOKEN_CONSTRUCTOR, [](std::vector<MetaToken *> * tokens, long start, long length)
	{
		MetaToken * result = NULL;
		
		if(tokens->size() > start + length)
		{
			if(length == 5)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);
				MetaToken * tokenFour = tokens->at(start + 3);
				MetaToken * tokenFive = tokens->at(start + 4);

				if(tokenOne->getType()->name == TOKEN_ID
					&& tokenTwo->getType()->name == TOKEN_OPEN_PARAN
					&& tokenThree->getType()->name == TOKEN_CLOSE_PARAN
					&& tokenFour->getType()->name == TOKEN_OPEN_BRACE
					&& tokenFive->getType()->name == TOKEN_CLOSE_BRACE)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);
					resultTokens->push_back(tokenFour);
					resultTokens->push_back(tokenFive);

					result = new MetaToken(new MetaTokenType(TOKEN_CONSTRUCTOR), resultTokens);
				}
			}
			else if(length == 6)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);
				MetaToken * tokenFour = tokens->at(start + 3);
				MetaToken * tokenFive = tokens->at(start + 4);
				MetaToken * tokenSix = tokens->at(start + 5);

				if((tokenOne->getType()->name == TOKEN_ID
					&& tokenTwo->getType()->name == TOKEN_OPEN_PARAN
					&& tokenThree->getType()->name == TOKEN_PARAMETER_DEFINITION_LIST
					&& tokenFour->getType()->name == TOKEN_CLOSE_PARAN
					&& tokenFive->getType()->name == TOKEN_OPEN_BRACE
					&& tokenSix->getType()->name == TOKEN_CLOSE_BRACE)
					||
					(tokenOne->getType()->name == TOKEN_ID
					&& tokenTwo->getType()->name == TOKEN_OPEN_PARAN
					&& tokenThree->getType()->name == TOKEN_CLOSE_PARAN
					&& tokenFour->getType()->name == TOKEN_OPEN_BRACE
					&& tokenFive->getType()->name == TOKEN_FUNCTION_STATEMENTS
					&& tokenSix->getType()->name == TOKEN_CLOSE_BRACE))
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);
					resultTokens->push_back(tokenFour);
					resultTokens->push_back(tokenFive);
					resultTokens->push_back(tokenSix);

					result = new MetaToken(new MetaTokenType(TOKEN_CONSTRUCTOR), resultTokens);
				}
			}
			else if(length == 7)
			{
				MetaToken * tokenOne = tokens->at(start);
				MetaToken * tokenTwo = tokens->at(start + 1);
				MetaToken * tokenThree = tokens->at(start + 2);
				MetaToken * tokenFour = tokens->at(start + 3);
				MetaToken * tokenFive = tokens->at(start + 4);
				MetaToken * tokenSix = tokens->at(start + 5);
				MetaToken * tokenSeven = tokens->at(start + 6);
				
				if(tokenOne->getType()->name == TOKEN_ID
					&& tokenTwo->getType()->name == TOKEN_OPEN_PARAN
					&& tokenThree->getType()->name == TOKEN_PARAMETER_DEFINITION_LIST
					&& tokenFour->getType()->name == TOKEN_CLOSE_PARAN
					&& tokenFive->getType()->name == TOKEN_OPEN_BRACE
					&& tokenSix->getType()->name == TOKEN_FUNCTION_STATEMENTS
					&& tokenSeven->getType()->name == TOKEN_CLOSE_BRACE)
				{
					std::vector<MetaToken *> * resultTokens = new std::vector<MetaToken *>();
					resultTokens->push_back(tokenOne);
					resultTokens->push_back(tokenTwo);
					resultTokens->push_back(tokenThree);
					resultTokens->push_back(tokenFour);
					resultTokens->push_back(tokenFive);
					resultTokens->push_back(tokenSix);
					resultTokens->push_back(tokenSeven);

					result = new MetaToken(new MetaTokenType(TOKEN_CONSTRUCTOR), resultTokens);
				}
			}
		}

		return result;
	}));

	return parser;
}