#include "MetaTokenConversionFactory.h"

MetaTokenConversionFactory::MetaTokenConversionFactory(void){}

/**
returns a vector of metatokens that are in the same order as the incoming tokens except converted to metatokens for the parser to understand
*/
std::vector<MetaToken *> * MetaTokenConversionFactory::convertTokensToMetaTokens(std::vector<Token *> * tokens)
{
	std::vector<MetaToken *> * metaTokens = new std::vector<MetaToken *>();

	for(int i = 0; i < tokens->size(); i ++)
	{
		MetaTokenType * type;
	}
}