#include "Game.h"

#include <conio.h>

Game::Game(Board b) {
	m_b = b;

};

void Game::Menu() {

	string menu_item[] = { "�������� ������","������� ������ �� �����","������� ���� �������", "������ ����","�����" };

	char n_menu = '\0';

	while (true)
	{

		for (int i = 0; i < sizeof(menu_item) / sizeof(string); i++)
		{
			cout << i << ". " << menu_item[i] << endl;
		}

		cout << "������� ����� ����:";
		n_menu = _getch();
		cout << "\n";
		switch (n_menu)
		{
		case '0':
		{

			system("cls");
			cout << "0.�������� ���������� ������\n1.�������� ������ ������\n";
			cout << "������� ����� ����:";
			char n_menu_2 = 0;
			n_menu_2 = _getch();
			if (n_menu_2 == '0') {
				string name = ""; char sign = '\0';
				cout << "\n������� ��� ������:";
				cin >> name;
				cout << "\n������� ���� (����) ������:";

				sign = _getch();
				cout << sign;
				Player_random PR(name, sign);
				try
				{
					Add_Random_Player(PR);
				}
				catch (const char* e)
				{
					cout << e;
				}
				cout << "\n";
			}
			else if (n_menu_2 == '1')
			{
				string name = ""; char sign = '\0';
				cout << "\n������� ��� ������:";
				cin >> name;
				cout << "\n������� ���� (����) ������:";

				sign = _getch();
				cout << sign;
				Smart_Player PS(name, sign);
				try
				{
					Add_Smart_Player(PS);
				}
				catch (const char* e)
				{
					cout << e;
				}
				cout << "\n";

			}
			else
			{
				cout << "�� ����� ��� �� �� ��\n";
			}

			break;
		}
		case '1': {

			system("cls");
			string name = "";
			cout << "\n������� ��� ������ �������� ������ �������:";
			cin >> name;
			try
			{
				Delete_Player_By_Name(name);
			}
			catch (string e) {
				cout << e << endl;
			}

			break;
		}
		case '2': {
			try {

				system("cls");
				Print_Player();

			}
			catch (string e) {
				cout << e;
				cout << "\n";
			}

			break;
		}
		case '3': {


			if (count_player < 2) {
				cout << "\n������� ������ ���� 2 �������� �������\n" << endl;
				break;
			}

			int count_move = (m_b.Get_Height() * m_b.Get_Width());
			bool win = false;


			for (int i = 0; i < count_move; i++) {
				Print_Board();
				cout << "������ ����� ����� " << Player_Which_Making_Move() << endl;
				cout << "\n0.������� �������������\n1.������� ������\n";
				cout << "������� ����� ����:\n";
				char n_menu_2 = 0;
				n_menu_2 = _getch();

				cout << "\n";
				if (n_menu_2 == '0') {
					if (!Do_Move()) {
						win = true;
						break;
					}
				}
				else if (n_menu_2 == '1')
				{
					int x, y;
					cout << "\n������� ���������� ���� ��������� ����\n";
					cout << "\n������� x =";
					cin >> x;
					cout << "\n������� y =";
					cin >> y;

					Point p(x, y);
					try
					{
						if (Do_Move(p) == 0) {
							win = true;
							break;
						}
						else if (Do_Move(p) == 1)
						{
							cout << "\n�� ����� ��� �� �� ��\n";
						}
					}
					catch (int e)
					{
						cout << "�� ���� ����������� ��� ���� ����";
						i--;
					}

				}
				else
				{
					i--;
				}
				if (win)break;

			}

			if (win) {

				cout << "----------------------------------------" << endl;
				cout << "������� ����� � �����: " << Get_Winner() << "|" << endl;
				cout << "----------------------------------------" << endl;

				Print_Board();
				ClearBoard();
				cout << endl;
			}

		}
				break;
		case '4':
			return;
			break;
		default: system("cls"); cout << "�� ����� ��� �� �� ��\n\n"; break;
		}


	}
	delete[] Players_R;
	delete[] Players_S;
}

void Game::ClearBoard() {
	m_b.ClearBoard();
}





void Game::Add_Random_Player(Player_random PR) {
	int i = 0;
	// ���������� 
	if (PR.GetName() == "" || PR.GetSign() == '\0') throw "�� �� ������ �������� ������ ������������";
	if (count_player >= 5) throw "�� �������� ������ ������� �� ����";
	if (PR.GetSign() == m_b.Get_Sign_null()) throw "�� �� ������ ������������ ������� ���� ����";


	for (i = 0; i < count_r_player; i++) {
		if (Players_R[i].GetSign() == PR.GetSign()) throw "�� �� ������ �������� ������ ������������";
	}
	for (i = 0; i < count_s_player; i++) {
		if (Players_S[i].GetSign() == PR.GetSign()) throw "�� �� ������ �������� ������ ������������";
	}


	my_realloc(Players_R, count_r_player, count_r_player + 1);
	Players_R[count_r_player] = PR;

	count_r_player++;
	count_player++;
};

template <typename T>
void Game::my_realloc(T*& arr, int size, int new_size)
{
	T* new_arr = new T[new_size];
	size = size < new_size ? size : new_size;

	for (int i = 0; i < size; ++i)
		new_arr[i] = arr[i];

	delete[] arr;

	arr = new_arr;
}

