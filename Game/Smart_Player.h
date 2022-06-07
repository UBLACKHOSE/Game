#pragma once
#include "Player.h"

using namespace std;

class Smart_Player : public Player
{

public:
	Smart_Player(std::string name, char sign) : Player(name, sign) {}; // имя и значок игрока
	Smart_Player() {}; // конструктор по умолчанию 
	Smart_Player(const Smart_Player&);// конструктор копирования
	string Get_Print() ;
	Point CreateMove(std::shared_ptr<Board>) ;


};

