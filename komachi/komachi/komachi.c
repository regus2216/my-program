/*
小町算
1.□1□2□3□4□5□6□7□8□9=100(□の中には"+","-","*","/ ",""のいずれかが入る
2.順列通りにやるとすべての場合の数(131072通り)を総当りする
*/
#include<stdio.h>
#include<stdlib.h>

int komachi[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
#define ANSWER 100

const char *operator_str[] = { "+", "-"};

/*小町算リスト*/
struct rist_komach
{
	int nam; /*数値*/
	int oper; /*演算子の種類*/
};

