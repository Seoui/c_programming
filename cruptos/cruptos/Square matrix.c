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
	// 평문을 저장할 2차원 배열(matrix_squre) 동적할당
	matrix_squre = (char**)malloc(sizeof(char*) *row);
	for (i = 0; i < row; i++)
		matrix_squre[i] = (char*)malloc(sizeof(char)*col);

	for (i = 0; i < row; i++)	// matrix_squre 초기화
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
	
	printf("암호 결과: ");
	/* square matrix 배열 출력
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
	// 평문을 저장할 2차원 배열(matrix_squre) 동적할당
	matrix_squre = (char**)malloc(sizeof(char*) *row);
	for (i = 0; i < row; i++)
		matrix_squre[i] = (char*)malloc(sizeof(char)*col);

	for (i = 0; i < row; i++)	// matrix_squre 초기화
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

	printf("복호 결과: ");
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
		
	printf("Square matrix 암호 시작");
	while (1) {

		system("cls");
		printf("1) Square matrix 암호화\n2) Square matrix 복호화\n3) Square matrix 종료\n\n");
		printf("메뉴 선택: ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			int i = 0,
				j = 0;

			getchar();
			printf("암호화할 평문 입력([a-zA-Z]): \n");
			fgets(plaintext_squre, sizeof(plaintext_squre), stdin);

			// 입력 받은 문자열 전부 다 소문자 처리
			while (plaintext_squre[i] != 10) {
				plaintext_squre[i] = tolower(plaintext_squre[i]);
				i += 1;
			}

			// 공백제거 
			i = 0;
			while (ciphertext_squre[i] != 10) {
				if (ciphertext_squre[i] == 32)
					memmove(ciphertext_squre + i, ciphertext_squre + i + 1, strlen(ciphertext_squre) - i);
				i += 1;
			}
			// 이 부분에 오버플로우 예외처리 추가해야함

			printf("\n키 입력(0보다 큰 정수): ");
			scanf_s("%d", &key_squre);

			/* 키 범위 추가
			if (key_squre > 26 || key_squre < 0) {
				fputs("key 범위: 0 ~ 26\n", stderr);
				continue;
			}*/

			getchar();
			printf("\n키 배열 입력(입력한 정수 범위 안의 숫자 순서): ");
			fgets(key_arr, sizeof(key_arr), stdin);
			/* 입력받은 암호문 중 공백(space)제거 
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
			printf("복호화할 암호문 입력([a-zA-Z]): \n");
			fgets(ciphertext_squre, sizeof(ciphertext_squre), stdin);

			// 입력 받은 문자열 전부 소문자 처리 해야함
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

			// 이 부분에 오버플로우 예외처리 추가해야함

			printf("\n키 입력(0보다 큰 정수): ");
			scanf_s("%d", &key_squre);

			/* 키 범위 추가
			if (key_cae > 26 || key_cae < 0) {
				fputs("key 범위: 0 ~ 26\n", stderr);
				continue;
			}*/

			getchar();
			printf("\n키 배열 입력(입력한 정수 범위 안의 숫자 순서): ");
			fgets(key_arr, sizeof(key_arr), stdin);
			/* 입력받은 암호문 중 공백(space)제거
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
			printf("Square matrix 암호 종료\n\n");
			break;
		}
		else {
			printf("메뉴 입력 값 오류\n\n");
			getchar();
			continue;
		}
	}
	
}