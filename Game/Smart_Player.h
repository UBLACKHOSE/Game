#pragma once
#include <iostream>
#include <string>
#include "Point.h"
#include "Board.h"
#include <time.h>

using namespace std;

class Smart_Player
{
private:
	std::string m_name;
	char m_sign;//знак
public:
	Smart_Player(string name, char sign) : m_name(name), m_sign(sign) {};
	Smart_Player() {};

	std::string GetName();
	char GetSign();
	Point CreateMove(Board);
	void DeletePlayer();


};

