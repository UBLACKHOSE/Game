#pragma once
#include "Player.h"

using namespace std;

class Player_random : public Player
{

public:
	Player_random(std::string name, char sign) : Player(name,sign) {}; // имя и значок игрока
	Player_random() {}; // конструктор по умолчанию 


	Player_random(const Player_random&);// конструктор копирования
	string Get_Print() ;
	Point CreateMove(std::shared_ptr <Board>) ;



};

