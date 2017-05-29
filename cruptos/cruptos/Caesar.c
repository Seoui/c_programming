#include "cruptos.h"

void Encrypt_Caesar(char *plaintext_cae, int key_cae) {

	char *plain = plaintext_cae;
	int i = 0;

	printf("��ȣ ���: ");
	while (plain[i] != 10) {	// ���� new line �� ���� �� ���� �ݺ��Ѵ�.
		if (plain[i] == 32) {	// ���ڰ� ����(space)�� ���
			i += 1;
		}
		if (plain[i] + key_cae > 122) {		// (���� + key) �� 'z'���� Ŭ ���
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

	printf("��ȣ ���: ");
	// �ƿ� ���ڿ� ������ ��� ���� �޴°� �����ؾ��� 
	while (cipher[i] != 10) {	// ��ȣ���� new line�� ���� �� ����
		if (cipher[i] == 32) {	// ���ڰ� ����(space)�� ���
			i += 1;
		}
		if (cipher[i] - key_cae < 97) {		// (���� - key)�� 'a'���� ���� ��� 
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

	printf("\nCaesar ��ȣ ����\n");
	while (1) {
		system("cls");
		printf("1) Caesar ��ȣȭ\n2) Caesar ��ȣȭ\n3) Caesar ����\n\n");
		printf("�޴� ����: ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			int i = 0;

			getchar();
			printf("��ȣȭ�� �� �Է�([a-zA-Z]): \n");
			fgets(plaintext_cae, sizeof(plaintext_cae), stdin);

			// �Է� ���� ���ڿ� ���� �� �ҹ��� ó��
			while (plaintext_cae[i] != 10) {
				plaintext_cae[i] = tolower(plaintext_cae[i]);
				i += 1;
			}
			// �� �κп� �����÷ο� ����ó�� �߰��ؾ���

			printf("\nŰ �Է�(0~26 ������ ����): ");
			scanf_s("%d", &key_cae);
			if (key_cae > 26 || key_cae < 0) {
				fputs("key ����: 0 ~ 26\n", stderr);
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
			printf("��ȣȭ�� ��ȣ�� �Է�([a-zA-Z]): \n");
			fgets(ciphertext_cae, sizeof(ciphertext_cae), stdin);

			// �Է� ���� ���ڿ� ���� �ҹ��� ó�� �ؾ���
			while (ciphertext_cae[i] != 10) {
				ciphertext_cae[i] = tolower(ciphertext_cae[i]);
				i += 1;
			}
			// �� �κп� �����÷ο� ����ó�� �߰��ؾ���

			printf("\nŰ �Է�(0~26 ������ ����): ");
			scanf_s("%d", &key_cae);
			if (key_cae > 26 || key_cae < 0) {
				fputs("key ����: 0 ~ 26\n", stderr);
				continue;
			}
			fputc('\n', stdout);
			Decrypt_Caesar(ciphertext_cae, key_cae);
			fputc('\n', stdout);
			_getch();
		}
		else if (choice == 3) {
			printf("Caesar ��ȣ ����\n\n");
			break;
		}
		else {
			printf("�޴� �Է� �� ����\n\n");
			getchar();
			continue;
		}
	}
}