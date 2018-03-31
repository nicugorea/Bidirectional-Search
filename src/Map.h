#pragma once
#include "includes.h"


class Map
{
public:
	Map();
	~Map();

	bool LoadNamesFromFile( const char* _path );
	bool LoadLinksFromFile( const char* _path );
	bool Search(int _from , int _to);


private:
	std::vector<std::string> cityNames;
	float** cityLinks;
	int number;
};


