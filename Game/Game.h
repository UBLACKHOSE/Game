#pragma once
#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
#include <vector>
using namespace std;

class Game
{



public:
	Game(std::shared_ptr<Board>);
	void Print_Board();
	void Print_Player();
	void Add_Players(std::unique_ptr<Player>); // ���������� ����������������
	void Delete_Player_By_Name(string);// �������� ������ �� �����
	bool Do_Move();// ���������� ���� ������������� 
	int Do_Move(Point);// ���������� ���� �� �������� �����������
	string Get_Winner();// ��������� ����������
	string Player_Which_Making_Move();// ��������� ������������ ��� ������
	bool CheckPointWin(Point, char);

	void ClearBoard();



	bool check_two_point(Point, Point, char);
	int GetCountMove();

private:
	std::shared_ptr<Board> m_b;
	vector<shared_ptr<Player>> players;
	int number_player = 0;

public :
	int count_player = 0;
};

