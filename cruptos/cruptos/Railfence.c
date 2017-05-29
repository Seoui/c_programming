#include "cruptos.h"

void Encrypt_Rail(char *plaintext_rail, int depth) {

	char *plain = plaintext_rail;
	int i = 0,
		j = 0,
		m = -1,
		n = -1,
		num = 1,
		len = strlen(plain);
	char **matrix_rail;

	printf("��ȣ ���: ");
	// depth == 1 �� ���� ��� ���� ó����
	if (depth == 1) {
		for (i = 0; i < len; i++)
		{
			if (plain[i] == 32)
				printf("");
			else
				printf("%c", plain[i]);
		}
		return;
	}

	// ���� ������ 2���� �迭(matrix_rail) �����Ҵ�
	matrix_rail = (char**)malloc(sizeof(char*)*depth);
	for (i = 0; i < depth; i++)
		matrix_rail[i] = (char*)malloc(sizeof(char)*len);

	for (i = 0; i < depth; i++)	// matrix_rail �ʱ�ȭ
		memset(matrix_rail[i], 0, sizeof(char)*len);

	// matrix_rail�� ��Ģ�� �°� ���ڿ�(plain) �Է�
	while (plain[n] != 10) {

		if (m == depth - 1)
			num = -1;
		else if (m == 0)
			num = 1;

		m += num;
		n += 1;

		if (plain[n] == 32)
			matrix_rail[m][n] = plain[++n];
		else
			matrix_rail[m][n] = plain[n];
	}

	// matrix_rail ���
	for (i = 0; i < depth; i++) {
		for (j = 0; j < len; j++) {
			if (matrix_rail[i][j] == 0 || matrix_rail[i][j] == 10)
				printf("");
			else
				printf("%c", (matrix_rail[i][j]));
		}
	}

	for (i = 0; i < depth; i++)
		free(matrix_rail[i]);
	free(matrix_rail);

}

void Decrypt_Rail(char *ciphertext_rail, int depth) {
	// depth: 2
	// plaintext: We are discovered
	// ciphertext: waeicvrderdsoee
	char *cipher = ciphertext_rail;
	int i = 0,
		j = 0,
		m = -1,
		n = -1,
		num = 1,
		len = strlen(cipher);
	char **matrix_rail;

	// ���� ������ 2���� �迭(matrix_rail) �����Ҵ�
	matrix_rail = (char**)malloc(sizeof(char*)*depth);
	for (i = 0; i < depth; i++)
		matrix_rail[i] = (char*)malloc(sizeof(char)*len);

	for (i = 0; i < depth; i++)	// matrix_rail �ʱ�ȭ
		memset(matrix_rail[i], 0, sizeof(char)*len);

	// matrix_rail�� ��Ģ�� �°� ���ڿ�(cipher) �Է�
	while (cipher[n] != 10) {

		if (m == depth - 1)
			num = -1;
		else if (m == 0)
			num = 1;

		m += num;
		n += 1;

		matrix_rail[m][n] = cipher[n];
	}

	n = 0;
	for (i = 0; i < depth; i++) {
		for (j = 0; j < len - 1; j++) {
			if (matrix_rail[i][j] == 0)
				continue;
			else
				matrix_rail[i][j] = cipher[n++];
		}
	}

	n = 0;
	m = 0;
	printf("��ȣ ���: ");
	while (matrix_rail[m][n] != 10) {

		if (m == depth - 1)
			num = -1;
		else if (m == 0)
			num = 1;

		printf("%c ", matrix_rail[m][n]);

		m += num;
		n += 1;
	}
	putc('\n', stdout);

	for (i = 0; i < depth; i++)
		free(matrix_rail[i]);
	free(matrix_rail);
}

void Railfence() {
	// depth: 2
	// plaintext: We are discovered
	// ciphertext: waeicvrderdsoee

	char plaintext_rail[MAX_PLAIN],
		ciphertext_rail[MAX_CIPHER];
	int depth,
		choice;

	printf("Railfence ��ȣ ����\n");
	while (1) {
		system("cls");
		printf("1) Railfence ��ȣȭ\n2) Railfence ��ȣȭ\n3) Railfence ����\n\n");
		printf("�޴� ����: ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			int i = 0;

			getchar();
			printf("��ȣȭ�� �� �Է�([a-zA-Z]): \n");
			fgets(plaintext_rail, sizeof(plaintext_rail), stdin);

			// �Է� ���� ���ڿ� ���� �� �ҹ��� ó��
			while (plaintext_rail[i] != 10) {
				plaintext_rail[i] = tolower(plaintext_rail[i]);
				i += 1;
			}
			// �� �κп� �����÷ο� ����ó�� �߰��ؾ���

			printf("\n���� �Է�(0���� ū ����): ");
			scanf_s("%d", &depth);
			fputc('\n', stdout);

			// depth ���� ����ó��
			if (depth <= 0) {
				fputs("depth ������ 0���� Ŀ����\n", stderr);
				continue;
			}

			Encrypt_Rail(plaintext_rail, depth);
			fputc('\n', stdout);
			_getch();
		}
		else if (choice == 2) {
			int i = 0;

			getchar();
			printf("��ȣȭ�� ��ȣ�� �Է�([a-zA-Z]): \n");
			fgets(ciphertext_rail, sizeof(ciphertext_rail), stdin);

			// �Է� ���� ���ڿ� ���� �ҹ��� ó�� �ؾ���
			while (ciphertext_rail[i] != 10) {
				ciphertext_rail[i] = tolower(ciphertext_rail[i]);
				i += 1;
			}
			// �� �κп� �����÷ο� ����ó�� �߰��ؾ���

			printf("\nŰ �Է�(0���� ū ����): ");
			scanf_s("%d", &depth);
			fputc('\n', stdout);

			// depth ���� ����ó��
			if (depth <= 0) {
				fputs("depth ������ 0���� Ŀ����\n", stderr);
				continue;
			}

			Decrypt_Rail(ciphertext_rail, depth);
			fputc('\n', stdout);
			_getch();
		}
		else if (choice == 3) {
			printf("Railfence ��ȣ ����\n\n");
			break;
		}
		else {
			printf("�޴� �Է� �� ����\n\n");
			getchar();
			continue;
		}
	}
}