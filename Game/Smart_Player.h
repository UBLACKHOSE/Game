#pragma once
#include "Player.h"

using namespace std;

class Smart_Player : public Player
{

public:
	Smart_Player(std::string name, char sign) : Player(name, sign) {}; // ��� � ������ ������
	Smart_Player() {}; // ����������� �� ��������� 
	Smart_Player(const Smart_Player&);// ����������� �����������
	string Get_Print() ;
	Point CreateMove(std::shared_ptr<Board>) ;


};

