#pragma once
#include "MetaTokenType.h"

class ValueTokenType : MetaTokenType
{
public:
	ValueTokenType(void);
	virtual std::vector<MetaToken *> * containsMetaToken(std::vector<MetaToken *> *);
};

