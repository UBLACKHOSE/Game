#pragma once
#include "Player.h"

using namespace std;

class Player_random : public Player
{

public:
	Player_random(std::string name, char sign) : Player(name,sign) {}; // ��� � ������ ������
	Player_random() {}; // ����������� �� ��������� 


	Player_random(const Player_random&);// ����������� �����������
	string Get_Print() ;
	Point CreateMove(std::shared_ptr <Board>) ;



};

