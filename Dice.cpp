#include "pch.h"
#include "Dice.h"
#include "Player.h"
#include <time.h>
#include <iostream>

int Dice::rollDice()
{
	return 1 + rand() % 6;
}
