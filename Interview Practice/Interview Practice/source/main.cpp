#include <stdlib.h>
#include <iostream>
using namespace std;

//Variable Declarations
int players[20];
int startingPlayers[20];
int tournament[38][20];

//Function Declarations
void ShiftPlayers();
void GenerateTournament();
void OutputMatches(int round);

//Function Definitions
int main()
{
	GenerateTournament();

	return 0;
}

void ShiftPlayers()
{
	int temp;
	int firstValue = players[0];
	for (int i = 0; i < 19; i++)
	{
		if (i == 0)
		{
			temp = players[i];
			players[i] = players[19];
		}
		else
		{
			players[i + 1] = players[i];
		}
	}
}

void GenerateTournament()
{
	for (int i = 1; i <= 20; i++)
	{
		players[i] = i + 1;
	}

	for (int i = 1; i <= 38; i++)
	{
		cout << "Round[" << i << "]------------------------------------------" << endl;
		if (i > 1)
		{
			ShiftPlayers();
		}
		OutputMatches(i);
	}
}

void OutputMatches(int round)
{
	int matchCounter = 1;
	for (int n = 1; n <= 20; n++)
	{
		if (n % 2 != 0)
		{
			cout << "Match[" << matchCounter << "]:";
		}
		cout << players[n] << ",";
		if (n % 2 == 0)
		{
			cout << endl;
			matchCounter++;
		}
	}
}