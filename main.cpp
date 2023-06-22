#include <iostream>
using namespace std;

char grid[3][3] = {'1','2','3','4','5','6','7','8','9'};
char player = 'X';

void printGrid();
void play();
char decider();

int main() {
    while(decider() == '.'){
        printGrid();
        play();
    }
    printGrid();
    if(decider() == 'Z')
        cout << "\nNo Winner !!\n\n";
    else cout << "\nWinner Is Player (" << decider() << "), Congratulations!!\n\n";
    system("pause");
    return 0;
}

void printGrid(){
    system("cls");
    for (int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; j++){
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}
void play(){
    char pos;
    bool notFound = true;
    cout << "Enter A Position (" << player << ") : ";
    cin >> pos;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(grid[i][j] == pos) {
                grid[i][j] = player;
                notFound = false;
            }
        }
    }
    if(notFound){
        cout << "Already occupied, Try again!\n";
        play();
        return;
    }
    if(player == 'X') player = 'O';
    else player = 'X';
}
char decider(){
    int Xc, Oc, counter=0;
    for (int i = 0; i < 3; ++i) {
        Xc = 0, Oc = 0;
        for (int j = 0; j < 3; ++j) {
            if(grid[i][j] == 'X') Xc++;
            else if(grid[i][j] == 'O') Oc++;
            else counter++;
        }
        if(Xc == 3 || Oc == 3)
            return (Xc > Oc)? 'X':'O';
    }
    for (int i = 0; i < 3; ++i) {
        Xc = 0, Oc = 0;
        for (int j = 0; j < 3; ++j) {
            if(grid[j][i] == 'X') Xc++;
            else if(grid[j][i] == 'O') Oc++;
        }
        if(Xc == 3 || Oc == 3)
            return (Xc > Oc)? 'X':'O';
    }
    if( grid[1][1]=='X') {
        if (grid[0][0] == 'X' && grid[2][2] == 'X')
            return 'X';
        else if (grid[0][2] == 'X' && grid[2][0] == 'X')
            return 'X';
    }
    else if(grid[1][1]=='O'){
        if (grid[0][0] == 'O' && grid[2][2] == 'O')
            return 'O';
        else if (grid[0][2] == 'O' && grid[2][0] == 'O')
            return 'O';
    }
    if(counter == 0) return 'Z';
    return '.';
}
