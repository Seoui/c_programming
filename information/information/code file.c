#include<stdio.h>
#include<string.h>

#define rows 16
#define cols 31
#define element 5

//�˻���� ����Լ�
char (*cal_H(char(*G)[cols], int row, int col))[cols]
{
	int i = 0;
	int j = 0;
	char trans_P[cols - rows][rows];             // P���(G����� parity �κ�) �� ��ġ���
	static char H[cols - rows][cols];            // H����� (15,31) 

	// P����� transpose
	for (i = 0; i < row; i++) {
		for (j = 0; j < col - row; j++) {
			trans_P[j][i] = G[i][j];
		}
	}

	// H���
	for (i = 0; i < col - row; i++) {
		for (j = 0; j < row; j++)
			H[i][j] = trans_P[i][j];
		for (j = 16; j < col; j++) {
			if (j == 16 + i)
				H[i][j] = 1;
			else
				H[i][j] = 0;
		}
	}

	// print H���
	for (i = 0; i < col - row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d ", H[i][j]);
		}
		printf("\n");
	}
	printf("������� H���\n");
	return H;
}

//�˻������ ��ġ��� ����Լ�
char (*cal_trans_H(char (*H)[cols], int row, int col))[cols-rows]{
	static char trans_H[cols][cols - rows] = { 0 };
	int i = 0, j = 0;

	for (i = 0; i < col-row; i++) {
		for (j = 0; j < col; j++) {
			trans_H[j][i] = H[i][j];
		}
		printf("\n");
	}
	for (i = 0; i < col; i++) {
		for (j = 0; j < col - row; j++) {
			printf("%d ", trans_H[i][j]);
		}
		printf("\n");
	}
	printf("������� trans_H���\n\n");

	return trans_H;
}

//��ȣ�� U��� ����Լ�
char (*cal_U(char (*G)[cols], char *message, int row, int col))
{
	int i = 0, j = 0;
	static char U[cols] = { 0 };

	U[0] = message[0] & G[0][0];
	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++) 
			U[i] = U[i] ^ (message[j] & G[j][i]);
	}
	
	for (i = 0; i < col; i++)
		printf("%d ", U[i]);
	printf("\n������� U���\n\n");

	return U;
}

//�ŵ�� S��� ����Լ�
void cal_S(char *U, char(*trans_H)[cols - rows], int row, int col)
{
	int i = 0, j = 0;
	char syndrome[rows] = { 0 };

	syndrome[0] = U[0] & trans_H[0][0];
	for (i = 0; i < col - row; i++) {
		for (j = 0; j < col; j++) 
			syndrome[i] = syndrome[i] ^ (U[j] & trans_H[j][i]);
	}

	for (i = 0; i < row; i++)
		printf("%d ", syndrome[i]);
	printf("\n������� S���\n\n");

}


