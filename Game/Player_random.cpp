#include "Player_random.h"


Player_random::Player_random(const Player_random& PR)
{
	m_name = PR.m_name;
	m_sign = PR.m_sign;
}


Point Player_random::CreateMove(std::shared_ptr<Board> b)  {
	int x, y;
	x = rand() % b->Get_Width();
	y = rand() % b->Get_Height();
	Point p(x, y);

	while (!b->Is_Condition_Cell(p)) // Проверка на пустую ячейку
	{
		x = rand() % b->Get_Width();
		y = rand() % b->Get_Height();
		p.Set_Coordinate(x, y);
	}

	return p;
}

string Player_random::Get_Print() {
	string str;
	str.append("\nРандомный игрок.Имя:");
	str.append(m_name);
	str.append("Знак:");
	str.append(string(1,m_sign));
	str.append("\n");
	return str;
}
