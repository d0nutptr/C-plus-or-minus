
#pragma once
#include <vector>
#include "MetaToken.h"

class ParseResult
{
public:
	ParseResult(std::vector<MetaToken *> * a);
	ParseResult(MetaToken * a);
	bool isValid();
	MetaToken * getValidResult();
	std::vector<MetaToken *> * getInvalidSet();
private:
	std::vector<MetaToken *> * failedSet;
	MetaToken * validResult;
	bool valid;
	void reduceResultTree(MetaToken * parent);
};