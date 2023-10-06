#pragma once
#include <iostream>
#include <string>
using namespace std;

class Game
{
private:
	char grid[3][3] = { {'1','2','3'}, {'4', '5', '6'}, {'7', '8', '9'} };
	char player = 'X';
	char pos;
	bool found;
	int Xc, Oc, counter;
public:
	void drawGrid();
	void play();
	char decider();
};

