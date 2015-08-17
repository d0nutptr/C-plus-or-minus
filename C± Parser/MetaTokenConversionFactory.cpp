#include "MetaTokenConversionFactory.h"
#include "TokenNames.h"

MetaTokenConversionFactory::MetaTokenConversionFactory(void)
{
	this->metaTokenTypes = new std::vector<MetaTokenType *>();

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_OPEN_PARAN, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_OPEN_PARAN);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_CLOSE_PARAN, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_CLOSE_PARAN);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_OPEN_BRACKET, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_OPEN_BRACKET);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_CLOSE_BRACKET, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_CLOSE_BRACKET);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_OPEN_BRACE, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_OPEN_BRACE);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_CLOSE_BRACE, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_CLOSE_BRACE);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_CLASS, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_CLASS);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_FUNCTION, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_FUNCTION);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_FOR, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_FOR);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_WHILE, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_WHILE);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_NEW, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_NEW);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_IF, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_IF);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_ELSE, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_ELSE);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_IN, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_IN);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_NULL, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_NULL);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_SUPER, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_SUPER);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_THIS, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_THIS);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_RETURN, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_RETURN);
	}));
	
	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_IMPORT, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_IMPORT);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_PARTIAL, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_PARTIAL);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_COLON, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_COLON);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_COMMA, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_COMMA);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_SEMI_COLON, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_SEMI_COLON);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_INT_TYPE, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_INT_TYPE);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_DOUBLE_TYPE, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_DOUBLE_TYPE);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_CHAR_TYPE, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_CHAR_TYPE);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_BOOLEAN_TYPE, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_BOOLEAN_TYPE);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_VOID_TYPE, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_VOID_TYPE);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_BANG, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_BANG);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_PLUSPLUS, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_PLUSPLUS);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_MINUSMINUS, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_MINUSMINUS);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_PLUS, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_PLUS);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_MINUS, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_MINUS);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_MULTIPLY, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_MULTIPLY);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_DIVIDE, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_DIVIDE);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_MOD, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_MOD);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_POWER, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_POWER);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_IS_EQUALS, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_IS_EQUALS);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_IS_GREATER_THAN_OR_EQUALS, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_IS_GREATER_THAN_OR_EQUALS);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_IS_GREATER_THAN, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_IS_GREATER_THAN);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_IS_LESS_THAN_OR_EQUALS, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_IS_LESS_THAN_OR_EQUALS);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_IS_LESS_THAN, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_IS_LESS_THAN);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_IS_NOT_EQUALS, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_IS_NOT_EQUALS);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_AND, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_AND);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_OR, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_OR);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_INSTANCEOF, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_INSTANCEOF);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_XOR, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_XOR);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_ACCESS_OPERATOR, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_ACCESS_OPERATOR);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_ASSIGNMENT_OPERATOR, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_ASSIGNMENT_OPERATOR);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_BOOLEAN_LITERAL, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_BOOLEAN_LITERAL);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_STRING_LITERAL, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_STRING_LITERAL);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_INT_LITERAL, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_INT_LITERAL);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_CHAR_LITERAL, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_CHAR_LITERAL);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_ID, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_ID);
	}));

	this->metaTokenTypes->push_back(new MetaTokenType(TOKEN_DOUBLE_LITERAL, [](Token * token)
	{
		return checkIfTypeNameMatches(token, TOKEN_DOUBLE_LITERAL);
	}));
}

/*
will return the token if the type matches the name given, otherwise NULL. This is horribly designed.
*/
Token * MetaTokenConversionFactory::checkIfTypeNameMatches(Token * token, const std::string * type)
{
	Token * result = NULL;

	if(*token->getType()->name == *type)
	{
		result = token;
	}

	return result;
}

/**
returns a vector of metatokens that are in the same order as the incoming tokens except converted to metatokens for the parser to understand
*/
std::vector<MetaToken *> * MetaTokenConversionFactory::convertTokensToMetaTokens(std::vector<Token *> * tokens)
{
	std::vector<MetaToken *> * translationList = new std::vector<MetaToken *>();

	//iterate tokens
	for(int i = 0; i < tokens->size(); i ++)
	{
		Token * currentToken = tokens->at(i);

		//iterate metaTokens for match
		for(int j = 0; j < metaTokenTypes->size(); j ++)
		{
			MetaTokenType * currentMetaTokenType = metaTokenTypes->at(j);

			if(currentToken == currentMetaTokenType->tryToTranslateTokenToMetaToken(currentToken))
			{
				translationList->push_back(new MetaToken(currentMetaTokenType, currentToken));
				break;
			}
		}
	}

	return translationList;
}