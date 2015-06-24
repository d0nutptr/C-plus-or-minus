#include "Lexer.h"
#include <iostream>
#include <fstream>

Lexer::Lexer(char * location)
{
	this->sourceLocation = location;

	char bufferChar;

	std::ifstream inputStream;
	inputStream.open(this->sourceLocation);

	if(inputStream.is_open())
	{
		while (inputStream.get(bufferChar))
		{
			source += bufferChar;
		}

		inputStream.close();
	}
}

void Lexer::addTokenType(TokenType * newToken)
{
	this->tokenTypes.push_back(newToken);
}

void Lexer::beginLexing(std::vector<Token *> * results)
{	
	//so we dont damage the original string
	std::string * lexableSource = new std::string(source);
	do
	{
		int indexOfToken = -1;
		unsigned int sizeOfToken = 0;

		//search the token types for the smallest, next match.
		//in the event of a tie (in size. ie 2 token types are 4 chars long in match) the one with the smallest index value wins
		for(unsigned int i = 0; i < tokenTypes.size(); i ++)
		{
			std::string * matchResults = tokenTypes[i]->isTypeOfToken(lexableSource);
			
			if(matchResults != NULL)
			{
				if(matchResults->size() > sizeOfToken)
				{
					indexOfToken = i;
					sizeOfToken = matchResults->size();
				}
				else if(matchResults->size() > 0 && matchResults->size() == sizeOfToken && i < indexOfToken)
				{
					indexOfToken = i;
				}
			}
		}

		if(indexOfToken >= 0)
		{
			std::string result = lexableSource->substr(0, sizeOfToken);
			* lexableSource = lexableSource->substr(sizeOfToken);
			(*results).push_back(new Token(result, tokenTypes[indexOfToken]));
		}
		else
		{
			* lexableSource = lexableSource->substr(1);
		}

	} while(lexableSource->size() > 0);
}