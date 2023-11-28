#include <iostream>
#include <Windows.h>
#include "Game.h"
using namespace std;

int main()
{
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, 2);
	Game g;
	while (g.decider() == '.')
	{
		g.drawGrid();
		g.play();
	}
	g.drawGrid();
	if (g.decider() == 'Z')
		cout << "\nNo Winner !!\n\n";
	else cout << "\nWinner Is Player (" << g.decider() << "), Congratulations!!\n\n";
	system("pause");
	return 0;
}
