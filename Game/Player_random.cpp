#include "Player_random.h"


Player_random::Player_random(const Player_random& PR)
{
	m_name = PR.m_name;
	m_sign = PR.m_sign;
}

string Player_random::GetName() {

	return m_name;

}


char Player_random::GetSign()
{
	return m_sign;
}


Point Player_random::CreateMove(Board b) {
	int x, y;
	x = rand() % b.Get_Width();
	y = rand() % b.Get_Height();
	Point p(x, y);

	while (!b.Is_Condition_Cell(p)) // Проверка на пустую ячейку
	{
		x = rand() % b.Get_Width();
		y = rand() % b.Get_Height();
		p.Set_Coordinate(x, y);
	}

	return p;
}


void Player_random::DeletePlayer() {
	m_name = "";
	m_sign = '\0';
}