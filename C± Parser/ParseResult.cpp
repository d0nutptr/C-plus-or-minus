#include "ParseResult.h"

ParseResult::ParseResult(std::vector<MetaToken *> * invalidSet)
{
	this->valid = false;
	this->failedSet = invalidSet;
	this->validResult = NULL;
}

ParseResult::ParseResult(MetaToken * result)
{
	this->valid = true;
	this->failedSet = NULL;
	this->validResult = result;
}

bool ParseResult::isValid()
{
	return valid;
}

MetaToken * ParseResult::getValidResult()
{
	return validResult;
}

std::vector<MetaToken *> * ParseResult::getInvalidSet()
{
	return failedSet;
}