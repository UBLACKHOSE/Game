#include "Smart_Player.h"

string Smart_Player::GetName()
{

	return m_name;
}

char Smart_Player::GetSign()
{
	return m_sign;
}


Point Smart_Player::CreateMove(Board b)
{
	bool flag = false; // ��� ����������� ����������� ����� ������ �� ����
	Point p(1, 1);
	for (int i = 0; i < b.Get_Height(); i++)
	{
		for (int j = 0; j < b.Get_Width(); j++) {
			p.Set_Coordinate(i, j);
			if (this->GetSign() == b.Get_Condition(p)) { // ���������� ���� ������ �� ������ �� ����
				flag = true;
				break;
			}
		}
		if (flag == true) break;
	}



	if (!flag) {
		int x, y;
		x = rand() % b.Get_Width();
		y = rand() % b.Get_Height();
		Point p(x, y);
		// ���� �� ������� ������ ������ ������ ������ 
		while (!b.Is_Condition_Cell(p))
		{
			x = rand() % b.Get_Width();
			y = rand() % b.Get_Height();
			p.Set_Coordinate(x, y);
		}
		return p;
	}
	else // ���� ���������� ����
	{
		Point p_tmp(p.x, p.y); // ���������� ������� ���������� �����
		flag = false;


		for (int i = p.y - 1; i < p.y + 1; i++) {
			for (int j = p.x - 1; j < p.x + 1; j++) { // �������� ������ ����� 
				if (p.x == i && p.y == j) {
					continue;
				}

				if (i < 0 || j < 0 || i > b.Get_Width() || j > b.Get_Height()) { // ������� ���� 
					continue;
				}


				// ���������� ���������� ����� 
				p_tmp.Set_Coordinate(i, j);


				if (this->GetSign() == b.Get_Condition(p_tmp)) { // ���� ����� ���������� ���� ������ �����
					Point p_erv(p.x, p.y);
					// ���� ��� ����� �� ��������� �� � ��� ��������� �
					if (p_tmp.x == p.x) {
						// ���� ��� �� ���� ����� ������ �� �� ������� � �������� ������ ����� � ������
						if (p_tmp.y + 1 == p.y) {
							// �������� ��� ������ ������ ������
							p_erv.Set_Coordinate(p_tmp.x, p_tmp.y - 1);
							if (b.Is_Condition_Cell(p_erv)) {
								return p_erv;
							}
							p_erv.Set_Coordinate(p.x, p.y + 1);
							if (b.Is_Condition_Cell(p_erv)) {
								return p_erv;
							}
						}
						// �������� ��� ������ ������ �����
						else if (p_tmp.y - 1 == p.y) {

							p_erv.Set_Coordinate(p_tmp.x, p_tmp.y + 1);
							if (b.Is_Condition_Cell(p_erv)) {
								return p_erv;
							}
							p_erv.Set_Coordinate(p.x, p.y - 1);
							if (b.Is_Condition_Cell(p_erv)) {
								return p_erv;
							}

						}
					}
					if (p_tmp.y == p.y) {
						if (p_tmp.x + 1 == p.x) {
							// �������� ��� ������ ������ �����
							p_erv.Set_Coordinate(p_tmp.x - 1, p_tmp.y);
							if (b.Is_Condition_Cell(p_erv)) {
								return p_erv;
							}
							p_erv.Set_Coordinate(p.x + 1, p.y);
							if (b.Is_Condition_Cell(p_erv)) {
								return p_erv;
							}
						}
						// �������� ��� ������ ������ ������
						else if (p_tmp.x - 1 == p.x) {

							p_erv.Set_Coordinate(p_tmp.x + 1, p_tmp.y);
							if (b.Is_Condition_Cell(p_erv)) {
								return p_erv;
							}
							p_erv.Set_Coordinate(p.x - 1, p.y);
							if (b.Is_Condition_Cell(p_erv)) {
								return p_erv;
							}

						}
					}
				}
			}
		}
		// ���� �� �� ����� ����� � ��� ����������� ����� � ��������� ����
		p_tmp.Set_Coordinate(p.x - 1, p.y);
		if (b.Is_Condition_Cell(p_tmp)) {
			return p_tmp;
		}

		p_tmp.Set_Coordinate(p.x + 1, p.y);
		if (b.Is_Condition_Cell(p_tmp)) {
			return p_tmp;
		}

		p_tmp.Set_Coordinate(p.x, p.y + 1);
		if (b.Is_Condition_Cell(p_tmp)) {
			return p_tmp;
		}

		p_tmp.Set_Coordinate(p.x, p.y - 1);
		if (b.Is_Condition_Cell(p_tmp)) {
			return p_tmp;
		}
	}

	int x, y;
	x = rand() % b.Get_Width();
	y = rand() % b.Get_Height();
	p.Set_Coordinate(x, y);

	while (!b.Is_Condition_Cell(p))
	{
		x = rand() % b.Get_Width();
		y = rand() % b.Get_Height();
		p.Set_Coordinate(x, y);
	}
	return p;

}

void Smart_Player::DeletePlayer() {
	m_name = "";
	m_sign = '\0';
}