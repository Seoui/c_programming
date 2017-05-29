#include "cruptos.h"

void Encrypt_Play(char *plaintext_play, char *key_play) {

	char *plain = plaintext_play;
	char *key = key_play;
	//char alphabet[25] = "abcdefghiklmnopqrstuvwxyz";
	char alphabet[25] = { 'a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char matrix_play[5][5];
	char tmp = 0;
	int n = 0,
		i = 0,
		j = 0,
		x = 0,
		y = 1;

	// 입력 받은 키와 5x5 행렬 부분
	while (key[n] != 10) {
		for (i = 0; i < 25; i++) {
			if (alphabet[i] == key[n]) {
				alphabet[i] = 48;
				n++;
			}
		}
	}
	strcat_s(key, 100, alphabet);

	n = 0;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (key[n] == 48 || key[n] == 10) {
				n += 1;
				j -= 1;
				continue;
			}
			else {
				matrix_play[i][j] = key[n];
				n += 1;
			}
		}
	}

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%c ", matrix_play[i][j]);
		}
		putc('\n', stdout);
	}
	putc('\n', stdout);

	// 평문 두 개씩 분리 
	while ((plain[x] != 10) && (plain[y] != 10)) {
		if (plain[x] == plain[y]) {
			memmove(plain + y + 1, plain + y, strlen(plain) - y + 1);
			plain[y] = 'x';
		}
		x += 2;
		y += 2;
	}

	printf("암호화 결과: ");
	// 두 개씩 분리된 평문을 5x5 행렬의 규칙에 맞게 치환
	x = 0;
	y = 1;
	int fst_row,
		fst_col,
		snd_row,
		snd_col;

	while ((plain[x] != 10) && (plain[y] != 10)) {

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (matrix_play[i][j] == plain[x]) {
					fst_row = i;
					fst_col = j;
				}
			}
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (matrix_play[i][j] == plain[y]) {
					snd_row = i;
					snd_col = j;
				}
			}
		}

		if (fst_row == snd_row) {
			if (fst_col == 4)
				fst_col = -1;
			else if (snd_col == 4)
				snd_col = -1;
			printf("%c%c", matrix_play[fst_row][fst_col + 1], matrix_play[snd_row][snd_col + 1]);
		}
		else if (fst_col == snd_col) {
			if (fst_row == 4)
				fst_row = -1;
			else if (snd_row == 4)
				snd_row = -1;
			printf("%c%c", matrix_play[fst_row + 1][fst_col], matrix_play[snd_row + 1][snd_col]);
		}
		else {
			printf("%c%c", matrix_play[fst_row][snd_col], matrix_play[snd_row][fst_col]);
		}

		x += 2;
		y += 2;
	}
	putc('\n', stdout);
}

void Decrypt_Play(char *ciphertext_play, char *key_play) {

	char *cipher = ciphertext_play;
	char *key = key_play;
	char alphabet[25] = { 'a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char matrix_play[5][5];
	int i = 0,
		n = 0,
		j = 0,
		x = 0,
		y = 1,
		fst_row,
		fst_col,
		snd_row,
		snd_col;

	while (key[n] != 10) {
		for (i = 0; i < 25; i++) {
			if (alphabet[i] == key[n]) {
				alphabet[i] = 48;
				n++;
			}
		}
	}
	strcat_s(key, 100, alphabet);

	n = 0;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (key[n] == 48 || key[n] == 10) {
				n += 1;
				j -= 1;
				continue;
			}
			else {
				matrix_play[i][j] = key[n];
				n += 1;
			}
		}
	}

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%c ", matrix_play[i][j]);
		}
		putc('\n', stdout);
	}
	putc('\n', stdout);

	printf("복호화 결과: ");
	while ((cipher[x] != 10) && (cipher[y] != 10)) {

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (matrix_play[i][j] == cipher[x]) {
					fst_row = i;
					fst_col = j;
				}
			}
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (matrix_play[i][j] == cipher[y]) {
					snd_row = i;
					snd_col = j;
				}
			}
		}

		if (fst_row == snd_row) {
			if (fst_col == 0)
				fst_col = 5;
			else if (snd_col == 0)
				snd_col = 5;
			printf("%c%c", matrix_play[fst_row][fst_col - 1], matrix_play[snd_row][snd_col - 1]);
		}
		else if (fst_col == snd_col) {
			if (fst_row == 0)
				fst_row = 5;
			else if (snd_row == 0)
				snd_row = 5;
			printf("%c%c", matrix_play[fst_row - 1][fst_col], matrix_play[snd_row - 1][snd_col]);
		}
		else {
			printf("%c%c", matrix_play[fst_row][snd_col], matrix_play[snd_row][fst_col]);
		}

		x += 2;
		y += 2;
	}
	putc('\n', stdout);
}

void Playfair() {

	char plaintext_play[MAX_PLAIN],
		ciphertext_play[MAX_CIPHER],
		key_play[100];
	int choice;

	printf("\nPlayfair 암호 시작\n");
	while (1) {
		system("cls");
		printf("1) Playfair 암호화\n2) Playfair 복호화\n3) Playfair 종료\n\n");
		printf("메뉴 선택: ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			int i = 0;

			getchar();
			printf("암호화할 평문 입력([a-zA-Z]): \n");
			fgets(plaintext_play, sizeof(plaintext_play), stdin);

			// 입력 받은 문자열 전부 다 소문자 처리
			while (plaintext_play[i] != 10) {
				plaintext_play[i] = tolower(plaintext_play[i]);
				i += 1;
			}
			// 이 부분에 오버플로우 예외처리 추가해야함

			printf("\n키 입력([a-zA-Z]): ");
			fgets(key_play, sizeof(key_play), stdin);

			/*
			if (key_cae > 26 || key_cae < 0) {
			fputs("key 범위: 0 ~ 26\n", stderr);
			continue;
			}
			*/
			fputc('\n', stdout);
			Encrypt_Play(plaintext_play, key_play);
			fputc('\n', stdout);
			_getch();
		}
		else if (choice == 2) {
			int i = 0;

			getchar();
			printf("복호화할 암호문 입력([a-zA-Z]): \n");
			fgets(ciphertext_play, sizeof(ciphertext_play), stdin);

			// 입력 받은 문자열 전부 소문자 처리 해야함
			while (ciphertext_play[i] != 10) {
				ciphertext_play[i] = tolower(ciphertext_play[i]);
				i += 1;
			}
			// 이 부분에 오버플로우 예외처리 추가해야함

			printf("\n키 입력([a-zA-Z]): ");
			fgets(key_play, sizeof(key_play), stdin);

			/*
			if (key_cae > 26 || key_cae < 0) {
			fputs("key 범위: 0 ~ 26\n", stderr);
			continue;
			}
			*/
			fputc('\n', stdout);
			Decrypt_Play(ciphertext_play, key_play);
			fputc('\n', stdout);
			_getch();
		}
		else if (choice == 3) {
			printf("Playfair 암호 종료\n\n");
			break;
		}
		else {
			printf("메뉴 입력 값 오류\n\n");
			getchar();
			continue;
		}
	}
}