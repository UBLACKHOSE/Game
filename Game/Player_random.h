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
	char m_sign;//����
public:

	Player_random(std::string name, char sign) : m_name(name), m_sign(sign) {}; // ��� � ������ ������
	Player_random() {}; // ����������� �� ��������� 
	Player_random(const Player_random&);
	std::string GetName();
	char GetSign();
	Point CreateMove(Board);
	void DeletePlayer();



};

