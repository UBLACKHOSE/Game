#pragma once
#include <iostream>
#include <string>
#include "Point.h"
#include "Board.h"

using namespace std;

class Player_random
{
private:
	std::string m_name;
	char m_sign;//знак
public:

	Player_random(std::string name, char sign) : m_name(name), m_sign(sign) {}; // имя и значок игрока
	Player_random() {}; // конструктор по умолчанию 
	Player_random(const Player_random&);
	std::string GetName();
	char GetSign();
	Point CreateMove(Board);
	void DeletePlayer();



};

