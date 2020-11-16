#include <iostream>
#include <time.h>
#include "GameManager.h"

int main()
{
	// TODO: Right now i am copying player and creating new varibles. I need to refrence the player instead
	// I need to reference player so I can actually change the value rather than changing it of a new copy
	// Going to need references in Fight, Team, and maybe GM but do not use for variables you are deleting
	// Such as eligible player.
	srand(time(NULL));

	GameManager gameManager = GameManager();
	int32_t roundCount = 0;

	while (!gameManager.IsGameOver())
	{
		if (roundCount == 16)
		{
			gameManager.SwitchSides();
		}
		gameManager.SimulateRound();
		gameManager.PrintScore();
		roundCount++;
	}
	

}