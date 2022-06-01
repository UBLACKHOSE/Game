#pragma once
#include "Point.h"

class Board
{


public:
	// конструктор по умолчанию
	Board() {
		this->Sign_null = '-';
		m_Size_x = 0;
		m_Size_y = 0;
		m_Matrix = new char* [m_Size_x];
		for (int i = 0; i < m_Size_x; i++) {
			m_Matrix[i] = new char[m_Size_y];
			for (int j = 0; j < m_Size_y; j++) {

				m_Matrix[i][j] = Sign_null;
			}
		}
	}


	Board(int Size_x, int Size_y, char Sign_null) {
		this->Sign_null = Sign_null;
		// заполнили объект введенными значениями 
		m_Size_x = Size_x;
		m_Size_y = Size_y;
		m_Matrix = new char* [m_Size_x];
		for (int i = 0; i < Size_y; i++) {
			m_Matrix[i] = new char[m_Size_y];
			for (int j = 0; j < Size_x; j++) {

				m_Matrix[i][j] = Sign_null; // заполняем знаком нуля
			}
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
	char** m_Matrix;
	int m_Size_x, m_Size_y; // СВОЙСТВА КЛАССА
	char Sign_null;
};

