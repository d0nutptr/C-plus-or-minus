#include "CPMLexerFactory.h"
#include "TokenNames.h"

Lexer * CPMLexerFactory::generateCPMLexer(std::string file)
{
	Lexer * lexer = new Lexer((char*)file.c_str());

	lexer->addTokenType(new TokenType(TOKEN_OPEN_PARAN, [](std::string * source)
	{ 
		return checkSimpleStartingString(source, "(");
	}));

	lexer->addTokenType(new TokenType(TOKEN_CLOSE_PARAN, [](std::string * source)
	{
		return checkSimpleStartingString(source, ")");
	}));

	lexer->addTokenType(new TokenType(TOKEN_OPEN_BRACE, [](std::string * source)
	{
		return checkSimpleStartingString(source, "[");
	}));

	lexer->addTokenType(new TokenType(TOKEN_CLOSE_BRACE, [](std::string * source)
	{
		return checkSimpleStartingString(source, "]");
	}));

	lexer->addTokenType(new TokenType(TOKEN_OPEN_BRACKET, [](std::string * source)
	{
		return checkSimpleStartingString(source, "{");
	}));

	lexer->addTokenType(new TokenType(TOKEN_CLOSE_BRACKET, [](std::string * source)
	{
		return checkSimpleStartingString(source, "}");
	}));

	lexer->addTokenType(new TokenType(TOKEN_CLASS, [](std::string * source)
	{
		return checkSimpleStartingString(source, "class");
	}));

	lexer->addTokenType(new TokenType(TOKEN_FUNCTION, [](std::string * source)
	{
		return checkSimpleStartingString(source, "function");
	}));

	lexer->addTokenType(new TokenType(TOKEN_FOR, [](std::string * source)
	{
		return checkSimpleStartingString(source, "for");
	}));

	lexer->addTokenType(new TokenType(TOKEN_WHILE, [](std::string * source)
	{
		return checkSimpleStartingString(source, "while");
	}));

	lexer->addTokenType(new TokenType(TOKEN_NEW, [](std::string * source)
	{
		return checkSimpleStartingString(source, "new");
	}));

	lexer->addTokenType(new TokenType(TOKEN_IF, [](std::string * source)
	{
		return checkSimpleStartingString(source, "if");
	}));

	lexer->addTokenType(new TokenType(TOKEN_ELSE, [](std::string * source)
	{
		return checkSimpleStartingString(source, "else");
	}));

	lexer->addTokenType(new TokenType(TOKEN_IN, [](std::string * source)
	{
		return checkSimpleStartingString(source, "in");
	}));

	lexer->addTokenType(new TokenType(TOKEN_NULL, [](std::string * source)
	{
		return checkSimpleStartingString(source, "null");
	}));

	lexer->addTokenType(new TokenType(TOKEN_SUPER, [](std::string * source)
	{
		return checkSimpleStartingString(source, "super");
	}));

	lexer->addTokenType(new TokenType(TOKEN_THIS, [](std::string * source)
	{
		return checkSimpleStartingString(source, "this");
	}));

	lexer->addTokenType(new TokenType(TOKEN_RETURN, [](std::string * source)
	{
		return checkSimpleStartingString(source, "return");
	}));

	lexer->addTokenType(new TokenType(TOKEN_IMPORT, [](std::string * source)
	{
		return checkSimpleStartingString(source, "import");
	}));

	lexer->addTokenType(new TokenType(TOKEN_PARTIAL, [](std::string * source)
	{
		return checkSimpleStartingString(source, "partial");
	}));

	lexer->addTokenType(new TokenType(TOKEN_COLON, [](std::string * source)
	{
		return checkSimpleStartingString(source, ":");
	}));

	lexer->addTokenType(new TokenType(TOKEN_COMMA, [](std::string * source)
	{
		return checkSimpleStartingString(source, ",");
	}));

	lexer->addTokenType(new TokenType(TOKEN_SEMI_COLON, [](std::string * source)
	{
		return checkSimpleStartingString(source, ";");
	}));

	lexer->addTokenType(new TokenType(TOKEN_INT_TYPE, [](std::string * source)
	{
		return checkSimpleStartingString(source, "int");
	}));

	lexer->addTokenType(new TokenType(TOKEN_DOUBLE_TYPE, [](std::string * source)
	{
		return checkSimpleStartingString(source, "double");
	}));

	lexer->addTokenType(new TokenType(TOKEN_CHAR_TYPE, [](std::string * source)
	{
		return checkSimpleStartingString(source, "char");
	}));

	lexer->addTokenType(new TokenType(TOKEN_BOOLEAN_TYPE, [](std::string * source)
	{
		return checkSimpleStartingString(source, "boolean");
	}));

	lexer->addTokenType(new TokenType(TOKEN_VOID_TYPE, [](std::string * source)
	{
		return checkSimpleStartingString(source, "void");
	}));

	lexer->addTokenType(new TokenType(TOKEN_BANG, [](std::string * source)
	{
		return checkSimpleStartingString(source, "!");
	}));

	lexer->addTokenType(new TokenType(TOKEN_PLUSPLUS, [](std::string * source)
	{
		return checkSimpleStartingString(source, "++");
	}));

	lexer->addTokenType(new TokenType(TOKEN_MINUSMINUS, [](std::string * source)
	{
		return checkSimpleStartingString(source, "--");
	}));

	lexer->addTokenType(new TokenType(TOKEN_PLUS, [](std::string * source)
	{
		return checkSimpleStartingString(source, "+");
	}));

	lexer->addTokenType(new TokenType(TOKEN_MINUS, [](std::string * source)
	{
		return checkSimpleStartingString(source, "-");
	}));

	lexer->addTokenType(new TokenType(TOKEN_MULTIPLY, [](std::string * source)
	{
		return checkSimpleStartingString(source, "*");
	}));

	lexer->addTokenType(new TokenType(TOKEN_DIVIDE, [](std::string * source)
	{
		return checkSimpleStartingString(source, "/");
	}));

	lexer->addTokenType(new TokenType(TOKEN_MOD, [](std::string * source)
	{
		return checkSimpleStartingString(source, "%");
	}));

	lexer->addTokenType(new TokenType(TOKEN_POWER, [](std::string * source)
	{
		return checkSimpleStartingString(source, "**");
	}));

	lexer->addTokenType(new TokenType(TOKEN_IS_EQUALS, [](std::string * source)
	{
		return checkSimpleStartingString(source, "==");
	}));

	lexer->addTokenType(new TokenType(TOKEN_IS_GREATER_THAN_OR_EQUALS, [](std::string * source)
	{
		return checkSimpleStartingString(source, ">=");
	}));

	lexer->addTokenType(new TokenType(TOKEN_IS_GREATER_THAN, [](std::string * source)
	{
		return checkSimpleStartingString(source, ">");
	}));

	lexer->addTokenType(new TokenType(TOKEN_IS_LESS_THAN_OR_EQUALS, [](std::string * source)
	{
		return checkSimpleStartingString(source, "<=");
	}));

	lexer->addTokenType(new TokenType(TOKEN_IS_LESS_THAN, [](std::string * source)
	{
		return checkSimpleStartingString(source, "<");
	}));

	lexer->addTokenType(new TokenType(TOKEN_IS_NOT_EQUALS, [](std::string * source)
	{
		return checkSimpleStartingString(source, "!=");
	}));

	lexer->addTokenType(new TokenType(TOKEN_AND, [](std::string * source)
	{
		return checkSimpleStartingString(source, "&&");
	}));

	lexer->addTokenType(new TokenType(TOKEN_OR, [](std::string * source)
	{
		return checkSimpleStartingString(source, "||");
	}));

	lexer->addTokenType(new TokenType(TOKEN_INSTANCEOF, [](std::string * source)
	{
		return checkSimpleStartingString(source, "instanceof");
	}));

	lexer->addTokenType(new TokenType(TOKEN_XOR, [](std::string * source)
	{
		return checkSimpleStartingString(source, "^");
	}));

	lexer->addTokenType(new TokenType(TOKEN_ACCESS_OPERATOR, [](std::string * source)
	{
		return checkSimpleStartingString(source, ".");
	}));

	lexer->addTokenType(new TokenType(TOKEN_ASSIGNMENT_OPERATOR, [](std::string * source)
	{
		return checkSimpleStartingString(source, "=");
	}));

	lexer->addTokenType(new TokenType(TOKEN_QUESTION, [](std::string * source)
	{
		return checkSimpleStartingString(source, "?");
	}));

	lexer->addTokenType(new TokenType(TOKEN_BOOLEAN_LITERAL, [](std::string * source)
	{
		std::string * trueString = checkSimpleStartingString(source, "true");
		std::string * falseString = checkSimpleStartingString(source, "false");

		std::string * returnString = NULL;

		if(trueString != NULL) returnString = trueString;
		else if(falseString != NULL) returnString = falseString;

		return returnString;

	}));

	lexer->addTokenType(new TokenType(TOKEN_STRING_LITERAL, [](std::string * source)
	{
		std::string * returnString = NULL;

		unsigned int length = 0;
		bool closedString = false;

		if((*source)[0] == '"')
		{
			length ++;

			while (length <= source->size())
			{
				if((*source)[length] == '"')
				{
					length ++;
					closedString = true;
					break;
				}
				else if((*source)[length] == '\\')
				{
					// assume that the next character is valid no matter what
					length ++;
				}

				length ++;
			}

			if(closedString)
			{
				returnString = new std::string(((*source).substr(0, length)));
			}
		}

		return returnString;
	}));

	lexer->addTokenType(new TokenType(TOKEN_INT_LITERAL, [](std::string * source)
	{
		std::string * returnString = NULL;
		unsigned int length = 0;

		if(isANumber((char)(*source)[0]))
		{
			while(length < source->length() && isANumber((char)(*source)[length]))
			{
				length ++;
			}

			returnString = new std::string(source->substr(0, length));
		}

		return returnString;
	}));

	lexer->addTokenType(new TokenType(TOKEN_CHAR_LITERAL, [](std::string * source)
	{
		std::string * returnString = NULL;

		if(((char)(*source)[0]) == '\'')
		{
			if((char)(*source)[1] != '\'')
			{
				if((char)(*source)[1] == '\\')
				{
					if((char)(*source)[3] == '\'')
					{
						//valid
						returnString = new std::string(source->substr(0, 4));
					}
					else
					{
						//invalid
					}
				}
				else if((char)(*source)[2] == '\'')
				{
					//valid
					returnString = new std::string(source->substr(0, 3));
				}
				else
				{
					//invalid
				}
			}
			else
			{
				//invalid
			}
		}

		return returnString;
	}));

	lexer->addTokenType(new TokenType(TOKEN_ID, [](std::string * source)
	{
		std::string * returnString = NULL;
		unsigned int length = 0;

		if(isAValidIDCharacter((char)(*source)[0], false))
		{
			while(length < source->size() && isAValidIDCharacter((char)(*source)[length], true))
			{
				length ++;
			}

			returnString = new std::string(source->substr(0, length));
		}

		return returnString;
	}));

	lexer->addTokenType(new TokenType(TOKEN_DOUBLE_LITERAL, [](std::string * source)
	{
		std::string * returnString = NULL;
		unsigned int length = 0;

		if(isANumber((char)(*source)[0]))
		{
			while(length < source->size() && isANumber((char)(*source)[length]))
			{
				length ++;
			}

			if(length < source->size() && (char)(*source)[length] == '.')
			{
				length ++;
			}
			
			while(length < source->size() && isANumber((char)(*source)[length]))
			{
				length ++;
			}

			returnString = new std::string(source->substr(0, length));
		}

		return returnString;
	}));

	return lexer;
}

/**
* checks to see if the start of *source matches *str
* returns a result string pointer if a match was found, otherwise NULL
*/
std::string * CPMLexerFactory::checkSimpleStartingString(std::string * source, std::string str)
{
	bool isMatch = true;
	std::string * matchResults = NULL;

	if(source->size() >= str.size())
	{
		for(unsigned int i = 0; i < str.size(); i ++)
		{
			if(((char)(*source)[i]) != ((char)str[i]))
			{
				isMatch = false;
				break;
			}
		}

		if(isMatch)
		{
			matchResults = new std::string(str);
		}
	}

	return matchResults;
}

bool CPMLexerFactory::isANumber(char character)
{
	return character == '0'
		|| character == '1'
		|| character == '2'
		|| character == '3'
		|| character == '4'
		|| character == '5'
		|| character == '6'
		|| character == '7'
		|| character == '8'
		|| character == '9';
}

bool CPMLexerFactory::isAValidIDCharacter(char character, bool acceptNum)
{
	return (character <= 90 && character >= 65)
		|| (character == 95)
		|| (character <= 122 && character >= 97)
		|| (acceptNum && isANumber(character));
}