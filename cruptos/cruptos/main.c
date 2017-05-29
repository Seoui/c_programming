#include "cruptos.h"

int main() {

	int choice;
	
	printf("CRUPTOS - encrypt & decrypt program\n\n");
	printf("By  Hong Sungki\n\n");
	printf("Start of programming : 2017. 4. 8\n\n");
	printf("End of programming : 2017. 5. 28\n\n");
	printf("About Caesar, Vigenere, Play fair, Rail fence, Polybius, Square matrix\n");
	printf("INFORMATION SECURITY and CRYPTOGRAPHY\n\n");

	while (1) {
		printf("1) Caesar 암호\n");
		printf("2) Vigenere 암호\n");
		printf("3) Playfair 암호\n");
		printf("4) Railfence 암호\n");
		printf("5) Polybius 암호\n");
		printf("6) Square matrix 암호\n");
		printf("7) 종료\n\n");
		printf("메뉴 선택: ");

		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			Caesar();
			break;
		case 2:
			Vigenere();
			break;
		case 3:
			Playfair();
			break;
		case 4:
			Railfence();
			break;
		case 5:
			Polybius();
			break;
		case 6:
			SquareMatrix();
			break;
		case 7:
			printf("CRUPTOS 암호&복호 프로그램 종료\n");
			exit(0);
		default:
			printf("입력 오류\n");
			break;
		}
	}

	return 0;
}