#include <iostream>
#include <cstdlib>
#include <time.h>

int main()
{
	int pae1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int pae2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };	//1,3,8 ��
	int P_bet = 300, C_bet = 300;						//�ʱ� ���ñݾ�
	int P_money = 10000, C_money = 10000;				//���� �ݾ�
	int choice = 0, ai = 0;								//player computer ����
	int ddang = 0, ggut = 0;							//��ǻ�� �� �� ��
	int dang = 0, gut = 0;								//�÷��̾� �� �� ��
	int P_bnew = 0, C_bnew = 0;							//���� �ݾ�
	int i = 0, a = 0, c = 0;
	int j = 0, b = 0;
	int prob = 0;										//Ȯ������

	while (true)
	{
		// �� �� ���� �� �� �Ҹ�Ǵ� �⺻ ���ñݾ�
		C_bet = 300;
		P_bet = 300;

		//�� ���� ����
		srand(time(NULL));
		i = rand() % 10;
		j = rand() % 10;
		a = rand() % 10;
		b = rand() % 10;
		prob = rand() % 100 + 1;
		std::cout << "\n-------------------------------------\n";
		std::cout << "�⺻ ���ñݾ� >> 300" << "\n";
		std::cout << "Player card 1 : " << pae1[i] << "\n" <<
			"Player card 2 : " << pae2[j] << "\n";

		//player card
		if (pae1[i] == pae2[j]) {
			dang = pae1[i] + 10;
			std::cout << dang - 10 << "��\n";
			gut = dang;
		}
		else {
			gut = (pae1[i] + pae2[j]) % 10;
			std::cout << gut << "��\n";
		}

		//computer card
		if (pae1[a] == pae2[b]) {
			ddang = pae1[a] + 10;
			ggut = ddang;
		}
		else if (pae1[a] != pae2[b])
			ggut = (pae1[a] + pae2[b]) % 10;


		// call die            
		for (c = 0; c<1; ++c) {
		INPUT:
			std::cout << "call[1] die[2] : ";
			std::cin >> choice;



			//my turn
			if (choice == 1) {
				std::cout << "bet: ";
				std::cin >> P_bnew;
				P_bet = P_bet + P_bnew;
			}
			else if (choice == 2) {
				break;
			}
			else {
				std::cout << "1 or 2 �� ����\n";
				goto INPUT;
			}

			//computer turn ��ǻ�Ͱ� �����ϴ� ��츦 ���� �κ�
			if (ddang > 0) {
				if (prob < 95) {
					ai = 1;
					C_bnew = 700;
					C_bet = C_bet + C_bnew;
				}
				else {
					ai = 2;
					break;
				}
			}
			else if (ggut && ddang == 0) {
				if (ggut == 0) {
					ai = 2;
					break;
				}
				else if (ggut > 8) {
					if (prob < 80) {
						ai = 1;
						C_bnew = 500;
						C_bet = C_bet + C_bnew;
					}
					else {
						ai = 2;
						break;
					}
				}
				else {
					if (prob < 40) {
						ai = 1;
						C_bnew = 300;
						C_bet = C_bet + C_bnew;
					}
					else {
						ai = 2;
						break;
					}
				}
			}
		}

		//result
		if (choice == 2 && ai == 1) // computer win
		{
			C_money = C_money + P_bet;
			P_money = P_money - P_bet;
			std::cout << "Player Die\n";
			std::cout << "Computer Win\n";
			std::cout << "Computer card 1 : " << pae1[a] << "\n" << "Computer card 2 : " << pae2[b] << "\n";
			std::cout << "P_money : " << P_money << "\n" << "C_money : " << C_money;
		}
		else if (choice == 1 && ai == 2) // player win
		{
			C_money = C_money - C_bet;
			P_money = P_money + C_bet;
			std::cout << "Computer Die\n";
			std::cout << "Player Win\n";
			std::cout << "Computer card 1 : " << pae1[a] << "\n" << "Computer card 2 : " << pae2[b] << "\n";
			std::cout << "P_money : " << P_money << "\n" << "C_money : " << C_money;
		}
		else if (choice == 2 && ai == 2) //draw
		{
			std::cout << "Player Die\n";
			std::cout << "Computer Die\n";
			std::cout << "Draw";
		}
		else			//compare (�� �� call �� ���)
		{
			if (dang > ddang || gut > ggut || dang > ggut) {       //player win
				C_money = C_money - C_bet;
				P_money = P_money + C_bet;
				std::cout << "Computer Call\n";
				std::cout << "Computer Bet: " << C_bnew << "\n";
				std::cout << "Player Win\n";
				std::cout << "Computer card 1 : " << pae1[a] << "\n" << "Computer card 2 : " << pae2[b] << "\n";
				std::cout << "P_money : " << P_money << "\n" << "C_money : " << C_money;
			}
			else if (ddang > dang || ggut > gut || ddang > gut) {         //computer win
				C_money = C_money + P_bet;
				P_money = P_money - P_bet;
				std::cout << "Computer Call\n";
				std::cout << "Computer Bet: " << C_bnew << "\n";
				std::cout << "Computer Win\n";
				std::cout << "Computer card 1 : " << pae1[a] << "\n" << "Computer card 2 : " << pae2[b] << "\n";
				std::cout << "P_money : " << P_money << "\n" << "C_money : " << C_money;
			}
		}
		std::cout << "\n1�� �Է��Ͽ� �ٽ� ����(�����ϱ� ���ϸ� 0�� �Է�):";

		int x;
		std::cin >> x;
		if (x == 0)
			break;
	}

	return 0;
}