int main(int argc, char* argv[])
{
	char G[rows][cols] = {
		{ 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } };
	char message[rows] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 };
	char C[cols] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	char R[cols] = { 0,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	printf("messages�� ��� 0�϶�\n\n");
	char(*H)[cols] = cal_H(G, rows, cols);                      //H��� main�Լ������� ����
	char(*trans_H)[cols - rows] = cal_trans_H(H, rows, cols);   //trans_H��� main�Լ������� ����
	char(*U) = cal_U(G, message, rows, cols);					//U��� main�Լ������� ����
	cal_S(U, trans_H, rows, cols);								//S���

	
	int i = 0, j = 0, k = 0, n = 30, DD = 3, nData=0;
	
	printf("\n���� 3�� �����ϴ� RECEIVED WORD �Է�\n ���ڸ� �ϳ��� 31�� �Է��ؾ��Ѵ� : ");
	for (i = 0; i < cols; i++) {
		scanf("%d", &nData);
		R[i] = nData;
	}

	printf("\n\nRECEIVED WORD: ");
	for (i = 0; i < cols; i++) {
		printf("%d ", R[i]);
	}

	while (DD != 0) {
		//�ʱ� �ŵ�� �� ���� ���� ���ϱ� 
		char SA[element] = { 0 };       //S �迭�� 0���� �����Ѵ�
		char SB[element] = { 0 };
		char SC[element] = { 0 };
		char FA[element] = { 0 };       //�� �迭�� 1���� �����Ѵ� FA[0] = ��FA(1)
		char FB[element] = { 0 };       //�� �迭�� �������� 
		char M1[element] = { 0 };
		char M2[element] = { 0 };
		char M3[element] = { 0 };
		char AA[cols] = { 0 };

		for (i = 0; i < cols; i++)    //AA���� 
			AA[i] = R[cols - 1 - i];

		//AA�� R[i](31��Ʈ)->U[i] �� �� ����̴�.

		for (i = 30; i >= 0; i--) {

			//S1 = r(a)�� �ϴ� �ŵ�� ��
			FA[0] = SA[4];
			SA[4] = SA[3];
			SA[3] = SA[2];
			SA[2] = SA[1] ^ FA[0];
			SA[1] = SA[0];
			SA[0] = AA[i] ^ FA[0];
			//SA[5] �迭�� S1��...

			//S3 = r(a^3) �� �ϴ� ��
			FA[1] = SB[0];
			FA[2] = SB[1];
			SB[0] = AA[i] ^ SB[2];
			SB[1] = SB[3];
			SB[2] = SA[2] ^ SB[4];
			SB[3] = FA[1] ^ SB[3];
			SB[4] = FA[2] ^ SB[4];
			//SB[5] �迭�� S3��..

			//S5 = r(a^5)
			FA[3] = SC[3];
			FA[4] = SC[4];
			SC[4] = SC[2] ^ FA[4];
			SC[3] = SC[1] ^ FA[3] ^ FA[4];
			SC[2] = SC[0] ^ SC[2] ^ FA[3];
			SC[1] = SC[1] ^ FA[4];
			SC[0] = AA[i] ^ SC[0] ^ FA[3];
			//SC[5] �迭�� S5��..
		}


		memcpy(&M1, &SA, sizeof(SA));                   //�Լ��� �̿��Ͽ� M1,M2,M3 �� ����
		memcpy(&M2, &SB, sizeof(SB));
		memcpy(&M3, &SC, sizeof(SC));

	INPUT:
		// *a ��µ�....
		FB[1] = M1[4];
		M1[4] = M1[3];
		M1[3] = M1[2];
		M1[2] = M1[1] ^ FB[0];
		M1[1] = M1[0];
		M1[0] = FB[0];

		// *a^3 
		FB[1] = M2[0];
		FB[2] = M2[3];
		M2[0] = M2[2];
		M2[2] = M2[1] ^ M2[4];
		M2[3] = FB[1] ^ M2[3];
		M2[4] = FB[2] ^ M2[4];

		// *a^5                         //M1�� *a �� ���    M2�� *a^3 �� ���    M3�� *a^5 �� ���
		FA[3] = M3[3];
		FA[4] = M3[4];
		M3[4] = M3[2] ^ FB[4];
		M3[3] = M3[1] ^ FB[3] ^ FB[4];
		M3[2] = M3[0] ^ M3[2] ^ FB[3];
		M3[1] = M3[1] ^ FB[4];
		M3[0] = M3[0] ^ FB[3];


		/*	for (i = 0; i < element; ++i) {
		printf("%d ", SA[i]);
		}
		puts("\n");
		for (i = 0; i < element; ++i) {
		printf("%d ", SB[i]);
		}
		puts("\n");
		for (i = 0; i < element; ++i) {
		printf("%d ", SC[i]);
		}
		puts("\n������� S1,S3,S5\n");
		for (i = 0; i < element; ++i) {
		printf("%d ", M1[i]);
		}
		puts("\n");
		for (i = 0; i < element; ++i) {
		printf("%d ", M2[i]);
		}
		puts("\n");
		for (i = 0; i < element; ++i) {
		printf("%d ", M3[i]);
		}
		puts("\n������� a,a^3,a^5\n");
		*/

		// M1 = S1, M2 = S3, M3 = S5, M4 = S2, M5 = S1^3, M6 = S4
		char M4[element] = { 0 }, M5[element] = { 0 }, M6[element] = { 0 }, M7[element] = { 0 }, M8[element] = { 0 };
		char N1[element] = { 0 }, N2[element] = { 0 }, N3[element] = { 0 }, N4[element] = { 0 };
		int T = 0, Y = 0, EX = 0;
		// �������� �ʱ�ȭ�� �Ǹ� �ȵ�

		//������ ��ĽĿ��� ������ �� ��
		for (k = 1; k < 10; k++) {
			int T1 = 0, T2 = 0;																		//�ʱ�ȭ�� ��� �����־�� �Ѵ�
			char X[element] = { 0 }, Y[element] = { 0 }, Z[element] = { 0 }, s[element] = { 0 };	//��������

			switch (k)
			{
			case 1:
				//M8
				for (i = 0; i < element; i++) {
					Y[i] = M2[i];
					Z[i] = M2[i];
				}
				for (i = 0; i < element; i++) {
					T1 = Z[4];
					Z[4] = Z[3];
					Z[3] = Z[2];
					Z[2] = Z[1];
					Z[1] = Z[0];
					Z[0] = T1;
					for (j = 0; j < 5; j++)
						s[j] = T1 & Y[j];
					T2 = X[4];
					X[4] = (X[3] ^ s[4]);
					X[3] = (X[2] ^ s[3] ^ T2);
					X[2] = (X[1] ^ s[2]);
					X[1] = (X[0] ^ s[1]);
					X[0] = (s[0] ^ T2);
				}
				for (i = 0; i < element; i++)
					M8[i] = X[i];
				break;

			case 2:
				//N1
				for (i = 0; i < element; i++) {
					Y[i] = M1[i];
					Z[i] = M2[i];
				}
				for (i = 0; i < element; i++) {
					T1 = Z[4];
					Z[4] = Z[3];
					Z[3] = Z[2];
					Z[2] = Z[1];
					Z[1] = Z[0];
					Z[0] = T1;
					for (j = 0; j < 5; j++)
						s[j] = T1 & Y[j];
					T2 = X[4];
					X[4] = (X[3] ^ s[4]);
					X[3] = (X[2] ^ s[3] ^ T2);
					X[2] = (X[1] ^ s[2]);
					X[1] = (X[0] ^ s[1]);
					X[0] = (s[0] ^ T2);
				}
				for (i = 0; i < element; i++)
					N1[i] = X[i];
				break;

			case 3:
				//N4
				for (i = 0; i < element; i++) {
					Y[i] = M1[i];
					Z[i] = M3[i];
				}
				for (i = 0; i < element; i++) {
					T1 = Z[4];
					Z[4] = Z[3];
					Z[3] = Z[2];
					Z[2] = Z[1];
					Z[1] = Z[0];
					Z[0] = T1;
					for (j = 0; j < 5; j++)
						s[j] = T1 & Y[j];
					T2 = X[4];
					X[4] = (X[3] ^ s[4]);
					X[3] = (X[2] ^ s[3] ^ T2);
					X[2] = (X[1] ^ s[2]);
					X[1] = (X[0] ^ s[1]);
					X[0] = (s[0] ^ T2);
				}
				for (i = 0; i < element; i++)
					N4[i] = X[i];
				break;

			case 4:
				//M4
				for (i = 0; i < element; i++) {
					Y[i] = M1[i];
					Z[i] = M1[i];
				}
				for (i = 0; i < element; i++) {
					T1 = Z[4];
					Z[4] = Z[3];
					Z[3] = Z[2];
					Z[2] = Z[1];
					Z[1] = Z[0];
					Z[0] = T1;
					for (j = 0; j < 5; j++)
						s[j] = T1 & Y[j];
					T2 = X[4];
					X[4] = (X[3] ^ s[4]);
					X[3] = (X[2] ^ s[3] ^ T2);
					X[2] = (X[1] ^ s[2]);
					X[1] = (X[0] ^ s[1]);
					X[0] = (s[0] ^ T2);
				}
				for (i = 0; i < element; i++)
					M4[i] = X[i];
				break;

			case 5:
				//M5
				for (i = 0; i < element; i++) {
					Y[i] = M4[i];
					Z[i] = M1[i];
				}
				for (i = 0; i < element; i++) {
					T1 = Z[4];
					Z[4] = Z[3];
					Z[3] = Z[2];
					Z[2] = Z[1];
					Z[1] = Z[0];
					Z[0] = T1;
					for (j = 0; j < 5; j++)
						s[j] = T1 & Y[j];
					T2 = X[4];
					X[4] = (X[3] ^ s[4]);
					X[3] = (X[2] ^ s[3] ^ T2);
					X[2] = (X[1] ^ s[2]);
					X[1] = (X[0] ^ s[1]);
					X[0] = (s[0] ^ T2);
				}
				for (i = 0; i < element; i++)
					M5[i] = X[i];
				break;

			case 6:
				//M6
				for (i = 0; i < element; i++) {
					Y[i] = M4[i];
					Z[i] = M4[i];
				}
				for (i = 0; i < element; i++) {
					T1 = Z[4];
					Z[4] = Z[3];
					Z[3] = Z[2];
					Z[2] = Z[1];
					Z[1] = Z[0];
					Z[0] = T1;
					for (j = 0; j < 5; j++)
						s[j] = T1 & Y[j];
					T2 = X[4];
					X[4] = (X[3] ^ s[4]);
					X[3] = (X[2] ^ s[3] ^ T2);
					X[2] = (X[1] ^ s[2]);
					X[1] = (X[0] ^ s[1]);
					X[0] = (s[0] ^ T2);
				}
				for (i = 0; i < element; i++)
					M6[i] = X[i];
				break;

			case 7:
				//N2
				for (i = 0; i < element; i++) {
					Y[i] = M4[i];
					Z[i] = M2[i];
				}
				for (i = 0; i < element; i++) {
					T1 = Z[4];
					Z[4] = Z[3];
					Z[3] = Z[2];
					Z[2] = Z[1];
					Z[1] = Z[0];
					Z[0] = T1;
					for (j = 0; j < 5; j++)
						s[j] = T1 & Y[j];
					T2 = X[4];
					X[4] = (X[3] ^ s[4]);
					X[3] = (X[2] ^ s[3] ^ T2);
					X[2] = (X[1] ^ s[2]);
					X[1] = (X[0] ^ s[1]);
					X[0] = (s[0] ^ T2);
				}
				for (i = 0; i < element; i++)
					N2[i] = X[i];
				break;

			case 8:
				//M7
				for (i = 0; i < element; i++) {
					Y[i] = M4[i];
					Z[i] = M6[i];
				}
				for (i = 0; i < element; i++) {
					T1 = Z[4];
					Z[4] = Z[3];
					Z[3] = Z[2];
					Z[2] = Z[1];
					Z[1] = Z[0];
					Z[0] = T1;
					for (j = 0; j < 5; j++)
						s[j] = T1 & Y[j];
					T2 = X[4];
					X[4] = (X[3] ^ s[4]);
					X[3] = (X[2] ^ s[3] ^ T2);
					X[2] = (X[1] ^ s[2]);
					X[1] = (X[0] ^ s[1]);
					X[0] = (s[0] ^ T2);
				}
				for (i = 0; i < element; i++)
					M7[i] = X[i];
				break;

			case 9:
				//N3
				for (i = 0; i < element; i++) {
					Y[i] = M5[i];
					Z[i] = M2[i];
				}
				for (i = 0; i < element; i++) {
					T1 = Z[4];
					Z[4] = Z[3];
					Z[3] = Z[2];
					Z[2] = Z[1];
					Z[1] = Z[0];
					Z[0] = T1;
					for (j = 0; j < 5; j++)
						s[j] = T1 & Y[j];
					T2 = X[4];
					X[4] = (X[3] ^ s[4]);
					X[3] = (X[2] ^ s[3] ^ T2);
					X[2] = (X[1] ^ s[2]);
					X[1] = (X[0] ^ s[1]);
					X[0] = (s[0] ^ T2);
				}
				for (i = 0; i < element; i++)
					N3[i] = X[i];
				break;
			}
		}

		/*	for (i = 0; i < element; i++)
		printf("%d ", M2[i]);
		printf("\n");
		for (i = 0; i < element; i++)
		printf("%d ", M3[i]);
		printf("\n");
		for (i = 0; i < element; i++)
		printf("%d ", M5[i]);
		printf("\n");
		for (i = 0; i < element; i++)
		printf("%d ", M6[i]);
		printf("\n");
		for (i = 0; i < element; i++)
		printf("%d ", M7[i]);
		printf("\n");
		for (i = 0; i < element; i++)
		printf("%d ", M8[i]);
		printf("\n");
		for (i = 0; i < element; i++)
		printf("%d ", N1[i]);
		printf("\n");
		for (i = 0; i < element; i++)
		printf("%d ", N2[i]);
		printf("\n");
		for (i = 0; i < element; i++)
		printf("%d ", N3[i]);
		printf("\n");
		for (i = 0; i < element; i++)
		printf("%d ", N4[i]);
		printf("\n�������\n\n");
		*/

		//delta.....���� ���Ѵ�.....
		char K[element] = { 0 };

		for (i = 0; i < element; i++)
			K[i] = M2[i] ^ M3[i] ^ M5[i] ^ M6[i] ^ M7[i] ^
			M8[i] ^ N1[i] ^ N2[i] ^ N3[i] ^ N4[i];

		/*	printf("\nK���\n");
		for (i = 0; i < element; i++)
		printf("%d ", K[i]);
		printf("\n");
		*/
		//		for (i = 0; i < element; i++)
		//			T = T ^ K[i];

		//NOR

		for (i = 0; i < element; i++) {
			if (K[i] == 0) {
				T = T + 1;
			}
		}
		if (T == 5)
			Y = 1;
		else
			Y = 0;

		//ERROR LOCATION
		EX = Y ^ R[n];
		C[n] = EX;
		n = n - 1;


		if (n < 0) {
			printf("\n\nError Location : ");
			for (i = 0; i < cols; i++) {
				printf("%d ", C[i]);
			}
		}
		else
			goto INPUT;

		DD = DD - 1;
	}

	int count = 0;
	for (i = 0; i < cols; i++) {
		if (count != 3) {
			if (C[i] == 1) {
				C[i] = 0;
				count++;
			}
		}
	}
	
	printf("\n\nCORRECTED WORD: ");
	for (i = 0; i < cols; i++) {
		if (C[i] > 1)
			printf("\n����\n");
		printf("%d ", C[i]);
	}
	printf("\n");

	return 0;
}