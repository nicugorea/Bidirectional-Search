#pragma once

#include "includes.h"

class BidirectionalSearch
{
public:
	BidirectionalSearch();
	~BidirectionalSearch();

	std::vector<int> CreatePath( float **_links, int _number, int _from, int _to, int& _inters,std::vector<std::string> cityNames );
	int Intersect( Node* _list );

private:
	int number = 0;
	int intersection = -1;
};

