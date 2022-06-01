#pragma once
#include <iostream>
#include <string>
#include "Board.h"
#include "Smart_Player.h"
#include "Player_random.h"



using namespace std;

class Game
{
private:
	Board m_b;
	Player_random* Players_R;
	Smart_Player* Players_S;
	int number_player = 0;
	int count_player = 0;

	int count_r_player = 0;
	int count_s_player = 0;

	bool random_or_smart = 0;


public:
	Game(Board);
	void Print_Board();
	void Print_Player();
	void Add_Random_Player(Player_random); // добавлени€ —лучайного»грока
	void Add_Smart_Player(Smart_Player);// добавлени€ ”много»грока
	void Delete_Player_By_Name(string);// удалени€ игрока по имени
	bool Do_Move();// выполнени€ хода автоматически 
	int Do_Move(Point);// выполнени€ хода по заданным координатам
	string Get_Winner();// получени€ победител€
	string Player_Which_Making_Move();// получени€ выполн€ющего ход игрока
	bool CheckPointWin(Point, char);
	void Menu();
	void ClearBoard();

	template <typename T>
	void my_realloc(T*&, int, int);

	bool check_two_point(Point, Point, char);

};

