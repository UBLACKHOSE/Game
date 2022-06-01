#pragma once

struct Point
{
	int x, y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void Set_Coordinate(int x, int y) {
		this->x = x;
		this->y = y;
	}
};