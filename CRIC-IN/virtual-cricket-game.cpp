#include "game.h"
using namespace std;
int main()
{
  
	Game game;
	game.welcome(); 

	cout<<"\n Press enter to continue";
	getchar();
	

	game.showAllPlayers();
	cout<<"\nPress Enter to continue";
	getchar();
	game.selectPlayers();
	game.showTeamPlayers();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout<<"\nPress Enter to continue";
	getchar();
	game.toss();
	return 0;
}