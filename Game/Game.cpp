#include "Game.h"

#include <conio.h>

Game::Game(std::shared_ptr<Board> b) {
	m_b = std::move(b);
};



void Game::ClearBoard() {
	m_b->ClearBoard();
}







void Game::Add_Players(std::unique_ptr<Player> p) {
	int i = 0;

	if (p->GetName() == "" || p->GetSign() == '\0')  throw "�� �� ������ �������� ������ ������������";

	if (count_player >= 5) throw "�� �������� ������ ������� �� ����";

	if (p->GetSign() == m_b->Get_Sign_null()) throw "�� �� ������ ������������ ������� ���� ����";


	for (i = 0; i < count_player; i++) {
		if (players[i]->GetName() == p->GetName()) throw "�� �� ������ �������� ������ ������������";
	}

	for (i = 0; i < count_player; i++) {
		if (players[i]->GetSign() == p->GetSign()) throw "�� �� ������ �������� ������ ������������";
	}

	players.push_back(std::move(p));

	count_player++;
};



void Game::Delete_Player_By_Name(string name) {
	int i = 0;
	bool error = false;

	for (i = 0; i < count_player; i++) {
		if (players[i]->GetName() == name) {
			error = true;
			break;
		}
	}


	if (error == false) {
		string str = "��� ������ ������ = ";
		str.append(name);
		throw str; // ���������� 
	}
	else
	{
		players.erase(players.begin() + i);
		count_player--;
	}
};

bool Game::Do_Move() {

	bool move = false;

	Point p = players[number_player]->CreateMove(m_b);

	m_b->Push_Point(players[number_player]->GetSign(), p);

	if (CheckPointWin(p, players[number_player]->GetSign())) {
		return false;
	};


	if (number_player >= count_player - 1) number_player = 0; else
	{
		number_player++;
	}

	return true;

};

int Game::Do_Move(Point p) {

	bool move = false;

	if (m_b->Is_Condition_Cell(p)) {

		m_b->Push_Point(players[number_player]->GetSign(), p);

		if (CheckPointWin(p, players[number_player]->GetSign())) {
			return 0;
		};


		if (number_player >= count_player - 1) number_player = 0; 
		else
			number_player++;

	}
	else
	{
		return 1;
	}

	

};



bool Game::CheckPointWin(Point p, char sign) {

	Point p_check_1(p.x - 2, p.y - 2);
	Point p_check_2(p.x - 1, p.y - 1);


	//�������� ��������� ����� �������



	if (check_two_point(p_check_1, p_check_2, sign)) return true;


	p_check_1.Set_Coordinate(p.x - 1, p.y - 1);
	p_check_2.Set_Coordinate(p.x + 1, p.y + 1);

	if (check_two_point(p_check_1, p_check_2, sign)) return true;

	p_check_1.Set_Coordinate(p.x + 2, p.y + 2);
	p_check_2.Set_Coordinate(p.x + 1, p.y + 1);

	if (check_two_point(p_check_1, p_check_2, sign)) return true;


	//�������� ��������� ������ ������
	p_check_1.Set_Coordinate(p.x + 2, p.y - 2);
	p_check_2.Set_Coordinate(p.x + 1, p.y - 1);
	if (check_two_point(p_check_1, p_check_2, sign)) return true;

	p_check_1.Set_Coordinate(p.x - 1, p.y + 1);
	p_check_2.Set_Coordinate(p.x + 1, p.y - 1);
	if (check_two_point(p_check_1, p_check_2, sign)) return true;

	p_check_1.Set_Coordinate(p.x - 2, p.y + 2);
	p_check_2.Set_Coordinate(p.x - 1, p.y + 1);

	if (check_two_point(p_check_1, p_check_2, sign)) return true;


	//�������� ��������� 
	p_check_1.Set_Coordinate(p.x, p.y - 2);
	p_check_2.Set_Coordinate(p.x, p.y - 1);
	if (check_two_point(p_check_1, p_check_2, sign)) return true;

	p_check_1.Set_Coordinate(p.x, p.y + 1);
	p_check_2.Set_Coordinate(p.x, p.y - 1);
	if (check_two_point(p_check_1, p_check_2, sign)) return true;

	p_check_1.Set_Coordinate(p.x, p.y + 2);
	p_check_2.Set_Coordinate(p.x, p.y + 1);

	if (check_two_point(p_check_1, p_check_2, sign)) return true;



	//�������� ����������� 
	p_check_1.Set_Coordinate(p.x - 2, p.y);
	p_check_2.Set_Coordinate(p.x - 1, p.y);
	if (check_two_point(p_check_1, p_check_2, sign)) return true;

	p_check_1.Set_Coordinate(p.x + 1, p.y);
	p_check_2.Set_Coordinate(p.x - 1, p.y);
	if (check_two_point(p_check_1, p_check_2, sign)) return true;

	p_check_1.Set_Coordinate(p.x + 2, p.y);
	p_check_2.Set_Coordinate(p.x + 1, p.y);

	if (check_two_point(p_check_1, p_check_2, sign)) return true;

	return false;

}


bool Game::check_two_point(Point p1, Point p2, char sign) {

	try
	{
		if (m_b->Get_Condition(p1) == sign && m_b->Get_Condition(p2) == sign) {
			return true;
		}
	}
	catch (int e)
	{
		return false;
	}

	return false;
}

void Game::Print_Board() {


	Point p(0, 0);

	for (int i = 0; i < m_b->Get_Height(); i++) {
		for (int j = 0; j < m_b->Get_Width(); j++) {
			p.Set_Coordinate(i, j);

			cout << m_b->Get_Condition(p);
		}
		cout << "\n";
	}


}



string Game::Get_Winner() {

	return players[number_player]->GetName();
};

string Game::Player_Which_Making_Move() {

	return players[number_player]->GetName();
};


void Game::Print_Player() {

	int i = 0;
	int n_player = 1;
	bool error = false;

	cout << "������" << endl;

	for (const std::shared_ptr<Player>& palyer : players) {
		cout << palyer->Get_Print() << endl;
		n_player++;
		error = true;
	}


	cout << "----------------" << endl;

	if (error == false) {
		string str = "������� ���";
		throw str; // ���������� 
	}

}


int Game::GetCountMove() {
	return m_b->Get_Height() * m_b->Get_Width();
}