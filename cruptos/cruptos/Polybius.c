#include "cruptos.h"

void Encrypt_Poly(char *plaintext_poly) {

	const char table_poly[5][5] = {
		{ 'a', 'b', 'c', 'd', 'e' },
		{ 'f', 'g', 'h', 'i', 'k' },
		{ 'l', 'm', 'n', 'o', 'p' },
		{ 'q', 'r', 's', 't', 'u' },
		{ 'v', 'w', 'x', 'y', 'z' },
	};
	char** matrix_poly;
	char* plain = plaintext_poly;
	int len = strlen(plain),
		l = 0,
		i = 0,
		j = 0,
		n = 0;

	// 평문을 저장할 2차원 배열(matrix_poly) 동적할당
	matrix_poly = (char**)malloc(sizeof(char*) * 2);
	for (i = 0; i < 2; i++)
		matrix_poly[i] = (char*)malloc(sizeof(char)*len);

	for (i = 0; i < 2; i++)	// matrix_poly 초기화
		memset(matrix_poly[i], 0, sizeof(char)*len);

	printf("암호 결과: ");
	while (plain[l] != 10) {

		for (i = 0; i < 5; i++) {
			for (j = 0; j < 5; j++) {
				if (plain[l] == 106)
					plain[l] = 105;

				if (table_poly[i][j] == plain[l]) {
					//printf("%d%d ", i + 1, j + 1);  1차 치환
					matrix_poly[0][n] = i + 1;
					matrix_poly[1][n] = j + 1;
					n += 1;
				}
			}
		}
		l++;
	}
	putc('\n', stdout);
	for (i = 0; i < 2; i++) {
		for (j = 0; j < len-1; j+=2) {
			printf("%d%d ", matrix_poly[i][j], matrix_poly[i][j+1]);
		}
	}

	for (i = 0; i < 2; i++)
		free(matrix_poly[i]);
	free(matrix_poly);
}

void Decrypt_Poly(char *ciphertext_poly) {
	
	const char table_poly[5][5] = {
		{ 'a', 'b', 'c', 'd', 'e' },
		{ 'f', 'g', 'h', 'i', 'k' },
		{ 'l', 'm', 'n', 'o', 'p' },
		{ 'q', 'r', 's', 't', 'u' },
		{ 'v', 'w', 'x', 'y', 'z' },
	};
	char** matrix_poly;
	char* cipher = ciphertext_poly;
	int len = strlen(cipher),
		l = 0,
		i = 0,
		j = 0,
		n = 0,
		row,
		col;

	printf("복호 결과: ");
	// 평문을 저장할 2차원 배열(matrix_poly) 동적할당
	matrix_poly = (char**)malloc(sizeof(char*) * 2);
	for (i = 0; i < 2; i++)
		matrix_poly[i] = (char*)malloc(sizeof(char)*(len/2));

	for (i = 0; i < 2; i++)	// matrix_poly 초기화
		memset(matrix_poly[i], 0, sizeof(char)*(len/2));

	for (i = 0; i < 2; i++)
		for (j = 0; j < len/2 ; j++)
			matrix_poly[i][j] = cipher[n++];

	for (i = 0; i < len / 2; i++) {
		row = matrix_poly[0][i] - 48;
		col = matrix_poly[1][i] - 48;
		if (row == 2 && col == 4) // I/J 일 경우 따로 처리
			printf("I/J ");
		else
			printf("%c ", toupper(table_poly[row - 1][col - 1]));
	}


	for (i = 0; i < 2; i++)
		free(matrix_poly[i]);
	free(matrix_poly);
}

void Polybius() {
	
	char plaintext_poly[MAX_PLAIN],
		cipher_poly[MAX_CIPHER],
		ciphertext_poly[MAX_CIPHER];

	const char table_poly[5][5] = {
		{ 'a', 'b', 'c', 'd', 'e' },
		{ 'f', 'g', 'h', 'i', 'k' },
		{ 'l', 'm', 'n', 'o', 'p' },
		{ 'q', 'r', 's', 't', 'u' },
		{ 'v', 'w', 'x', 'y', 'z' },
	};
	int choice;

	printf("Polybius 암호 시작");
	while (1) {

		system("cls");
		printf("1) Polybius 암호화\n2) Polybius 복호화\n3) Polybius 종료\n\n");
		printf("메뉴 선택: ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			int i = 0;

			getchar();
			printf("암호화할 평문 입력: \n");
			fgets(plaintext_poly, sizeof(plaintext_poly), stdin);

			// 입력 받은 문자열 전부 다 소문자 처리
			while (plaintext_poly[i] != 10) {
				plaintext_poly[i] = tolower(plaintext_poly[i]);
				i += 1;
			}
			// 이 부분에 오버플로우 예외처리 추가해야함

			fputc('\n', stdout);
			Encrypt_Poly(plaintext_poly);
			fputc('\n', stdout);
			_getch();
		}
		else if (choice == 2) {
			int i = 0,
				j = 0;
			getchar();
			printf("복호화할 암호문 입력: \n");
			fgets(cipher_poly, sizeof(cipher_poly), stdin);

			// 입력받은 암호문 중 공백(space)제거 
			while (cipher_poly[i] != 10) {
				if (cipher_poly[i] == 32)
					i += 1;
				ciphertext_poly[j] = cipher_poly[i];
				i += 1;
				j += 1;
			}
			ciphertext_poly[j] = 10;
			ciphertext_poly[j + 1] = 0;
			// 이 부분에 오버플로우 예외처리 추가해야함

			fputc('\n', stdout);
			Decrypt_Poly(ciphertext_poly);
			fputc('\n', stdout);
			_getch();
		}
		else if (choice == 3) {
			printf("Polybius 암호 종료\n\n");
			break;
		}
		else {
			printf("메뉴 입력 값 오류\n\n");
			getchar();
			continue;
		}
	}
}