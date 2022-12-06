// pacma.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "conio.h"
#include <stdlib.h>



#define MAP_VERTICAL 29
#define MAP_HORIZONTAL 120
#define PERSONAJE 'O'



enum TILES {EMPTY = ' ', WALL = '#', POINT = '.'};
TILES map[MAP_VERTICAL][MAP_HORIZONTAL];
bool run = true;


enum INPUT { QUIT , UP ,DOWN, LEFT, RIGHT, UNKNOWN};
INPUT currentInput = INPUT::UNKNOWN;

int win;
int personaje_x;
int personaje_y;
int puntuacion_actual = 0;
int puntuacion_total;
// SE COLOQUE EL PERSONAJE EN EL CENTRO DEL MAPA AL COMENZAR
void Setup() {
	//PERSONAJE NO AVANCE SI EL ESPACIO NO ESTA VACIO Y SI LO ESTA AVANZA

	
	personaje_x = MAP_HORIZONTAL / 2;
	personaje_y = MAP_VERTICAL / 2;
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
	//PUNTOS DEL MAPA Y ESPACIOS VACIOS DEL MAPA TANTO VERTICAL COMO HORIZONTAL 
	map[27][61] = TILES::POINT;
	map[27][62] = TILES::POINT;
	map[27][63] = TILES::POINT;
	map[27][64] = TILES::POINT;

	map[1][61] = TILES::POINT;
	map[1][62] = TILES::POINT;
	map[1][63] = TILES::POINT;

	map[10][1] = TILES::POINT;
	map[11][1] = TILES::POINT;
	map[12][1] = TILES::POINT;
	map[13][1] = TILES::POINT;

	map[10][118] = TILES::POINT;
	map[11][118] = TILES::POINT;
	map[12][118] = TILES::POINT;
	map[13][118] = TILES::POINT;

	map[12][0] = TILES::EMPTY;
	map[10][0] = TILES::EMPTY;
	map[11][0] = TILES::EMPTY;
	map[13][0] = TILES::EMPTY;

	map[0][58] = TILES::EMPTY;
	map[0][59] = TILES::EMPTY;
	map[0][60] = TILES::EMPTY;
	map[0][61] = TILES::EMPTY;
	map[0][62] = TILES::EMPTY;
	map[0][63] = TILES::EMPTY;
	map[0][64] = TILES::EMPTY;
	map[0][65] = TILES::EMPTY;


	map[12][MAP_HORIZONTAL-1] = TILES::EMPTY;
	map[10][MAP_HORIZONTAL - 1] = TILES::EMPTY;
	map[11][MAP_HORIZONTAL - 1] = TILES::EMPTY;
	map[13][MAP_HORIZONTAL - 1] = TILES::EMPTY;

	map[MAP_VERTICAL - 1][58] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][59] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][60] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][61] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][62] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][63] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][64] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][65] = TILES::EMPTY;
	//VERIFICAMOS SI EL JUGADOR PASO POR UN PUNTO O NO 
	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (map[i][j] == TILES::POINT) {
				puntuacion_total++;
			}

		}
	}
}
//VALIDACION DE TECLAS PARA EL MOVIMIENTO 
void Input() {
	
	if (_kbhit) {
		char tecla = _getch();
		if (tecla == 'w' ) {
			currentInput = INPUT::UP;
		}
		else if (tecla == 'W') {
			currentInput = INPUT::UP;
		}
		else if (tecla == 's') {
			currentInput = INPUT::DOWN;
		}
		else if (tecla == 'S') {
			currentInput = INPUT::DOWN;
		}
		else if (tecla == 'a') {
			currentInput = INPUT::LEFT;
		}
		else if (tecla == 'A') {
			currentInput = INPUT::LEFT;
		}
		else if (tecla == 'd') {
			currentInput = INPUT::RIGHT;
		}
		else if (tecla == 'D') {
			currentInput = INPUT::RIGHT;
		}
		else if (tecla == 'q') {
			currentInput = INPUT::QUIT;
		}
		else if (tecla == 'Q') {
			currentInput = INPUT::QUIT;
		}
		else {
			currentInput = INPUT::UNKNOWN;
		}
			
	}

	

}
// SUMA DE LA POSICION A LA POSICION ACTUAL 
void Logic() {
	int personaje_y_new = personaje_y;
	int personaje_x_new = personaje_x;
	switch (currentInput)
	{
	case QUIT:
		run = false;
		break;
	case UP:
		personaje_y_new--;
		break;
	case DOWN:
		personaje_y_new++;
		break;
	case LEFT:
		personaje_x_new--;
		break;
	case RIGHT:
		personaje_x_new++;
		break;
	case UNKNOWN:
		break;
		while (true) {
			
	}
	}
	//TELETRANSPORTE ENTRE ESPACIOS 
	if (personaje_y_new < 0) {
		personaje_y_new = MAP_VERTICAL - 1;
	}
	if (personaje_x_new < 0) {
		personaje_x_new = MAP_HORIZONTAL - 1;
	}
	personaje_x_new = personaje_x_new % MAP_HORIZONTAL;
	personaje_y_new = personaje_y_new % MAP_VERTICAL;
	if (map[personaje_y_new][personaje_x_new] != TILES::WALL) {
		personaje_y = personaje_y_new;
		personaje_x = personaje_x_new;
	}
	//puntuacion y suma de la puntuacion
	switch (map[personaje_y_new][personaje_x_new])
	{
	case TILES::WALL:
		break;
	case TILES::POINT:
		puntuacion_actual++;
		map[personaje_y_new][personaje_x_new] = TILES::EMPTY;
		break;
	default:
		personaje_y = personaje_y_new;
		personaje_x = personaje_x_new;
		break;
		
	}

	

	

}
void Draw() {
	//DIBUJO DEL MAPA Y DEL PERSONAJE
	system("color 0A");
	system("CLS");

	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (i == personaje_y && j == personaje_x) {
				std::cout << PERSONAJE;
			}
			else {
				std::cout << (char)map[i][j];
			}
			
		}
		std::cout << std::endl;
	}
	// DIBUJO DE LA PUNTUACION ACTUAL
	

	std::cout << puntuacion_actual << '/' << puntuacion_total;
	if (puntuacion_actual == puntuacion_total) {

		printf("\n\t\tGanaste La Partida");
		exit(1);
		

	}
	
}




int main()
{
	//EJECUCION DE LAS FUNCIONES
	Setup();
	Draw();
	while (run) {
		Input();
		Logic();
		Draw();
	}
	
}
