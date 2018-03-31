#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <fstream>
#include <string>

typedef struct{
	int id;
	bool visitedByStart;
	bool visitedByGoal;
	bool lookingFromStart;
	bool lookingFromGoal;
	int parentOfStart;
	int parentOfGoal;

}Node;


#define LOG(info) std::cout<<info;
#define LOGLN(info) std::cout<<info<<'\n';