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
		printf("1) Caesar ��ȣ\n");
		printf("2) Vigenere ��ȣ\n");
		printf("3) Playfair ��ȣ\n");
		printf("4) Railfence ��ȣ\n");
		printf("5) Polybius ��ȣ\n");
		printf("6) Square matrix ��ȣ\n");
		printf("7) ����\n\n");
		printf("�޴� ����: ");

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
			printf("CRUPTOS ��ȣ&��ȣ ���α׷� ����\n");
			exit(0);
		default:
			printf("�Է� ����\n");
			break;
		}
	}

	return 0;
}