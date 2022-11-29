// pacma.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define MAP_VERTICAL 29
#define MAP_HORIZONTAL 120
enum TILES {EMPTY = ' ', WALL = '#', POINT = '.'};
TILES map[MAP_VERTICAL][MAP_HORIZONTAL];
bool run = true;

enum INPUT { QUIT , UP ,DOWN, LEFT, RIGHT, UNKNOWN};
INPUT currentInput = INPUT::UNKNOWN;
void Setup() {
	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (i == 0 || j == 0 || i == MAP_VERTICAL - 1 || j == MAP_HORIZONTAL - 1) {
				map[i][j] = TILES::WALL;
			}
			else {
				map[i][j] = TILES::EMPTY;
			}

		}
	}
}

void Input() {
	char input;
	std::cin >> input;
	switch (input)
	{
	case 'a':
	case 'A':
		currentInput = INPUT::LEFT;
		break;
	case 'd':
	case 'D':
		currentInput = INPUT::RIGHT;
		break;
	case 'w':
	case 'W':
		currentInput = INPUT::UP;
		break;
	case 's':
	case 'S':
		currentInput = INPUT::DOWN;
		break;
	case 'q':
	case 'Q':
		currentInput = INPUT::QUIT;
		break;
	default:
		currentInput = INPUT::UNKNOWN;
		break;
	}
}

void Logic() {
	switch (currentInput)
	{
	case QUIT:
		run = false;
		break;
	case UP:
		break;
	case DOWN:
		break;
	case LEFT:
		break;
	case RIGHT:
		break;
	case UNKNOWN:
		break;
	
	}
}
void Draw() {
	system("CLS");
	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			std::cout << (char)map[i][j];
		}
		std::cout << std::endl;
	}
}



int main()
{
	Setup();
	Draw();
	while (run) {
		Input();
		Logic();
		Draw();
	}
	
}
