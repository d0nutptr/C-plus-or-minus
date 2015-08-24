#include "Lexer.h"
#include "CPMLexerFactory.h"
#include "TokenType.h"
#include "MetaTokenConversionFactory.h"
#include "CPMParserFactory.h"
#include "ParseResult.h"
#include <iomanip>
#include <iostream>

int main()
{
	Lexer * lexer = CPMLexerFactory::generateCPMLexer("import_test.txt");
	std::vector<Token *> * tokens = new std::vector<Token *>();
	lexer->beginLexing(tokens);

	for(unsigned int i = 0; i < (*tokens).size(); i ++)
	{
		std::printf("%-20s|%16s\r\n", (*tokens)[i]->getName().c_str(), (*tokens)[i]->getType()->name->c_str());
	}

	std::vector<MetaToken *> * metaTokens = (new MetaTokenConversionFactory())->convertTokensToMetaTokens(tokens);
	Parser * parser = CPMParserFactory::generateCPMParser();

	ParseResult * result = parser->parse(metaTokens);

	if(result->isValid())
	{
		MetaToken * programToken = result->getValidResult();
	}
	else
	{
		std::vector<MetaToken *> * badStuff = result->getInvalidSet();
	}

	std::string test;
	std::cin >> test;
}
