#include "Lexer.h"
#include "CPMLexerFactory.h"
#include "TokenType.h"
#include "MetaTokenConversionFactory.h"
#include "CPMParserFactory.h"
#include "ParseResult.h"
#include <iomanip>
#include <iostream>
#include <fstream>

void printMetaToken(MetaToken * token, ofstream * file, int indent);

int main()
{
	Lexer * lexer = CPMLexerFactory::generateCPMLexer("ExampleCPlusOrMinusFile.txt");
	std::vector<Token *> * tokens = new std::vector<Token *>();

	lexer->beginLexing(tokens);

	//print the tokens out for visualization
	for(unsigned int i = 0; i < tokens->size(); i ++)
	{
		std::printf("%-20s|%16s\r\n", (*tokens)[i]->getName()->c_str(), (*tokens)[i]->getType()->name->c_str());
	}

	std::vector<MetaToken *> * metaTokens = (new MetaTokenConversionFactory())->convertTokensToMetaTokens(tokens);
	Parser * parser = CPMParserFactory::generateCPMParser();

	ParseResult * result = parser->parse(metaTokens);

	if(result->isValid())
	{
		MetaToken * programToken = result->getValidResult();
		ofstream myFile;
		myFile.open("parserlog.txt");

		printMetaToken(programToken, &myFile, 0);
	}
	else
	{
		std::vector<MetaToken *> * badStuff = result->getInvalidSet();
	}

	std::string test;
	std::cin >> test;
}

void printMetaToken(MetaToken * token, ofstream * file, int indent)
{
	std::string * tab = new std::string();

	for(int i = 0; i < indent; i ++)
	{
		*tab += '\t';
	}

	*file << *tab << *token->getType()->name << "\n";

	if(token->getContents() != NULL)
	{
		for(int i = 0; i < token->getContents()->size(); i ++)
		{
			printMetaToken(token->getContents()->at(i), file, indent + 1);
		}
	}
}