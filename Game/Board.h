#pragma once
#include "Point.h"
#include <vector>

class Board
{


public:
	// конструктор по умолчанию
	Board() {
		this->Sign_null = '-';
		m_Size_x = 0;
		m_Size_y = 0;

		for (int i = 0; i < m_Size_x; i++) {
			std::vector<char> buf (m_Size_x);
			for (int j = 0; j < m_Size_y; j++) {
				buf.push_back(Sign_null);
			}
			m_Matrix.push_back(buf);
		}
	}


	Board(int Size_x, int Size_y, char Sign_null) {
		this->Sign_null = Sign_null;
		// заполнили объект введенными значениями 
		m_Size_x = Size_x;
		m_Size_y = Size_y;

		for (int i = 0; i < m_Size_x; i++) {
			std::vector<char> buf(m_Size_x);
			for (int j = 0; j < m_Size_y; j++) {
				buf.push_back(Sign_null);
			}
			m_Matrix.push_back(buf);
		}

	}


	bool Is_Condition_Cell(Point); // получения состояния ячейки по её координатам
	char Get_Condition(Point); // вернуть состояние ячейки 
	int Get_Height();
	int Get_Width();
	char Get_Sign_null(); // получения признака пустого поля
	void Push_Point(char, Point); // установки знака по заданным координатам
	void ClearBoard();

private:
	std::vector<std::vector<char>> m_Matrix;
	int m_Size_x, m_Size_y; // СВОЙСТВА КЛАССА
	char Sign_null;
};

