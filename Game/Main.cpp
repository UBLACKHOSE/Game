#include <iostream>
#include <locale.h>
#include "Player_random.h"
#include "Smart_Player.h"
#include "Game.h"
#include <conio.h>
#include  <vector>

//void Menu(Game);



int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

	Smart_Player* p1 = new Smart_Player("lol", 'x');

	cout << p1->Get_Print();

	vector<Player*> players;

	players.push_back(p1);


	cout << players[0]->Get_Print();
 //   Board b(5, 5, '-');
	//Game g(b);
	//
	//Menu(g);   

    return 0;
}

//void Menu(Game g) {
//
//	string menu_item[] = { "�������� ������","������� ������ �� �����","������� ���� �������", "������ ����","�����" };
//
//	char n_menu = '\0';
//
//	while (true)
//	{
//
//		for (int i = 0; i < sizeof(menu_item) / sizeof(string); i++)
//		{
//			cout << i << ". " << menu_item[i] << endl;
//		}
//
//		cout << "������� ����� ����:";
//		n_menu = _getch();
//		cout << "\n";
//		switch (n_menu)
//		{
//		case '0':
//		{
//
//			system("cls");
//			cout << "0.�������� ���������� ������\n1.�������� ������ ������\n";
//			cout << "������� ����� ����:";
//			char n_menu_2 = 0;
//			n_menu_2 = _getch();
//			if (n_menu_2 == '0') {
//				string name = ""; char sign = '\0';
//				cout << "\n������� ��� ������:";
//				cin >> name;
//				cout << "\n������� ���� (����) ������:";
//
//				sign = _getch();
//				cout << sign;
//				Player_random PR(name, sign);
//				try
//				{
//					g.Add_Players(PR);
//				}
//				catch (const char* e)
//				{
//					cout << e;
//				}
//				cout << "\n";
//			}
//			else if (n_menu_2 == '1')
//			{
//				string name = ""; char sign = '\0';
//				cout << "\n������� ��� ������:";
//				cin >> name;
//				cout << "\n������� ���� (����) ������:";
//
//				sign = _getch();
//				cout << sign;
//				Smart_Player SP(name, sign);
//				try
//				{
//					g.Add_Players(SP);
//				}
//				catch (const char* e)
//				{
//					cout << e;
//				}
//				cout << "\n";
//
//			}
//			else
//			{
//				cout << "�� ����� ��� �� �� ��\n";
//			}
//
//			break;
//		}
//		case '1': {
//
//			system("cls");
//			string name = "";
//			cout << "\n������� ��� ������ �������� ������ �������:";
//			cin >> name;
//			try
//			{
//				g.Delete_Player_By_Name(name);
//			}
//			catch (string e) {
//				cout << e << endl;
//			}
//
//			break;
//		}
//		case '2': {
//			try {
//
//				system("cls");
//				g.Print_Player();
//
//			}
//			catch (string e) {
//				cout << e;
//				cout << "\n";
//			}
//
//			break;
//		}
//		case '3': {
//
//
//			if (g.count_player < 2) {
//				cout << "\n������� ������ ���� 2 �������� �������\n" << endl;
//				break;
//			}
//
//			int count_move = (g.GetCountMove());
//			bool win = false;
//
//
//			for (int i = 0; i < count_move; i++) {
//				g.Print_Board();
//				cout << "������ ����� ����� " << g.Player_Which_Making_Move() << endl;
//				cout << "\n0.������� �������������\n1.������� ������\n";
//				cout << "������� ����� ����:\n";
//				char n_menu_2 = 0;
//				n_menu_2 = _getch();
//
//				cout << "\n";
//				if (n_menu_2 == '0') {
//					if (!g.Do_Move()) {
//						win = true;
//						break;
//					}
//				}
//				else if (n_menu_2 == '1')
//				{
//					int x, y;
//					cout << "\n������� ���������� ���� ��������� ����\n";
//					cout << "\n������� x =";
//					cin >> x;
//					cout << "\n������� y =";
//					cin >> y;
//
//					Point p(x, y);
//					try
//					{
//						if (g.Do_Move(p) == 0) {
//							win = true;
//							break;
//						}
//						else if (g.Do_Move(p) == 1)
//						{
//							cout << "\n�� ����� ��� �� �� ��\n";
//						}
//					}
//					catch (int e)
//					{
//						cout << "�� ���� ����������� ��� ���� ����";
//						i--;
//					}
//
//				}
//				else
//				{
//					i--;
//				}
//				if (win)break;
//
//			}
//
//			if (win) {
//
//				cout << "----------------------------------------" << endl;
//				cout << "������� ����� � �����: " << g.Get_Winner() << "|" << endl;
//				cout << "----------------------------------------" << endl;
//
//				g.Print_Board();
//				g.ClearBoard();
//				cout << endl;
//			}
//
//		}
//				break;
//		case '4':
//			return;
//			break;
//		default: system("cls"); cout << "�� ����� ��� �� �� ��\n\n"; break;
//		}
//
//
//	}
//}
