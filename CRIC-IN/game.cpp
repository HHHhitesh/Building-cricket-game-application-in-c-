#include "game.h"
using namespace std;
Game::Game(){
	playersPerTeam= 4;
	maxBalls = 6;
	totalPlayers= 11;

	players[0]="Virat";
	players[1]="Rohit";
	players[2]="Dhawan";
	players[3]="Pant";
	players[4]="Karthik";
	players[5]="KLRahul";
	players[6]="Jadeja";
	players[7]="Hardik";
	players[8]="Bumrah";
	players[9]="Bkumar";
	players[10]="Ishant";


 	isFirstInnings= false;
	teamA.name= "Team-A";
	teamB.name= "Team-B";
	}
void Game::welcome(){
	cout<<"-----------------------------------------------"<<endl;
	cout<<"|============== Instructions ================|"<<endl;
}

void game::showAllPlayers(){
	cout<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"|=========== pool of players ========="<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<endl;
	for(int i=0;i<totalPlayers;i++)
	{
	cout<<"\t\t["<<i<<"]"<<players[i]<<endl;
	}
}
int Game::takeIntegerInput(){
	int n;
	
	while(!(cin>>n)){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout<<"invalid input! Please try again with valid input: ";

	}
	return n;
}



bool Game::validateSelectedPlayer(int index){
	int n;
	vector<Player> players;
	players = teamA.players;
	n= players.size();
	for(int i=0;i<n;i++){
	if (player[i].id==index){
	return false;

	}}
	return true;


}



void Game::selectPlayers(){
	cout<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"========= Create Team-A and Team-B==========="<<endl;
	
	for (int i = 0;i<playersPerTeam;i++){
	
 // add player to team A
	teamASelection:
	
	cout<<endl<<"select player"<<i+1<<"of Team A -";
	int playerIndexTeamA = takeIntegerInput();
	
	if(playerIndexTeamA < 0 || playerIndexTeamA > 10){
	cout<<endl<<"please select from the given players"<<endl;
	goto teamASelection;}
	else if(!validateSelectedPlayer(playerIndexTeamA)){
	cout<<endl<<"Player has been already selected. Please select other player"<<endl;
	goto teamASelection;
	}	
	
	else{
	
	Player teamAPlayer;
	teamAPlayer.id=playerIndexTeamA;
	teamAPlayer.name = players[playerIndexTeamA];
	teamA.players.push_back(teamAPlayer);
	}
// add player to team B
	teamBSelection:
	cout<<endl<<"select player"<<i+1<<"of Team B -";
	int playerIndexTeamB = takeIntegerInput();
	
	if(playerIndexTeamB < 0 || playerIndexTeamB > 10){
	cout<<endl<<"please select from the given players"<<endl;
	goto teamBSelection;
	}else{
	
	Player teamBPlayer;  
	teamBPlayer.id=playerIndexTeamB;
	teamBPlayer.name = players[playerIndexTeamA];
	teamB.players.push_back(teamBPlayer);}
}

}

void Game::showTeamPlayers(){
	vector<Player> teamAPlayers = teamA.players;
	vector<Player> teamBPlayers = teamB.players;
	cout<<endl<<endl;
	for (int i=0;i<playersPerTeam; i++){
	cout<<"|\t"<<"["<<i<<"]"<<teamAPlayers[i].name<<"\t|"<<"\t\t"
<<"|\t"<<"["<<i<<"]"<<teamBPlayers[i].name<<"\t|"<<endl;
}
cout<<"--------------------------------\t\t------------------------"<<endl<<endl;
}


void Game::toss(){
	cout<<endl;
	cout<<"==================================="<<endl;
	cout<<"|=========lets toss=========|"<<endl;
	cout<<"tossing the coin..."<<endl<<endl;
	
	
	srand(tine(NULL));
	int randomValue = rand()%2;
	
	switch(randomValue){
	case 0:
		cout<<"Team-A won the toss"<<endl<<endl;
		tossChoice(teamA);
		break;
	case 1:
		cout<<"Team-B won the toss"<<endl<<endl;
		tossChoice(teamB);
		break;
	}
}
void Game::tossChoice(Team tossWinnerTeam){
	cout<<"enter 1 to bat or 2 to bowl first."<<endl<<"1. Bat"<<endl<<"2. Bowl" <<endl;
	int tossInput= takeIntegerInput();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	switch(tossInput){
	case 1:
		cout<<endl<<tossWinnerTeam.name<<"won the toss and elected to bat first"<<endl<<endl;
		if(tossWinnerTeam.name.compare("Team-A")==0){
			battingTeam = &teamA;
			bowlingTeam = &teamB;}
		else{
			battingTeam =&teamB;
			bowlingTeam = &teamA;}
		break;
	case 2:
		cout<<endl<<tossWinnerTeam.name<<"won the toss and elected to bowl first"<<endl<<endl;
		break;
	default;
		cout<<endl<<"Invalid input.Please try again:"<<endl<<endl;
		tossChoice(tossWinnerTeam);
		break;
		
	}
}

void Game::startFirstInnings(){
	cout<<"\t\t |||FIRST INNINGS STARTS|||"<<endl<<endl;
	
	isFirstInnings = true;
	
	initializePlayers();
	playInnings();
}

void Game::initializePlayers(){
		batsman = &battingTeam->players[0];
		bowler = &bowlingTeam->players[0];
}
 void Game::playInnings(){
	for (int i=0;i<maxBalls;i++){
	cout<<"Press enter to bowl...";
	getchar();
	cout<<"bowling... "<<endl;
	bat();
	if(!validateInningsScore()){
	break;
	}
	}
}

void Game::bat(){
	srand(tine(NULL));
	int runsScored=rand()%7;
	batsman->runScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed +1;

	bowler->ballsBowled = bowler->ballsBowled +1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled +1;
	bowler->runsGiven = bowler->runsGiven + runsScored;
	
	
	if (runsScored !=0)	{
	cout<<endl<<bowler->name<<"to"<<batsman->name<<" "<<runsScored<<" runs!"<<endl<<endl;
	
	}
	else{
cout<<endl<<bowler->name<<"to"<<batsman->name<<" "<<runsScored<<" runs!"<<endl<<endl;
	battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
	bowler->wicketsTaken = bowler->wicketsTaken +1; 
	int nextPlayerIndex = battingTeam->wicketLost;
	batsman = &battingTeam->players[nextPlayerIndex];
	}
}

bool Game::validateInningsScore(){
	if (isFirstInnings){
	if(battingTeam->wicketLost==playersPerTeam || bowlingTeam->totalBallsBowled==maxBalls){
	cout<<"\t\t||| first Innings Ends|||" << endl<< endl;
	cout<< battingTeam->name<<" "<<battingTeam->totalRunsScored<<"-"
		<<battingTeam->wicketLost<<"{"<<bowlingTeam->totalBallsBowled
		<<"}"<<endl;
	cout<<bowlingTeam->name<<" needs" << battingTeam->totalRunsScored +1
		<<"runs to win the match"<<endl<<endl;
	
		
	return false;
	}
else{}
	
return true;
	}

void Game::showGameScorecard(){
	cout<<"-------------------------------------------------------------"<<endl;
cout<<"\t"<<battingTeam->name<<" "<<battingTeam->totalRunsScored <<"-"
<<battingTeam->wicketsLost<<"{"<<bowlingTeam->totalBallsBowled<<"} \t"<<bowler-name<<
" "<< bowler->ballsBowled<<"-"<<bowler->runsGiven<<"-"<<bowler->wicketsTaken<<"\t"<<endl;
cout<<"------------------------------------------------------------"<<endl<<endl;

}

















