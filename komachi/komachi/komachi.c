/*
�����Z
1.��1��2��3��4��5��6��7��8��9=100(���̒��ɂ�"+","-","*","/ ",""�̂����ꂩ������
2.����ʂ�ɂ��Ƃ��ׂĂ̏ꍇ�̐�(131072�ʂ�)�𑍓��肷��
*/
#include<stdio.h>
#include<stdlib.h>

int komachi[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
#define ANSWER 100

const char *operator_str[] = { "+", "-"};

/*�����Z���X�g*/
struct rist_komach
{
	int nam; /*���l*/
	int oper; /*���Z�q�̎��*/
};

