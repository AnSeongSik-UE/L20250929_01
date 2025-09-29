#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

bool Input(int *PlayerX, int *PlayerY)
{
	int PlayerInput = _getch();

	if (PlayerInput == 'w')
	{
		if (*PlayerY > 0)
		{
			--*PlayerY;
		}
	}
	else if (PlayerInput == 's')
	{
		++*PlayerY;
	}
	else if (PlayerInput == 'a')
	{
		if (*PlayerX > 0)
		{
			--*PlayerX;
		}
	}
	else if (PlayerInput == 'd')
	{
		++*PlayerX;
	}
	else if (PlayerInput == 'q')
	{
		return false;
	}

	return true;
}

void ProcessMonsterMovement(int *MonsterX, int *MonsterY)
{
	int MonsterMovement = rand() % 4;

	if (MonsterMovement == 0)
	{
		if (*MonsterY > 0)
		{
			--*MonsterY;
		}
	}
	else if (MonsterMovement == 1)
	{
		++*MonsterY;
	}
	else if (MonsterMovement == 2)
	{
		if (*MonsterX > 0)
		{
			--*MonsterX;
		}
	}
	else if (MonsterMovement == 3)
	{
		++*MonsterX;
	}
}

void SetPosition(char Shape, int X, int Y)
{
	COORD MonsterPosition = { X, Y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), MonsterPosition);
	std::cout << Shape << endl;
}

int main()
{
	// ·£´ý ½Ãµå
	srand(time(nullptr));

	int Map[10][10] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	char PlayerShape = 'P';
	int PlayerX = 0;
	int PlayerY = 0;

	bool bIsPlay = true;

	char MonsterShape = 'M';
	int MonsterX = 0;
	int MonsterY = 0;

	MonsterX = rand() % 10;
	MonsterY = rand() * rand() % 10;

	while (bIsPlay)
	{
		bIsPlay = Input(&PlayerX, &PlayerY);

		ProcessMonsterMovement(&MonsterX, &MonsterY);

		system("cls");

		SetPosition('P', PlayerX, PlayerY);
		SetPosition('M', MonsterX, MonsterY);
	}

	return 0;
}