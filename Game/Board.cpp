#include "Board.h"
#include <exception>

bool Board::Is_Condition_Cell(Point p) { // провер€ем состо€ние €чейки 
	if (p.x >= m_Size_x || p.y >= m_Size_y || p.x < 0 || p.y < 0) return false;
	return (m_Matrix[p.x][p.y] == Sign_null) ? true : false; // провер€ем на пустоту
}


void Board::Push_Point(char sign, Point p) {
	m_Matrix[p.x][p.y] = sign;
}

char Board::Get_Sign_null() {
	return Sign_null;
}

int Board::Get_Height() {
	return m_Size_y;
}


int Board::Get_Width() {
	return m_Size_x;
}


char Board::Get_Condition(Point p) { // возвращаем знак €чейки 

	if (p.x < 0 || p.y < 0 || p.x >= m_Size_x || p.y >= m_Size_y)
		throw 0;

	return m_Matrix[p.x][p.y];
}

void Board::ClearBoard() {

	for (int i = 0; i < m_Size_x; i++) {
		for (int j = 0; j < m_Size_y; j++) {

			m_Matrix[i][j] = Sign_null;
		}
	}

}