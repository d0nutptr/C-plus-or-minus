#include "Lexer.h"
#include "CPMLexerFactory.h"
#include "TokenType.h"
#include <iomanip>
#include <iostream>

int main()
{
	Lexer * lexer = CPMLexerFactory::generateCPMLexer("test.txt");
	std::vector<Token *> * tokens = new std::vector<Token *>();
	lexer->beginLexing(tokens);

	for(unsigned int i = 0; i < (*tokens).size(); i ++)
	{
		std::cout << (*tokens)[i]->getName() << " - " << (*tokens)[i]->getType()->name << "\r\n";
	}

	std::string test;
	std::cin >> test;
}
