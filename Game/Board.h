#pragma once
#include "Point.h"

class Board
{


public:
	// ����������� �� ���������
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
		// ��������� ������ ���������� ���������� 
		m_Size_x = Size_x;
		m_Size_y = Size_y;
		m_Matrix = new char* [m_Size_x];
		for (int i = 0; i < Size_y; i++) {
			m_Matrix[i] = new char[m_Size_y];
			for (int j = 0; j < Size_x; j++) {

				m_Matrix[i][j] = Sign_null; // ��������� ������ ����
			}
		}

	}


	bool Is_Condition_Cell(Point); // ��������� ��������� ������ �� � �����������
	char Get_Condition(Point); // ������� ��������� ������ 
	int Get_Height();
	int Get_Width();
	char Get_Sign_null(); // ��������� �������� ������� ����
	void Push_Point(char, Point); // ��������� ����� �� �������� �����������
	void ClearBoard();

private:
	char** m_Matrix;
	int m_Size_x, m_Size_y; // �������� ������
	char Sign_null;
};

