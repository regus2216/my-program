/*
小町算
1.□1□2□3□4□5□6□7□8□9=100(□の中には"+","-","*","/ ",""のいずれかが入る
2.順列通りにやるとすべての場合の数(131072通り)を総当りする


仕様
・符号を数字で表す。"+"->0,"-"->1,"*"->2,"/"->3,""->4
*/
#include<stdio.h>
#include<stdlib.h>

int komachi[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
#define ANSWER 100 /*小町算の解答*/

const char *operator_str[] = { "+", "-"};

/*与えられた小町算の演算子配列で空白""をみつけ左に詰める*/
void hyouka_Blank(int komachi,int hugou){


	return 0;
}

