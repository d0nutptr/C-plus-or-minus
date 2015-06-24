#include "CPMLexerFactory.h"

Lexer * CPMLexerFactory::generateCPMLexer(std::string file)
{
	Lexer * lexer = new Lexer((char*)file.c_str());

	lexer->addTokenType(new TokenType("OpenParan", [](std::string * source)
	{ 
		return checkSimpleStartingString(source, "(");
	}));

	lexer->addTokenType(new TokenType("CloseParan", [](std::string * source)
	{
		return checkSimpleStartingString(source, ")");
	}));

	lexer->addTokenType(new TokenType("OpenBracket", [](std::string * source)
	{
		return checkSimpleStartingString(source, "[");
	}));

	lexer->addTokenType(new TokenType("CloseBracket", [](std::string * source)
	{
		return checkSimpleStartingString(source, "]");
	}));

	lexer->addTokenType(new TokenType("OpenBrace", [](std::string * source)
	{
		return checkSimpleStartingString(source, "{");
	}));

	lexer->addTokenType(new TokenType("CloseBrace", [](std::string * source)
	{
		return checkSimpleStartingString(source, "}");
	}));

	lexer->addTokenType(new TokenType("class", [](std::string * source)
	{
		return checkSimpleStartingString(source, "class");
	}));

	lexer->addTokenType(new TokenType("function", [](std::string * source)
	{
		return checkSimpleStartingString(source, "function");
	}));

	lexer->addTokenType(new TokenType("for", [](std::string * source)
	{
		return checkSimpleStartingString(source, "for");
	}));

	lexer->addTokenType(new TokenType("while", [](std::string * source)
	{
		return checkSimpleStartingString(source, "while");
	}));

	lexer->addTokenType(new TokenType("new", [](std::string * source)
	{
		return checkSimpleStartingString(source, "new");
	}));

	lexer->addTokenType(new TokenType("if", [](std::string * source)
	{
		return checkSimpleStartingString(source, "if");
	}));

	lexer->addTokenType(new TokenType("else", [](std::string * source)
	{
		return checkSimpleStartingString(source, "else");
	}));

	lexer->addTokenType(new TokenType("in", [](std::string * source)
	{
		return checkSimpleStartingString(source, "in");
	}));

	lexer->addTokenType(new TokenType("null", [](std::string * source)
	{
		return checkSimpleStartingString(source, "null");
	}));

	lexer->addTokenType(new TokenType("super", [](std::string * source)
	{
		return checkSimpleStartingString(source, "super");
	}));

	lexer->addTokenType(new TokenType("this", [](std::string * source)
	{
		return checkSimpleStartingString(source, "this");
	}));

	lexer->addTokenType(new TokenType("return", [](std::string * source)
	{
		return checkSimpleStartingString(source, "return");
	}));

	lexer->addTokenType(new TokenType("import", [](std::string * source)
	{
		return checkSimpleStartingString(source, "import");
	}));

	lexer->addTokenType(new TokenType("partial", [](std::string * source)
	{
		return checkSimpleStartingString(source, "partial");
	}));

	lexer->addTokenType(new TokenType("Colon", [](std::string * source)
	{
		return checkSimpleStartingString(source, ":");
	}));

	lexer->addTokenType(new TokenType("SemiColon", [](std::string * source)
	{
		return checkSimpleStartingString(source, ";");
	}));

	lexer->addTokenType(new TokenType("PrimitiveType", [](std::string * source)
	{
		std::string * intString = checkSimpleStartingString(source, "int");
		std::string * doubleString = checkSimpleStartingString(source, "double");
		std::string * charString = checkSimpleStartingString(source, "char");
		std::string * booleanString = checkSimpleStartingString(source, "boolean");
		std::string * voidString = checkSimpleStartingString(source, "void");

		std::string * returnString = NULL;

		if(intString != NULL) returnString = intString;
		else if(doubleString != NULL) returnString = doubleString;
		else if(charString != NULL) returnString = charString;
		else if(booleanString != NULL) returnString = booleanString;
		else if(voidString != NULL) returnString = voidString;

		return returnString;
	}));

	lexer->addTokenType(new TokenType("PreUnaryOperator", [](std::string * source)
	{
		return checkSimpleStartingString(source, "!");
	}));

	lexer->addTokenType(new TokenType("PostUnaryOperator", [](std::string * source)
	{
		std::string * plusPlusString = checkSimpleStartingString(source, "++");
		std::string * minusMinusString = checkSimpleStartingString(source, "--");

		std::string * returnString = NULL;

		if(plusPlusString != NULL) returnString = plusPlusString;
		else if(minusMinusString != NULL) returnString = minusMinusString;

		return returnString;
	}));

	lexer->addTokenType(new TokenType("BinaryOperator", [](std::string * source)
	{
		std::string * plusString = checkSimpleStartingString(source, "+");
		std::string * minusString = checkSimpleStartingString(source, "-");
		std::string * divisionString = checkSimpleStartingString(source, "/");
		std::string * modulusString = checkSimpleStartingString(source, "%");
		std::string * powerString = checkSimpleStartingString(source, "**");
		std::string * multiplicationString = checkSimpleStartingString(source, "*");
		std::string * equalsString = checkSimpleStartingString(source, "==");
		std::string * greaterThanOrEqualsString = checkSimpleStartingString(source, ">=");
		std::string * greaterThan = checkSimpleStartingString(source, ">");
		std::string * lessThanOrEqualsString = checkSimpleStartingString(source, "<=");
		std::string * lessThanString = checkSimpleStartingString(source, "<");
		std::string * notEqualsString = checkSimpleStartingString(source, "!=");
		std::string * andString = checkSimpleStartingString(source, "&&");
		std::string * orString = checkSimpleStartingString(source, "||");
		std::string * instanceofString = checkSimpleStartingString(source, "instanceof");
		std::string * xorString = checkSimpleStartingString(source, "^");
		std::string * dotString = checkSimpleStartingString(source, ".");

		std::string * returnString = NULL;

		if(plusString != NULL) returnString = plusString;
		else if(minusString != NULL) returnString = minusString;
		else if(divisionString != NULL) returnString = divisionString;
		else if(modulusString != NULL) returnString = modulusString;
		else if(powerString != NULL) returnString = powerString;
		else if(multiplicationString != NULL) returnString = multiplicationString;
		else if(equalsString != NULL) returnString = equalsString;
		else if(greaterThanOrEqualsString != NULL) returnString = greaterThanOrEqualsString;
		else if(greaterThan != NULL) returnString = greaterThan;
		else if(lessThanOrEqualsString != NULL) returnString = lessThanOrEqualsString;
		else if(lessThanString != NULL) returnString = lessThanString;
		else if(notEqualsString != NULL) returnString = notEqualsString;
		else if(andString != NULL) returnString = andString;
		else if(orString != NULL) returnString = orString;
		else if(instanceofString != NULL) returnString = instanceofString;
		else if(xorString != NULL) returnString = xorString;
		else if(dotString != NULL) returnString = dotString;

		return returnString;
	}));

	lexer->addTokenType(new TokenType("AssignmentOperator", [](std::string * source)
	{
		return checkSimpleStartingString(source, "=");
	}));

	lexer->addTokenType(new TokenType("BooleanLiteral", [](std::string * source)
	{
		std::string * trueString = checkSimpleStartingString(source, "true");
		std::string * falseString = checkSimpleStartingString(source, "false");

		std::string * returnString = NULL;

		if(trueString != NULL) returnString = trueString;
		else if(falseString != NULL) returnString = falseString;

		return returnString;

	}));

	lexer->addTokenType(new TokenType("StringLiteral", [](std::string * source)
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

	lexer->addTokenType(new TokenType("IntLiteral", [](std::string * source)
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

	lexer->addTokenType(new TokenType("CharLiteral", [](std::string * source)
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

	lexer->addTokenType(new TokenType("ID", [](std::string * source)
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

	lexer->addTokenType(new TokenType("DoubleLiteral", [](std::string * source)
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