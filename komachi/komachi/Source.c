#include<stdio.h>

/*�z��NEO�ɓ����Ă��鐔���𕄍��A�ςȂǂ𔻒肵�z��KEKKA�ɑ�����Ă���*/
void KEISAN(int hugou[9], int NEO[10], int KEKKA[10])
{
	int a;
	int b;

	for (a = 0, b = 0; a < 10; a++)
	{
		if (hugou[a] == 1){

			KEKKA[a] = NEO[a];

		}
		else if (hugou[a] == 2){

			KEKKA[a] = -NEO[a];

		}
		else if (hugou[a] == 3){

			KEKKA[a] = KEKKA[a - 1] * NEO[a];
			KEKKA[a - 1] = 0;

		}

	}

}
/*���̊֐��Ŕz��mark�ɓ����Ă���4(�܂艽�������Ă��Ȃ����𔻒肷�镨)�Ƃ����������Ȃ����ĉE�l�߂��Ĕz��hugou�ɓ���Ă���*/
void mark_hugou(int mark[9], int hugou[9])
{
	int x;
	int y;

	for (x = 0, y = 0; x < 9; x++){
		if (mark[x] != 4){
			hugou[y] = mark[x];
			y++;
		}
	}
}
/*���̊֐��Ŕz��NEW�ɂ͓����Ă��镨���ׂĂ�����0�������č��ɂ��炵�ē���Ă���*/
void NEW_NEO(int NEW[10], int NEO[10])
{
	int x;
	int y;

	for (x = 0, y = 0; x <10; x++){
		while (1){
			if (NEW[x] == 0){

			}
			else if (NEW[x] != 0){
				if (x < 10){
					NEO[y] = NEW[x];
					y++;
				}
			}
			break;
		}
	}
}

/*�����Ŏ���]������B
�����ŕ]������Ƃ́�1��2��3��4��5��6��7��8��9�́��̒���
���������Ă��Ȃ����̂������ɔ��肵�Ĕz��NEW�ɓ���Ă���*/
void hyouka(int suuzi[10], int NEW[10], int mark[9], int k)
{
	for (; k < 9; k++)
	{
		if (mark[k] == 4){
			NEW[k] = NEW[k - 1] * 10 + suuzi[k + 1];
			NEW[k - 1] = 0;
		}
		else{
			NEW[k] = suuzi[k + 1];
		}
	}
	k = 0;
}

/*�����ŁA�^����ꂽ���ǂ���ɕ\�����Ă���*/
void hyouji(int suuzi[10], int mark[9])
{
	int i;
	if (mark[0] == 2)
		printf("-");
	for (i = 1; i < 10; i++){
		printf("%d", suuzi[i]);
		switch (mark[i]){
		case 1:
			printf("+");
			break;
		case 2:
			printf("-");
			break;
		case 3:
			printf("*");
			break;
		case 4:
			printf("");
			break;
		}
	}
}

int main(void)
{
	int suuzi[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };             /*�������n�߂ɔz��ɓ���Ă���*/
	int NEW[10] = { 0 };                                   /*�]���������̂�����z��*/
	int NEO[10] = { 0 };                                 /*NEW�����l�������̂�����*/
	int KEKKA[10] = { 0 };                               /*�ŏI�I�ɂ��ׂĂ��v�Z�������̂�����*/
	int mark[9];                                       /*�n�߂̕���������*/
	int hugou[9] = { 0 };                                /*�]�������������i�[���邽�߂̔z��*/

	int n1;                                            /*n1~n9�܂ł͕������i�[����*/
	int n2;
	int n3;
	int n4;
	int n5;
	int n6;
	int n7;
	int n8;
	int n9;
	int k = 0;                                         /*�֐��]���ɓn������*/
	int i = 0;                                         /*���[�v�ϐ�*/
	int kekka;
	int x = 0, y = 0;

	/*�v�Z���ʂ�������*/
	for (n1 = 1; n1 <= 2; n1++){
		for (n2 = 1; n2 <= 4; n2++){
			for (n3 = 1; n3 <= 4; n3++){
				for (n4 = 1; n4 <= 4; n4++){
					for (n5 = 1; n5 <= 4; n5++){
						for (n6 = 1; n6 <= 4; n6++){
							for (n7 = 1; n7 <= 4; n7++){
								for (n8 = 1; n8 <= 4; n8++){
									for (n9 = 1; n9 <= 4; n9++){
										mark[0] = n1;
										mark[1] = n2;
										mark[2] = n3;
										mark[3] = n4;
										mark[4] = n5;
										mark[5] = n6;
										mark[6] = n7;
										mark[7] = n8;
										mark[8] = n9;

										hyouka(suuzi, NEW, mark, k);

										NEW_NEO(NEW, NEO);

										mark_hugou(mark, hugou);

										KEISAN(hugou, NEO, KEKKA);

										/*�z��NEW�̒��̒l�����ׂđ����Ă���*/
										for (kekka = 0, i = 0; i < 10; i++)
											kekka = kekka + KEKKA[i];

										/*kekka��100�Ȃ�Ε\������*/
										if (kekka == 100){
											hyouji(suuzi, mark);

											printf("=%d\n", kekka);

										}

										/*�z��̒��g�����ׂ�0�ŏ�����*/
										for (y = 0; y < 10; y++){
											NEW[y] = 0;
											if (y < 9)
												hugou[y] = 0;
											NEO[y] = 0;
											KEKKA[y] = 0;

										}

									}

								}

							}

						}

					}

				}

			}

		}

	}
	return(0);
}