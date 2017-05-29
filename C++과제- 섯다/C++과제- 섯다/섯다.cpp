#include <iostream>
#include <cstdlib>
#include <time.h>

int main()
{
	int pae1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int pae2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };	//1,3,8 광
	int P_bet = 300, C_bet = 300;						//초기 배팅금액
	int P_money = 10000, C_money = 10000;				//보유 금액
	int choice = 0, ai = 0;								//player computer 선택
	int ddang = 0, ggut = 0;							//컴퓨터 끗 과 땡
	int dang = 0, gut = 0;								//플레이어 끗 과 땡
	int P_bnew = 0, C_bnew = 0;							//배팅 금액
	int i = 0, a = 0, c = 0;
	int j = 0, b = 0;
	int prob = 0;										//확률변수

	while (true)
	{
		// 매 판 시작 할 때 소모되는 기본 배팅금액
		C_bet = 300;
		P_bet = 300;

		//각 변수 정의
		srand(time(NULL));
		i = rand() % 10;
		j = rand() % 10;
		a = rand() % 10;
		b = rand() % 10;
		prob = rand() % 100 + 1;
		std::cout << "\n-------------------------------------\n";
		std::cout << "기본 배팅금액 >> 300" << "\n";
		std::cout << "Player card 1 : " << pae1[i] << "\n" <<
			"Player card 2 : " << pae2[j] << "\n";

		//player card
		if (pae1[i] == pae2[j]) {
			dang = pae1[i] + 10;
			std::cout << dang - 10 << "땡\n";
			gut = dang;
		}
		else {
			gut = (pae1[i] + pae2[j]) % 10;
			std::cout << gut << "끗\n";
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
				std::cout << "1 or 2 중 선택\n";
				goto INPUT;
			}

			//computer turn 컴퓨터가 선택하는 경우를 나눈 부분
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
		else			//compare (둘 다 call 한 경우)
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
		std::cout << "\n1을 입력하여 다시 시작(종료하길 원하면 0을 입력):";

		int x;
		std::cin >> x;
		if (x == 0)
			break;
	}

	return 0;
}