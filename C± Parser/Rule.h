#pragma once
#include "TokenNames.h"
#include <vector>

class Rule
{
public:
	Rule(std::string * name);

	std::string * name;
	std::vector<std::string *> * tokens;

	void addToken(std::string * token);
};

