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

	// ���� ������ 2���� �迭(matrix_poly) �����Ҵ�
	matrix_poly = (char**)malloc(sizeof(char*) * 2);
	for (i = 0; i < 2; i++)
		matrix_poly[i] = (char*)malloc(sizeof(char)*len);

	for (i = 0; i < 2; i++)	// matrix_poly �ʱ�ȭ
		memset(matrix_poly[i], 0, sizeof(char)*len);

	printf("��ȣ ���: ");
	while (plain[l] != 10) {

		for (i = 0; i < 5; i++) {
			for (j = 0; j < 5; j++) {
				if (plain[l] == 106)
					plain[l] = 105;

				if (table_poly[i][j] == plain[l]) {
					//printf("%d%d ", i + 1, j + 1);  1�� ġȯ
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

	printf("��ȣ ���: ");
	// ���� ������ 2���� �迭(matrix_poly) �����Ҵ�
	matrix_poly = (char**)malloc(sizeof(char*) * 2);
	for (i = 0; i < 2; i++)
		matrix_poly[i] = (char*)malloc(sizeof(char)*(len/2));

	for (i = 0; i < 2; i++)	// matrix_poly �ʱ�ȭ
		memset(matrix_poly[i], 0, sizeof(char)*(len/2));

	for (i = 0; i < 2; i++)
		for (j = 0; j < len/2 ; j++)
			matrix_poly[i][j] = cipher[n++];

	for (i = 0; i < len / 2; i++) {
		row = matrix_poly[0][i] - 48;
		col = matrix_poly[1][i] - 48;
		if (row == 2 && col == 4) // I/J �� ��� ���� ó��
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

	printf("Polybius ��ȣ ����");
	while (1) {

		system("cls");
		printf("1) Polybius ��ȣȭ\n2) Polybius ��ȣȭ\n3) Polybius ����\n\n");
		printf("�޴� ����: ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			int i = 0;

			getchar();
			printf("��ȣȭ�� �� �Է�: \n");
			fgets(plaintext_poly, sizeof(plaintext_poly), stdin);

			// �Է� ���� ���ڿ� ���� �� �ҹ��� ó��
			while (plaintext_poly[i] != 10) {
				plaintext_poly[i] = tolower(plaintext_poly[i]);
				i += 1;
			}
			// �� �κп� �����÷ο� ����ó�� �߰��ؾ���

			fputc('\n', stdout);
			Encrypt_Poly(plaintext_poly);
			fputc('\n', stdout);
			_getch();
		}
		else if (choice == 2) {
			int i = 0,
				j = 0;
			getchar();
			printf("��ȣȭ�� ��ȣ�� �Է�: \n");
			fgets(cipher_poly, sizeof(cipher_poly), stdin);

			// �Է¹��� ��ȣ�� �� ����(space)���� 
			while (cipher_poly[i] != 10) {
				if (cipher_poly[i] == 32)
					i += 1;
				ciphertext_poly[j] = cipher_poly[i];
				i += 1;
				j += 1;
			}
			ciphertext_poly[j] = 10;
			ciphertext_poly[j + 1] = 0;
			// �� �κп� �����÷ο� ����ó�� �߰��ؾ���

			fputc('\n', stdout);
			Decrypt_Poly(ciphertext_poly);
			fputc('\n', stdout);
			_getch();
		}
		else if (choice == 3) {
			printf("Polybius ��ȣ ����\n\n");
			break;
		}
		else {
			printf("�޴� �Է� �� ����\n\n");
			getchar();
			continue;
		}
	}
}