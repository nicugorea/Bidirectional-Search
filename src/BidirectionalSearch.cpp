#include "BidirectionalSearch.h"



BidirectionalSearch::BidirectionalSearch()
{
}


BidirectionalSearch::~BidirectionalSearch()
{
}

std::vector<int> BidirectionalSearch::CreatePath( float ** _links, int _number, int _from, int _to, int& _inters,std::vector<std::string> cityNames )
{
	number = _number;
	//bfs

	Node* list = new Node[_number];
	for(int i = 0; i < _number; i++)
	{
		list[i].parentOfStart = -1;
		list[i].parentOfGoal = -1;
		list[i].id = i;
		list[i].lookingFromStart = false;
		list[i].lookingFromGoal = false;
		list[i].visitedByStart = false;
		list[i].visitedByGoal = false;
	}

	std::deque<Node> startQueue;
	std::deque<Node> goalQueue;
	
	startQueue.push_back( list[_from] );
	goalQueue.push_back( list[_to] );

	Node startCurrent;
	Node goalCurrent;

	while(!startQueue.empty()&&!goalQueue.empty())
	{
		startCurrent = startQueue.front();			  
		goalCurrent = goalQueue.front();

		list[startCurrent.id].visitedByStart = true;
		list[goalCurrent.id].visitedByGoal = true;

		if(intersection=Intersect( list ))
		{
			break;
		}

		for(int i = 0; i < _number; i++)
		{
			if(_links[startCurrent.id][i])
				if(!list[i].visitedByStart && !list[i].lookingFromStart)
				{
					list[i].lookingFromStart = true;
					list[i].parentOfStart = startCurrent.id;
					startQueue.push_back( list[i] );
				}

			if(_links[goalCurrent.id][i])
				if(!list[i].visitedByGoal && !list[i].lookingFromGoal)
				{
					list[i].lookingFromGoal = true;
					list[i].parentOfGoal = goalCurrent.id;
					goalQueue.push_back( list[i] );
				}

		}
		LOGLN( "\n\tOrase din start: " );
		for(int i = 0; i < startQueue.size(); i++)
		{
			LOG( cityNames[startQueue[i].id]<<" " );
		}

		LOGLN( "\n\tOrase din finis: " );
		for(int i = 0; i < goalQueue.size(); i++)
		{
			LOG( cityNames[goalQueue[i].id]<<" " );
		}
		LOGLN( "" );
		startQueue.pop_front();
		goalQueue.pop_front();



	}

	std::vector<int> startPath;
	std::vector<int> goalPath;


	while(1)
	{

		startPath.push_back( startCurrent.id );
		if(startCurrent.parentOfStart == -1) break;
		startCurrent = list[startCurrent.parentOfStart];

	}
	while(1)
	{

		goalPath.push_back( goalCurrent.id );
		if(goalCurrent.parentOfGoal == -1) break;
		goalCurrent = list[goalCurrent.parentOfGoal];

	}


	std::vector<int> path;
	
	for(int i = goalPath.size()-1; i >=0 ; i--)
	{
		path.push_back( goalPath[i] );
	}
	for(int i = 1; i < startPath.size(); i++)
	{
		path.push_back( startPath[i] );
	}
	

	_inters = intersection;
	return path;
}

int BidirectionalSearch::Intersect( Node* _list )
{
	for(int i = 0; i <number; i++)
	{
		if(_list[i].visitedByGoal && _list[i].visitedByStart)
			return _list[i].id;
	}
			 
			

	return 0;
}
