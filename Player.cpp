#include "pch.h"
#include "Player.h"
#include "Dice.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void Player::setName()
{
	std::cin >> name;
}
void Player::setChips()
{
	int i;
	switch (Dice::rollDice()) // roll the dice
	{
	case 1:
		cout << endl << "You rolled <L> "; // subtract 1 chip from player and add one to left
		--players[i].chips;
		if (i = 2) {
			++players[--i].chips;
		}
		break;
	case 2:
		cout << endl << "You rolled <C> "; // subtract 1 chip from player
		if (i = 3)
		--players[i].chips;
		break;
	case 3:
		cout << endl << "You rolled <R> "; //subrtact 1 chip from player and give to right
		--players[i].chips;
		if (i = 2) {
			++players[++i].chips;
		}
		break;
	case 4:
		cout << endl << "You rolled <*> ";
		break; //do nothing
	case 5:
		cout << endl << "You rolled <*> ";
		break; // do nothing
	case 6:
		cout << endl << "You rolled <*> ";
		break; //do nothing
	}
}
void Player::directions() //display directions to player
{
	string line; // variable to hold line being read from txt file
	ifstream LCRRules("Rules.txt"); // open txt file
	if (LCRRules.is_open()) //start loop if file is opened
	{
		while (getline(LCRRules, line)) //read txt file line by line and store it in var line while there are lines to read
		{
			cout << line << '\n'; // print var line to screen
		}
		LCRRules.close(); // close txt file
	}
	else cout << "Unable to open file"; // catch error of not reading file
}
