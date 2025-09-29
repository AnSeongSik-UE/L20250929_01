#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main()
{
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

		system("cls");
		COORD pos = { PlayerX,PlayerY };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		cout << PlayerShape << endl;
	}

	return 0;
}