void Game::Add_Smart_Player(Smart_Player SP) {
	int i = 0;

	if (SP.GetName() == "" || SP.GetSign() == '\0')  throw "�� �� ������ �������� ������ ������������";
	if (count_player >= 5) throw "�� �������� ������ ������� �� ����";
	if (SP.GetSign() == m_b.Get_Sign_null()) throw "�� �� ������ ������������ ������� ���� ����";

	for (i = 0; i < count_r_player; i++) {
		if (Players_R[i].GetSign() == SP.GetSign()) throw "�� �� ������ �������� ������ ������������";
	}
	for (i = 0; i < count_s_player; i++) {
		if (Players_S[i].GetSign() == SP.GetSign()) throw "�� �� ������ �������� ������ ������������";
	}


	my_realloc(Players_S, count_s_player, count_s_player + 1);
	Players_S[count_s_player] = SP;

	count_s_player++;
	count_player++;
};



void Game::Delete_Player_By_Name(string name) {
	int i = 0;
	bool error = false;



	for (i = 0; i < count_r_player; i++) {
		if (Players_R[i].GetName() == name) {

			for (int j = i; j < count_r_player - 1; j++) {
				Players_R[j] = Players_R[j + 1];
			}
			my_realloc(Players_R, count_r_player, count_r_player - 1);
			count_r_player = count_r_player - 1;
			error = true;
			break;
		}
	}

	if (!error)
		for (i = 0; i < count_s_player; i++) {
			if (Players_S[i].GetName() == name) {
				for (int j = i; j < count_s_player - 1; j++) {
					Players_S[j] = Players_S[j + 1];
				}
				my_realloc(Players_S, count_s_player, count_s_player - 1);
				count_s_player = count_s_player - 1;
				error = true;
				break;
			}
		}


	if (error == false) {
		string str = "��� ������ ������ = ";
		str.append(name);

		throw str; // ���������� 
	}
};

bool Game::Do_Move() {

	bool move = false;


	if (!random_or_smart && number_player < count_r_player) {
		Point p = Players_R[number_player].CreateMove(m_b);
		m_b.Push_Point(Players_R[number_player].GetSign(), p);


		if (CheckPointWin(p, Players_R[number_player].GetSign())) {
			return false;
		};

		number_player++;
		move = true;
	}

	if (!random_or_smart && number_player >= count_r_player)
	{
		random_or_smart = true;
		number_player = 0;
	}






	if (random_or_smart && number_player < count_s_player && !move) {
		Point p = Players_S[number_player].CreateMove(m_b);
		m_b.Push_Point(Players_S[number_player].GetSign(), p);
		if (CheckPointWin(p, Players_S[number_player].GetSign())) {
			return false;
		};
		number_player++;
		move = true;
	}


	if (random_or_smart && number_player >= count_s_player)
	{
		random_or_smart = false;
		number_player = 0;
		if (!move) this->Do_Move();
	}

};

int Game::Do_Move(Point p) {

	bool move = false;


	if (!random_or_smart && number_player < count_r_player) {
		if (m_b.Is_Condition_Cell(p)) {
			m_b.Push_Point(Players_R[number_player].GetSign(), p);


			if (CheckPointWin(p, Players_R[number_player].GetSign())) {
				return 0;
			};

			number_player++;
			move = true;
		}
		else
		{
			return 1;
		}
	}

	if (!random_or_smart && number_player >= count_r_player)
	{
		random_or_smart = true;
		number_player = 0;
	}






	if (random_or_smart && number_player < count_s_player && !move) {

		if (m_b.Is_Condition_Cell(p)) {

			m_b.Push_Point(Players_S[number_player].GetSign(), p);
			if (CheckPointWin(p, Players_S[number_player].GetSign())) {
				return 0;
			};
			number_player++;
			move = true;

		}
		else
		{
			return 1;
		}
	}


	if (random_or_smart && number_player >= count_s_player)
	{
		random_or_smart = false;
		number_player = 0;
		if (!move) this->Do_Move();
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
		if (m_b.Get_Condition(p1) == sign && m_b.Get_Condition(p2) == sign) {
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

	for (int i = 0; i < m_b.Get_Height(); i++) {
		for (int j = 0; j < m_b.Get_Width(); j++) {
			p.Set_Coordinate(i, j);

			cout << m_b.Get_Condition(p);
		}
		cout << "\n";
	}


}



string Game::Get_Winner() {


	if (!random_or_smart) { // ������
		return Players_R[number_player].GetName();
	}

	if (random_or_smart) { // smart
		return Players_S[number_player].GetName();
	}
};

string Game::Player_Which_Making_Move() {

	if (!random_or_smart) {
		return Players_R[number_player].GetName();
	}

	if (random_or_smart) {
		return Players_S[number_player].GetName();
	}
};


void Game::Print_Player() {

	int i = 0;
	int n_player = 1;
	bool error = false;

	cout << "������" << endl;

	for (i = 0; i < count_r_player; i++) {
		cout << n_player << ". " << Players_R[i].GetName() << " ���� (" << Players_R[i].GetSign() << ")" << " ��������� �����" << endl;
		n_player++;
		error = true;
	}


	for (i = 0; i < count_s_player; i++) {
		cout << n_player << ". " << Players_S[i].GetName() << " ���� (" << Players_S[i].GetSign() << ")" << " ����� �����" << endl;
		n_player++;
		error = true;
	}

	cout << "----------------" << endl;

	if (error == false) {
		string str = "������� ���";
		throw str; // ���������� 
	}

}