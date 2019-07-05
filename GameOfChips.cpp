/*
	Author: Nidhi Bothra
	Create Date: 2019-07-03
	Description: Game Of Chips
				A command line based chip picking game. 
				This supports two modes: 
				1. Player vs Player
				2. Player vs Computer
				
				Come and try to win against the bot!!!!!
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cctype>
#include <algorithm>

using namespace std;

//		Structure
struct player {
	string name;
	int wins;
};

//		Declaring constants
const float MAX_TURN = 0.5;
const int MAX_CHIPS = 100;

//		Declaring functions
string findPlayerName(player[], bool);
void getUserNames(player[]);
int askMove(bool, int, player[], bool);
void addWins(player[], bool);

int main() {
	cout<<"Whoever takes last chip, wins!!\n\n";
	// 		Declaring variable
	bool player1Turn = true, gameOver = false, player1PlayedFirst = true;
	int chipsInPile = 0, chipsTaken = 0, maxPerTurn = 0, moveCounter = 0;
	player players[2];
	char userChoice;
	
	//		Output file variable
	ofstream outFile;
	outFile.open("WinnersList.txt", ios::app);
	
	//		Seeding the random number generator
	srand(time(0));
	
	//		Asking players for their names
	getUserNames(players);
	
	do {
		chipsInPile = (rand() % MAX_CHIPS) + 1;
		cout<<"\n\nThis round will start with "<<chipsInPile<<" chips in the pile.\n";
		gameOver = false;
		moveCounter = 0;
		player1PlayedFirst = player1Turn;
		while (gameOver == false) {
			chipsTaken = askMove(player1Turn, chipsInPile, players, player1PlayedFirst);
			chipsInPile = chipsInPile - chipsTaken;
			cout<<"\nThere are "<<chipsInPile<<" chips left in the pile.\n";
			moveCounter++;
			if (chipsInPile == 0) {
				gameOver = true;
				cout<<"\nCongratulations "<<findPlayerName(players, player1Turn)<<", you won.\n";
				outFile<<findPlayerName(players, player1Turn)<<" won in "<<moveCounter<<" moves.\n";
				addWins(players, player1Turn);
			} else {
				player1Turn = !player1Turn;
			}
		}
		cout<<"\nDo you wish play again? (Y/N): ";
		cin>>userChoice;
		userChoice = toupper(userChoice);
	} while (userChoice == 'Y');
	
	cout<<endl;
	cout<<players[0].name<<" won "<<players[0].wins<<" rounds.\n";
	cout<<players[1].name<<" won "<<players[1].wins<<" rounds.\n";
	
	outFile.close();
	
	return 0;
}


//		Defining functions
string findPlayerName(player players[], bool playerTurn) {
	if (playerTurn) {
		return players[0].name;
	} else {
		return players[1].name;
	}
}

void getUserNames(player players[]) {
	cout<<"Player 1, please enter your name: ";
	cin>>players[0].name;
	cout<<"Player 2, please enter your name.\n(If you wish to play against computer, enter \"Computer\"): ";
	cin>>players[1].name;
	cout<<"Thanks, good luck!!\n";
	transform(players[0].name.begin(), players[0].name.end(), players[0].name.begin(), ::toupper);
	transform(players[1].name.begin(), players[1].name.end(), players[1].name.begin(), ::toupper);
	players[0].wins = 0;
	players[1].wins = 0;
}

int askMove(bool playerTurn, int chipsInPile, player players[], bool player1PlayedFirst) {
	int chipsTaken, maxPerTurn = MAX_TURN * chipsInPile;
	do {
		cout<<findPlayerName(players, playerTurn)<<", you can take upto ";
		if (maxPerTurn == 0) {
			cout<<"1 chips.\n";
		} else {
			cout<<maxPerTurn<<" chips.\n";
		}
		if (findPlayerName(players, playerTurn) == "COMPUTER") {
			if (maxPerTurn == 0) {
				chipsTaken = 1;
			} else if (chipsInPile > 11) {
				do {
					if (maxPerTurn < chipsInPile-11) {
						chipsTaken = (rand() % maxPerTurn) + 1;
					} else {
						chipsTaken = (rand() % (chipsInPile-11)) + 1;
					}
				} while (chipsInPile - chipsTaken < 11);
			} else if (chipsInPile > 5 && chipsInPile < 11) {
				chipsTaken = chipsInPile - 5;
			} else if (chipsInPile == 4 || chipsInPile == 5) {
				chipsTaken = 2;
			} else {
				chipsTaken = (rand() % maxPerTurn) + 1;
			}
			
			cout<<"Chips taken by COMPUTER: "<<chipsTaken<<endl;
		}
		else {
			cout<<"How many chips would you like?: ";
			cin>>chipsTaken;
		}
		if (chipsTaken <= 0) {
			cout<<"Invalid chips entered.\n";
		}
	} while (((chipsTaken > maxPerTurn) && (chipsInPile > 1)) || chipsTaken <= 0);
	return chipsTaken;
}

void addWins(player players[], bool playerTurn) {
	if (playerTurn) {
		players[0].wins++;
	} else {
		players[1].wins++;
	}
}

