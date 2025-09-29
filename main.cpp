#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

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

	int PlayerInput = 0;
	bool bIsPlay = true;

	char MonsterShape = 'M';
	int MonsterX = 0;
	int MonsterY = 0;
	int MonsterMovement = 0;

	MonsterX = rand() % 10;
	MonsterY = rand() * rand() % 10;

	while (bIsPlay)
	{
		PlayerInput = _getch();

		if (PlayerInput == 'w')
		{
			--PlayerY;
		}
		else if (PlayerInput == 's')
		{
			++PlayerY;
		}
		else if (PlayerInput == 'a')
		{
			--PlayerX;
		}
		else if (PlayerInput == 'd')
		{
			++PlayerX;
		}
		else if (PlayerInput == 'q')
		{
			bIsPlay = false;
		}

		MonsterMovement = rand() % 4;

		if (MonsterMovement == 0)
		{
			--MonsterY;
		}
		else if (MonsterMovement == 1)
		{
			++MonsterY;
		}
		else if (MonsterMovement == 2)
		{
			--MonsterX;
		}
		else if (MonsterMovement == 3)
		{
			++MonsterX;
		}

		system("cls");
		SetPosition('P', PlayerX, PlayerY);
		SetPosition('M', MonsterX, MonsterY);
	}

	return 0;
}