#include "cruptos.h"

void Encrypt_Squre(char *plaintext_squre, int key_squre, char* key_array) {

	char* plain = plaintext_squre;
	char* key_arr = key_array;
	char** matrix_squre;
	int len = strlen(plain),
		i = 0,
		j = 0,
		n = 0,
		x = 1,
		row = len / key_squre + 2,
		col = key_squre;
	// ���� ������ 2���� �迭(matrix_squre) �����Ҵ�
	matrix_squre = (char**)malloc(sizeof(char*) *row);
	for (i = 0; i < row; i++)
		matrix_squre[i] = (char*)malloc(sizeof(char)*col);

	for (i = 0; i < row; i++)	// matrix_squre �ʱ�ȭ
		memset(matrix_squre[i], 0, sizeof(char)*col);

	for (i = 0; i < col; i++)
		matrix_squre[0][i] = key_arr[i];

	for (i = 1; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (plain[n] == 10)
				break;
			matrix_squre[i][j] = plain[n];
			n += 1;
		}
		if (plain[n] == 10)
			break;
	}
	
	printf("��ȣ ���: ");
	/* square matrix �迭 ���
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (i == 0)
				printf("%d", matrix_squre[i][j]-48);
			else
				printf("%c", matrix_squre[i][j]);
		}
		putc('\n', stdout);
	}*/

	i = 0;
	while (x <= key_squre) {
		for (j = 0; j < col; j++) {
			if ((matrix_squre[0][j] - 48) == x) {
				for (i = 1; i < row; i++) {
					if (matrix_squre[i][j] == 0)
						continue;
					printf("%c", matrix_squre[i][j]);
				}
				x++;
			}
		}
	}
	
	for (i = 0; i < row; i++)
		free(matrix_squre[i]);
	free(matrix_squre);
}

void Decrypt_Squre(char* ciphertext_squre, int key_squre, char* key_array) {

	char* cipher = ciphertext_squre;
	char* key_arr = key_array;
	char** matrix_squre;
	int len = strlen(cipher),
		i = 0,
		j = 0,
		n = 0,
		x = 1,
		row = len / key_squre + 1,
		col = key_squre;
	// ���� ������ 2���� �迭(matrix_squre) �����Ҵ�
	matrix_squre = (char**)malloc(sizeof(char*) *row);
	for (i = 0; i < row; i++)
		matrix_squre[i] = (char*)malloc(sizeof(char)*col);

	for (i = 0; i < row; i++)	// matrix_squre �ʱ�ȭ
		memset(matrix_squre[i], 0, sizeof(char)*col);

	for (i = 0; i < col; i++)
		matrix_squre[0][i] = key_arr[i];

	while (x <= key_squre) {
		for (i = 0; i < col; i++) {
			if ((matrix_squre[0][i] - 48) == x) {
				for (j = 1; j < row; j++) {
					matrix_squre[j][i] = cipher[n];
					n += 1;
				}
				x++;
			}
		}
	}

	printf("��ȣ ���: ");
	for (i = 1; i < row; i++) {
		for(j = 0; j < col; j++) {
			if (matrix_squre[i][j] == 0)
				continue;
			else
				printf("%c", matrix_squre[i][j]);
		}
	}

	for (i = 0; i < row; i++)
		free(matrix_squre[i]);
	free(matrix_squre);
}

void SquareMatrix() {

	char plaintext_squre[MAX_PLAIN],
		ciphertext_squre[MAX_CIPHER],
		key_arr[32];
	int choice,
		key_squre;
		
	printf("Square matrix ��ȣ ����");
	while (1) {

		system("cls");
		printf("1) Square matrix ��ȣȭ\n2) Square matrix ��ȣȭ\n3) Square matrix ����\n\n");
		printf("�޴� ����: ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			int i = 0,
				j = 0;

			getchar();
			printf("��ȣȭ�� �� �Է�([a-zA-Z]): \n");
			fgets(plaintext_squre, sizeof(plaintext_squre), stdin);

			// �Է� ���� ���ڿ� ���� �� �ҹ��� ó��
			while (plaintext_squre[i] != 10) {
				plaintext_squre[i] = tolower(plaintext_squre[i]);
				i += 1;
			}

			// �������� 
			i = 0;
			while (ciphertext_squre[i] != 10) {
				if (ciphertext_squre[i] == 32)
					memmove(ciphertext_squre + i, ciphertext_squre + i + 1, strlen(ciphertext_squre) - i);
				i += 1;
			}
			// �� �κп� �����÷ο� ����ó�� �߰��ؾ���

			printf("\nŰ �Է�(0���� ū ����): ");
			scanf_s("%d", &key_squre);

			/* Ű ���� �߰�
			if (key_squre > 26 || key_squre < 0) {
				fputs("key ����: 0 ~ 26\n", stderr);
				continue;
			}*/

			getchar();
			printf("\nŰ �迭 �Է�(�Է��� ���� ���� ���� ���� ����): ");
			fgets(key_arr, sizeof(key_arr), stdin);
			/* �Է¹��� ��ȣ�� �� ����(space)���� 
			while (key_arr[i] != 10) {
				if (key_arr[i] == 32)
					i += 1;
				key_array[j] = key_arr[i];
				i += 1;
				j += 1;
			}
			key_array[j] = 10;
			key_array[j + 1] = 0;
			*/

			fputc('\n', stdout);
			Encrypt_Squre(plaintext_squre, key_squre, key_arr);
			fputc('\n', stdout);
			_getch();
		}
		else if (choice == 2) {
			int i = 0;
			
			getchar();
			printf("��ȣȭ�� ��ȣ�� �Է�([a-zA-Z]): \n");
			fgets(ciphertext_squre, sizeof(ciphertext_squre), stdin);

			// �Է� ���� ���ڿ� ���� �ҹ��� ó�� �ؾ���
			while (ciphertext_squre[i] != 10) {
				ciphertext_squre[i] = tolower(ciphertext_squre[i]);
				i += 1;
			}

			i = 0;
			while (ciphertext_squre[i] != 10) {
				if (ciphertext_squre[i] == 32)
					memmove(ciphertext_squre + i, ciphertext_squre + i + 1, strlen(ciphertext_squre) - i);
				i += 1;
			}

			// �� �κп� �����÷ο� ����ó�� �߰��ؾ���

			printf("\nŰ �Է�(0���� ū ����): ");
			scanf_s("%d", &key_squre);

			/* Ű ���� �߰�
			if (key_cae > 26 || key_cae < 0) {
				fputs("key ����: 0 ~ 26\n", stderr);
				continue;
			}*/

			getchar();
			printf("\nŰ �迭 �Է�(�Է��� ���� ���� ���� ���� ����): ");
			fgets(key_arr, sizeof(key_arr), stdin);
			/* �Է¹��� ��ȣ�� �� ����(space)����
			while (key_arr[i] != 10) {
			if (key_arr[i] == 32)
			i += 1;
			key_array[j] = key_arr[i];
			i += 1;
			j += 1;
			}
			key_array[j] = 10;
			key_array[j + 1] = 0;
			*/

			fputc('\n', stdout);
			Decrypt_Squre(ciphertext_squre, key_squre, key_arr);
			fputc('\n', stdout);
			_getch();
		}
		else if (choice == 3) {
			printf("Square matrix ��ȣ ����\n\n");
			break;
		}
		else {
			printf("�޴� �Է� �� ����\n\n");
			getchar();
			continue;
		}
	}
	
}