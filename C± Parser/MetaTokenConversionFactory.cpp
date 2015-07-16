#include "MetaTokenConversionFactory.h"

MetaTokenConversionFactory::MetaTokenConversionFactory(void)
{
	this->metaTokenTypes->push_back(new MetaTokenType("OpenParan", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "OpenParan");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("CloseParan", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "CloseParan");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("OpenBracket", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "OpenBracket");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("CloseBracket", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "CloseBracket");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("OpenBrace", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "OpenBrace");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("CloseBrace", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "CloseBrace");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("class", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "class");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("function", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "function");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("for", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "for");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("while", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "while");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("new", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "new");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("if", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "if");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("else", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "else");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("in", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "in");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("null", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "null");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("super", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "super");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("this", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "this");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("return", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "return");
	}));
	
	this->metaTokenTypes->push_back(new MetaTokenType("import", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "import");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("partial", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "partial");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("Colon", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "Colon");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("SemiColon", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "SemiColon");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("PrimitiveType", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "PrimitiveType");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("PreUnaryOperator", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "PreUnaryOperator");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("PostUnaryOperator", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "PostUnaryOperator");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("BinaryOperator", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "BinaryOperator");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("AssignmentOperator", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "AssignmentOperator");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("BooleanLiteral", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "BooleanLiteral");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("StringLiteral", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "StringLiteral");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("IntLiteral", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "IntLiteral");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("CharLiteral", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "CharLiteral");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("ID", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "ID");
	}));

	this->metaTokenTypes->push_back(new MetaTokenType("DoubleLiteral", [](Token * token)
	{
		return checkIfTypeNameMatches(token, "DoubleLiteral");
	}));
}

Token * checkIfTypeNameMatches(Token * token, std::string name)
{
	Token * result = NULL;

	if(token->getType()->name == name)
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
	std::vector<MetaToken *> * metaTokens = new std::vector<MetaToken *>();

	for(int i = 0; i < tokens->size(); i ++)
	{
		MetaTokenType * type;
	}
}