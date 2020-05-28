#include "asset.h"

asset::asset(std::string id)
{
	_id = id;
}

asset::~asset()
{
}

std::string asset::id()
{
	return _id;
}
