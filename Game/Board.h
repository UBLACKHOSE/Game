#pragma once
#include "Point.h"
#include <vector>

class Board
{


public:
	// ����������� �� ���������
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
		// ��������� ������ ���������� ���������� 
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


	bool Is_Condition_Cell(Point); // ��������� ��������� ������ �� � �����������
	char Get_Condition(Point); // ������� ��������� ������ 
	int Get_Height();
	int Get_Width();
	char Get_Sign_null(); // ��������� �������� ������� ����
	void Push_Point(char, Point); // ��������� ����� �� �������� �����������
	void ClearBoard();

private:
	std::vector<std::vector<char>> m_Matrix;
	int m_Size_x, m_Size_y; // �������� ������
	char Sign_null;
};

