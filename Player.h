#pragma once
#include "pch.h"
#include <iostream>
#include "Dice.h"


class Player
{
	class main;
public:
	int chips;
	int numPlayers;
	std::string name = "";
	Player() = default;
	void setName();
	static void setChips();
	static void directions();
};
