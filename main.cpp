#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

struct FCharacter
{
	int X;
	int Y;
	char Shape;
};

FCharacter Characters[2];

int KeyCode;
bool bIsPlay;

void Init()
{
	//형변환, Casting
	srand((unsigned int)time(nullptr));
	Characters[0].X = 1;
	Characters[0].Y = 1;
	Characters[0].Shape = 'P';

	Characters[1].X = 10;
	Characters[1].Y = 10;
	Characters[1].Shape = 'M';

	bIsPlay = true;
}

void Input()
{
	KeyCode = _getch();
}

void MovePlayer()
{
	//디자인 패턴
	if (KeyCode == 'w')
	{
		if (Characters[0].Y > 0)
		{
			--Characters[0].Y;
		}
	}
	else if (KeyCode == 's')
	{
		++Characters[0].Y;
	}
	else if (KeyCode == 'a')
	{
		if (Characters[0].X > 0)
		{
			--Characters[0].X;
		}
	}
	else if (KeyCode == 'd')
	{
		++Characters[0].X;
	}
	else if (KeyCode == 'q')
	{
		bIsPlay = false;
	}
}

void MoveMonster()
{
	int Direction = rand() % 4;

	switch (Direction)
	{
	case 0:		//Up
		if (Characters[1].Y > 0)
		{
			--Characters[1].Y;
		}
		break;
	case 1:		//Down
		++Characters[1].Y;
		break;
	case 2:		//Left
		if (Characters[1].X > 0)
		{
			--Characters[1].X;
		}
		break;
	case 3:		//Right
		++Characters[1].X;
		break;
	default:	//Error
		break;
	}
}

void Tick()
{
	MovePlayer();
	MoveMonster();
}

void RenderCharacter(FCharacter InData)
{
	COORD Position;
	Position.X = (SHORT)InData.X;
	Position.Y = (SHORT)InData.Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
	cout << InData.Shape;
}

void Render()
{
	system("cls");
	for (int i = 0; i < 2; i++)
	{
		RenderCharacter(Characters[i]);
	}
}

int main()
{
	Init();

	while (bIsPlay)
	{	
		//Frame
		Input();
		Tick();
		Render();
	}

	return 0;
}