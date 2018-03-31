#include "includes.h"
#include "Map.h"
#include "BidirectionalSearch.h"

int main(){
	Map map;
	map.LoadNamesFromFile( "res/names.txt" );
	map.LoadLinksFromFile( "res/links.txt" );
	map.Search(0,18);

	return 0;
}
