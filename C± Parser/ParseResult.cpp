#include "ParseResult.h"
#include "MetaTokenType.h"

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

/**
* return the automatically reduced AST from the valid result.
* TODO: recursive method still needed
*/
MetaToken * ParseResult::getValidResult()
{
	reduceResultTree(validResult);
	return validResult;
}

std::vector<MetaToken *> * ParseResult::getInvalidSet()
{
	return failedSet;
}

void ParseResult::reduceResultTree(MetaToken * parent)
{
	//return vector of contents
	for(int i = 0; i < parent->getContents()->size(); i ++)
	{
		MetaToken * child = parent->getContents()->at(i);

		//if the child has any children then we need to reduce the tree
		if(!child->isLeaf())
		{
			reduceResultTree(child);
		}

		//if the child and parent are the same, return the contents
		if(*child->getType()->name == *parent->getType()->name)
		{
			//remove the old token
			parent->getContents()->erase(parent->getContents()->begin() + i);

			//insert each content element starting from the last element to the first to insert the new items
			for(int j = 0; j < child->getContents()->size(); j ++)
			{
				parent->getContents()->insert(parent->getContents()->begin() + i,
					child->getContents()->at(child->getContents()->size() - j - 1));
			}
		}
	}
}