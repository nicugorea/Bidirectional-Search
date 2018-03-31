#include "Map.h"
#include "BidirectionalSearch.h"



Map::Map()
{
}


Map::~Map()
{
	for(int i = 0; i < number; i++)
	{
		delete[]( cityLinks[i] );
	}
	delete[]( cityLinks );
}


bool Map::LoadNamesFromFile( const char* _path )
{
	std::ifstream input( _path );
	if(!input.is_open()) return false;
	while(!input.eof())
	{
		std::string tmp;
		input >> tmp;
		cityNames.push_back(tmp);
	}
	input.close();
	number = cityNames.size();
}

bool Map::LoadLinksFromFile( const char* _path )
{
	cityLinks = new float* [number];
	for(int i = 0; i < number; i++)
	{
		cityLinks[i] = new float[number];
	}

	std::ifstream input( _path );
	if(!input.is_open()) return false;
	for(int i = 0; i < number; i++)
	{
		for(int j = 0; j < number; j++)
		{
			input >> cityLinks[i][j];
		}
	}
	input.close();
}

bool Map::Search( int _from, int _to )
{
	int n;
	BidirectionalSearch search;
	std::vector<int> path=search.CreatePath( cityLinks, number, _from, _to, n , cityNames);

	LOGLN( "\n\tDrumul gasit este: " );

	for(int i = path.size()-1;i>=0; i--)
	{
		LOG( cityNames[path[i]]<<"  " );
	}
	LOGLN( "\nDrumurile se intersecteaza in orasul : "<<cityNames[n] );
	
	
	
	return true;
}
