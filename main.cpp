#include <iostream>
#include <time.h>
#include "GameManager.h"

int main()
{
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
		gameManager.PrintRoundStats();
		roundCount++;
	}

	
	gameManager.PrintScore();
	gameManager.PrintStats();

}