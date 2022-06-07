#pragma once
#include "Smart_Player.h"


string Smart_Player::Get_Print() {
	string str;
	str.append("\n”мный игрок.»м€:");
	str.append(m_name);
	str.append("«нак:");
	str.append(string(1,m_sign));
	str.append("\n");
	return str;
}

Point Smart_Player::CreateMove(std::shared_ptr<Board> b)
{
	bool flag = false; // дл€ определени€ одинакового знака игрока на поле
	Point p(1, 1);
	for (int i = 0; i < b->Get_Height(); i++)
	{
		for (int j = 0; j < b->Get_Width(); j++) {
			p.Set_Coordinate(i, j);
			if (this->GetSign() == b->Get_Condition(p)) { // сравниваем знак игрока со знаком на поле
				flag = true;
				break;
			}
		}
		if (flag == true) break;
	}



	if (!flag) {
		int x, y;
		x = rand() % b->Get_Width();
		y = rand() % b->Get_Height();
		Point p(x, y);
		// пока не находим пустую €чейку ставим рандом 
		while (!b->Is_Condition_Cell(p))
		{
			x = rand() % b->Get_Width();
			y = rand() % b->Get_Height();
			p.Set_Coordinate(x, y);
		}
		return p;
	}
	else // есть одинаковый знак
	{
		Point p_tmp(p.x, p.y); // запоминаем текущие координаты знака
		flag = false;


		for (int i = p.y - 1; i < p.y + 1; i++) {
			for (int j = p.x - 1; j < p.x + 1; j++) { // проходит вокруг точки 
				if (p.x == i && p.y == j) {
					continue;
				}

				if (i < 0 || j < 0 || i > b->Get_Width() || j > b->Get_Height()) { // границы пол€ 
					continue;
				}


				// запоминаем координаты точки 
				p_tmp.Set_Coordinate(i, j);


				if (this->GetSign() == b->Get_Condition(p_tmp)) { // если нашли одинаковый знак вокруг точки
					Point p_erv(p.x, p.y);
					// если они лежат по вертикале то у них совпадают х
					if (p_tmp.x == p.x) {
						// если тот же знак лежит сверху то мы смотрим в соседнюю €чейку снизу и сверху
						if (p_tmp.y + 1 == p.y) {
							// проверка дл€ пустой €чейки сверху
							p_erv.Set_Coordinate(p_tmp.x, p_tmp.y - 1);
							if (b->Is_Condition_Cell(p_erv)) {
								return p_erv;
							}
							p_erv.Set_Coordinate(p.x, p.y + 1);
							if (b->Is_Condition_Cell(p_erv)) {
								return p_erv;
							}
						}
						// проверка дл€ пустой €чейки снизу
						else if (p_tmp.y - 1 == p.y) {

							p_erv.Set_Coordinate(p_tmp.x, p_tmp.y + 1);
							if (b->Is_Condition_Cell(p_erv)) {
								return p_erv;
							}
							p_erv.Set_Coordinate(p.x, p.y - 1);
							if (b->Is_Condition_Cell(p_erv)) {
								return p_erv;
							}

						}
					}
					if (p_tmp.y == p.y) {
						if (p_tmp.x + 1 == p.x) {
							// проверка дл€ пустой €чейки слева
							p_erv.Set_Coordinate(p_tmp.x - 1, p_tmp.y);
							if (b->Is_Condition_Cell(p_erv)) {
								return p_erv;
							}
							p_erv.Set_Coordinate(p.x + 1, p.y);
							if (b->Is_Condition_Cell(p_erv)) {
								return p_erv;
							}
						}
						// проверка дл€ пустой €чейки справа
						else if (p_tmp.x - 1 == p.x) {

							p_erv.Set_Coordinate(p_tmp.x + 1, p_tmp.y);
							if (b->Is_Condition_Cell(p_erv)) {
								return p_erv;
							}
							p_erv.Set_Coordinate(p.x - 1, p.y);
							if (b->Is_Condition_Cell(p_erv)) {
								return p_erv;
							}

						}
					}
				}
			}
		}
		// если мы не нашли р€дом с ним одинакового знака и добавл€ем знак
		p_tmp.Set_Coordinate(p.x - 1, p.y);
		if (b->Is_Condition_Cell(p_tmp)) {
			return p_tmp;
		}

		p_tmp.Set_Coordinate(p.x + 1, p.y);
		if (b->Is_Condition_Cell(p_tmp)) {
			return p_tmp;
		}

		p_tmp.Set_Coordinate(p.x, p.y + 1);
		if (b->Is_Condition_Cell(p_tmp)) {
			return p_tmp;
		}

		p_tmp.Set_Coordinate(p.x, p.y - 1);
		if (b->Is_Condition_Cell(p_tmp)) {
			return p_tmp;
		}
	}

	int x, y;
	x = rand() % b->Get_Width();
	y = rand() % b->Get_Height();
	p.Set_Coordinate(x, y);

	while (!b->Is_Condition_Cell(p))
	{
		x = rand() % b->Get_Width();
		y = rand() % b->Get_Height();
		p.Set_Coordinate(x, y);
	}
	return p;

}
