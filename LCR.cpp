// LCR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>
#include "Dice.h"
#include "Player.h"

bool winner = false;
int totalChips = 0;
using namespace std;

int setPlayers() //get number of players, check if 3 or more
{
	int numOfPlayers = 0;
	cout << endl << "Please enter number of players: " << endl;
	cin >> numOfPlayers;
	if (numOfPlayers <= 2)
	{
		cout << "Must be 3 or more." << endl;
		setPlayers();
	}
	return numOfPlayers;
}

int main()
{
	// Display Game Rules
	Player::directions();
	// Get # of Players
	int currentPlayer = 0;
	srand((unsigned)time(NULL));
	const int numPlayers = setPlayers(); //set number of players
	static Player* players = new Player[numPlayers]; //set up array
	for (int i = 0; i < numPlayers; i++) //set names and chips for each player
	{
		cout << endl << "Enter player number " << (i + 1) << "'s name: " << endl;
		players[i].setName();
		players[i].chips = 3;
	}
	// start game
	cout << endl << "OK Let's play!" << endl;
	while (winner == false) {
		for (int i = 0; i < numPlayers; i++) {
			// check if player has chips. if NO CHIPS ++i and skip turn
			if (players[i].chips == 0) {
				cout << endl << "Sorry " << players[i].name << " you have no chips, you must skip this turn" << endl;
				++i;
			}
			cout << endl << players[i].name << " You have " << players[i].chips << " chips " << " press enter to roll the dice" << endl;
			std::cin.ignore(); //wait for keypress
			for (int j = 0; j < players[i].chips || j < 3; j++) { // player rolls dice up to 3 times or max chips
				Player::setChips(); // call setChips. roll dice & move chips
				cout << players[i].chips;
				// check for winner after each diceroll
				totalChips = 0; // reset chip counter
				for (int k = 0; k < numPlayers; k++) { //add all chips on table
					totalChips = totalChips + players[i].chips;
				}
				// check for winner
				if (totalChips - players[i].chips == 0) {
					cout << endl << "Congratulations " << players[i].name << " you win " << players[i].chips << " chips!";
					winner = true;
					return 0;
				}
			}
		}
	}
	return 0;
}
