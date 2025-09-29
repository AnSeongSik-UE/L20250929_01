#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int CurrentBufferIndex = 0;
HANDLE ScreenBuffers[2];

struct FCharacter
{
	int X;
	int Y;
	string Shape;
};

FCharacter Characters[2];

int KeyCode;
bool bIsPlay;

void Init()
{
	// 0, nullptr, NULL 전부 0
	ScreenBuffers[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenBuffers[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, NULL);

	//형변환, Casting
	srand((unsigned int)time(nullptr));
	Characters[0].X = 1;
	Characters[0].Y = 1;
	Characters[0].Shape = "P";

	Characters[1].X = 10;
	Characters[1].Y = 10;
	Characters[1].Shape = "M";

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

void Present()
{
	SetConsoleActiveScreenBuffer(ScreenBuffers[CurrentBufferIndex]);

	++CurrentBufferIndex;
	CurrentBufferIndex = CurrentBufferIndex % 2;
}

//C++
void RenderCharacter(const FCharacter* InData)
{
	COORD Position;
	Position.X = (SHORT)InData->X;
	Position.Y = (SHORT)InData->Y;
	//Position.Y = (SHORT)(*(InData).Y);
	
	SetConsoleCursorPosition(ScreenBuffers[CurrentBufferIndex], Position);
	WriteConsole(ScreenBuffers[CurrentBufferIndex], InData->Shape.c_str(), 1, NULL, NULL);

}

void Clear()
{
	COORD coordScreen = { 0, 0 };    // home for the cursor
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	//스크린 버퍼 정보 가져오기
	GetConsoleScreenBufferInfo(ScreenBuffers[CurrentBufferIndex], &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(ScreenBuffers[CurrentBufferIndex],
		(TCHAR)' ',
		dwConSize,
		coordScreen,
		&cCharsWritten);
}

void Render()
{
	Clear();
	
	//Render All
	for (int i = 0; i < 2; i++)
	{
		RenderCharacter(&Characters[i]);
	}

	Present();
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