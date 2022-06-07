#pragma once
#include <iostream>
#include "Point.h"
#include "Board.h"
#include <string>
using namespace std;

class Player
{

public:
	Player(std::string name, char sign):m_name(name), m_sign(sign) {};
	Player() {};


	std::string GetName();
	char GetSign();
	virtual Point CreateMove(std::shared_ptr<Board>) = 0;
	virtual string Get_Print() = 0;
public:
	std::string m_name;
	char m_sign;//знак
};

