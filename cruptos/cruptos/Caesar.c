#include "cruptos.h"

void Encrypt_Caesar(char *plaintext_cae, int key_cae) {

	char *plain = plaintext_cae;
	int i = 0;

	printf("암호 결과: ");
	while (plain[i] != 10) {	// 평문의 new line 을 만날 때 까지 반복한다.
		if (plain[i] == 32) {	// 문자가 공백(space)일 경우
			i += 1;
		}
		if (plain[i] + key_cae > 122) {		// (문자 + key) 가 'z'보다 클 경우
			printf("%c", toupper(plain[i] + key_cae - 122 + 97 - 1));
			i += 1;
		}
		else {
			printf("%c", toupper(plain[i] + key_cae));
			i += 1;
		}
	}
	putc('\n', stdout);
}

void Decrypt_Caesar(char *ciphertext_cae, int key_cae) {

	char *cipher = ciphertext_cae;
	int i = 0;

	printf("복호 결과: ");
	// 아예 문자열 제외한 모든 문자 받는거 제외해야함 
	while (cipher[i] != 10) {	// 암호문의 new line을 만날 때 까지
		if (cipher[i] == 32) {	// 문자가 공백(space)일 경우
			i += 1;
		}
		if (cipher[i] - key_cae < 97) {		// (문자 - key)가 'a'보다 작을 경우 
			printf("%c", tolower(cipher[i] - key_cae - 97 + 122 + 1));
			i += 1;
		}
		else {
			printf("%c", tolower(cipher[i] - key_cae));
			i += 1;
		}
	}
	putc('\n', stdout);
}

void Caesar() {

	char plaintext_cae[MAX_PLAIN],
		 ciphertext_cae[MAX_CIPHER];
	int key_cae,
		choice;

	printf("\nCaesar 암호 시작\n");
	while (1) {
		system("cls");
		printf("1) Caesar 암호화\n2) Caesar 복호화\n3) Caesar 종료\n\n");
		printf("메뉴 선택: ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			int i = 0;

			getchar();
			printf("암호화할 평문 입력([a-zA-Z]): \n");
			fgets(plaintext_cae, sizeof(plaintext_cae), stdin);

			// 입력 받은 문자열 전부 다 소문자 처리
			while (plaintext_cae[i] != 10) {
				plaintext_cae[i] = tolower(plaintext_cae[i]);
				i += 1;
			}
			// 이 부분에 오버플로우 예외처리 추가해야함

			printf("\n키 입력(0~26 사이의 정수): ");
			scanf_s("%d", &key_cae);
			if (key_cae > 26 || key_cae < 0) {
				fputs("key 범위: 0 ~ 26\n", stderr);
				continue;
			}
			fputc('\n', stdout);

			Encrypt_Caesar(plaintext_cae, key_cae);
			fputc('\n', stdout);
			_getch();
		}
		else if (choice == 2) {
			int i = 0;

			getchar();
			printf("복호화할 암호문 입력([a-zA-Z]): \n");
			fgets(ciphertext_cae, sizeof(ciphertext_cae), stdin);

			// 입력 받은 문자열 전부 소문자 처리 해야함
			while (ciphertext_cae[i] != 10) {
				ciphertext_cae[i] = tolower(ciphertext_cae[i]);
				i += 1;
			}
			// 이 부분에 오버플로우 예외처리 추가해야함

			printf("\n키 입력(0~26 사이의 정수): ");
			scanf_s("%d", &key_cae);
			if (key_cae > 26 || key_cae < 0) {
				fputs("key 범위: 0 ~ 26\n", stderr);
				continue;
			}
			fputc('\n', stdout);
			Decrypt_Caesar(ciphertext_cae, key_cae);
			fputc('\n', stdout);
			_getch();
		}
		else if (choice == 3) {
			printf("Caesar 암호 종료\n\n");
			break;
		}
		else {
			printf("메뉴 입력 값 오류\n\n");
			getchar();
			continue;
		}
	}
}