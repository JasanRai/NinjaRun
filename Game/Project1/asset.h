#pragma once

#include <string>

class asset
{
public :
	asset(std::string id);
	~asset();

	std::string id();

private:
	std::string _id;
	 
};

