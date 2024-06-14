#pragma once
#include <string>
#include <vector>
using namespace std;
struct playersayings
{
	string saying;
	int nextsaying;
	int points = 0;
};
struct enemysaying 
{
	string saying;
	vector<playersayings> nextlines;
};

