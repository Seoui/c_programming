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

	printf("암호 결과: ");
	// depth == 1 일 때의 경우 따로 처리함
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

	// 평문을 저장할 2차원 배열(matrix_rail) 동적할당
	matrix_rail = (char**)malloc(sizeof(char*)*depth);
	for (i = 0; i < depth; i++)
		matrix_rail[i] = (char*)malloc(sizeof(char)*len);

	for (i = 0; i < depth; i++)	// matrix_rail 초기화
		memset(matrix_rail[i], 0, sizeof(char)*len);

	// matrix_rail에 규칙에 맞게 문자열(plain) 입력
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

	// matrix_rail 출력
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

	// 평문을 저장할 2차원 배열(matrix_rail) 동적할당
	matrix_rail = (char**)malloc(sizeof(char*)*depth);
	for (i = 0; i < depth; i++)
		matrix_rail[i] = (char*)malloc(sizeof(char)*len);

	for (i = 0; i < depth; i++)	// matrix_rail 초기화
		memset(matrix_rail[i], 0, sizeof(char)*len);

	// matrix_rail에 규칙에 맞게 문자열(cipher) 입력
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
	printf("복호 결과: ");
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

	printf("Railfence 암호 시작\n");
	while (1) {
		system("cls");
		printf("1) Railfence 암호화\n2) Railfence 복호화\n3) Railfence 종료\n\n");
		printf("메뉴 선택: ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			int i = 0;

			getchar();
			printf("암호화할 평문 입력([a-zA-Z]): \n");
			fgets(plaintext_rail, sizeof(plaintext_rail), stdin);

			// 입력 받은 문자열 전부 다 소문자 처리
			while (plaintext_rail[i] != 10) {
				plaintext_rail[i] = tolower(plaintext_rail[i]);
				i += 1;
			}
			// 이 부분에 오버플로우 예외처리 추가해야함

			printf("\n깊이 입력(0보다 큰 정수): ");
			scanf_s("%d", &depth);
			fputc('\n', stdout);

			// depth 변수 예외처리
			if (depth <= 0) {
				fputs("depth 범위는 0보다 커야함\n", stderr);
				continue;
			}

			Encrypt_Rail(plaintext_rail, depth);
			fputc('\n', stdout);
			_getch();
		}
		else if (choice == 2) {
			int i = 0;

			getchar();
			printf("복호화할 암호문 입력([a-zA-Z]): \n");
			fgets(ciphertext_rail, sizeof(ciphertext_rail), stdin);

			// 입력 받은 문자열 전부 소문자 처리 해야함
			while (ciphertext_rail[i] != 10) {
				ciphertext_rail[i] = tolower(ciphertext_rail[i]);
				i += 1;
			}
			// 이 부분에 오버플로우 예외처리 추가해야함

			printf("\n키 입력(0보다 큰 정수): ");
			scanf_s("%d", &depth);
			fputc('\n', stdout);

			// depth 변수 예외처리
			if (depth <= 0) {
				fputs("depth 범위는 0보다 커야함\n", stderr);
				continue;
			}

			Decrypt_Rail(ciphertext_rail, depth);
			fputc('\n', stdout);
			_getch();
		}
		else if (choice == 3) {
			printf("Railfence 암호 종료\n\n");
			break;
		}
		else {
			printf("메뉴 입력 값 오류\n\n");
			getchar();
			continue;
		}
	}
}