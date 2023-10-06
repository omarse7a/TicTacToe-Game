#include "Game.h"


void Game::drawGrid()
{
	system("cls");
	for (int i = 0; i < 3; i++) {
		cout << '\t';
		for (int j = 0; j < 3; j++) {
			cout << grid[i][j] << ' ';
		}
		cout << endl;
	}
}
void Game::play()
{
	cout << "Enter the position of player(" << player << ").. ";
	cin >> pos;
	found = false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (pos == grid[i][j]) {
				grid[i][j] = player;
				found = true;
			}
		}
	}
	if (!found) {
		cout << "Aready occupied or not found, Try again!\n";
		play();
		return;
	}
	if (player == 'X') player = 'O';
	else player = 'X';
}

char Game::decider()
{
	counter = 0;
	//Checking rows
	for (int i = 0; i < 3; i++) {
		Xc = Oc = 0;
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] == 'X') Xc++;
			else if (grid[i][j] == 'O') Oc++;
			else counter++;
		}
		if (Xc == 3 || Oc == 3)
			return (Xc > Oc) ? 'X' : 'O';
	}

	//Checking columns
	for (int i = 0; i < 3; i++) {
		Xc = Oc = 0;
		for (int j = 0; j < 3; j++) {
			if (grid[j][i] == 'X') Xc++;
			else if (grid[j][i] == 'O') Oc++;
		}
		if (Xc == 3 || Oc == 3)
			return (Xc > Oc) ? 'X' : 'O';
	}

	//Checking diagonals
	if (grid[1][1] == 'X')
	{
		if (grid[0][0] == 'X' && grid[2][2] == 'X') {
			return 'X';
		}
		else if(grid[0][2] == 'X' && grid[2][0] == 'X') {
			return 'X';
		}
	}
	else if (grid[1][1] == 'O')
	{
		if (grid[0][0] == 'O' && grid[2][2] == 'O') {
			return 'O';
		}
		else if (grid[0][2] == 'O' && grid[2][0] == 'O') {
			return 'O';
		}
	}

	//Checking if the grid is full
	if (counter == 0) return 'Z';
	return '.';
}
