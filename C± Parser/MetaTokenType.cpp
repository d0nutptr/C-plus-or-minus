#include "MetaTokenType.h"

MetaTokenType::MetaTokenType(std::string name, std::vector<MetaToken *> * (* containsMetaToken)(std::vector<MetaToken *> *))
{
	this->name = name;
	this->containsMetaToken = containsMetaToken;
}