#pragma once
//λ����ʵ�ּӷ�
/*�ֱ��ǲ���λ��ֻ��λ�������Ȼ�������û�н�λ*/
int bitAdd(int a, int b) {
	if (b == 0)return a;
	int sum = a ^ b;//������㣬���ҽ���ֻ��һ��1ʱȡ1�����㲻��λ�����
	unsigned int carry = (unsigned int)(a & b) << 1;//��λ��������ҽ���11ʱΪ1���������һλ
	while (carry != 0) {
		a = sum;
		b = carry;
		sum = a ^ b;
		carry = (unsigned int)(a & b) << 1;
	}
	return sum;
}
//λ����ʵ�ּ���
/*�Ѽ�һ����ת�ɼ�һ�����������üӷ�����
�����ı���ŵķ�����ȡ����һ��ʹ��ȡ�������~��*/
int bitSubstract(int a, int b) {
	return bitAdd(a, bitAdd(~b, 1));
}
//λ����ʵ�ֳ˷�
int bitMultiply_old(int a, int b) {
	if (a == 0 || b == 0)return 0;
	//��ȡ����ֵ
	int multiplicand = a < 0 ? bitAdd(~a, 1) : a;
	int multiplier = b < 0 ? bitAdd(~b, 1) : b;
	int product = 0;
	int times = 0;
	if (a < b) {//�Ż��ٶȣ�ʹѭ��������
		int temp = a;
		a = b;
		b = temp;
	}
	while (times < b) {
		product = bitAdd(product, a);
		times = bitAdd(times, 1);
	}
	if ((a ^ b) < 0)product = bitAdd(~product, 1);
	return product;
}
//λ����ʵ�ֳ˷����Ż���
int bitMultiply(int a, int b) {
	if (a == 0 || b == 0)return 0;
	//��ȡ����ֵ
	int multiplicand = a < 0 ? bitAdd(~a, 1) : a;
	int multiplier = b < 0 ? bitAdd(~b, 1) : b;
	int product = 0;
	if (multiplicand < b) {//�Ż��ٶȣ�ʹѭ��������
		int temp = multiplicand;
		multiplicand = multiplier;
		multiplier = temp;
	}
	while (multiplier > 0) {
		if ((multiplier & 0x1) > 0) product = bitAdd(product, multiplicand);
		multiplicand = multiplicand << 1;
		multiplier = multiplier >> 1;
	}
	if ((a ^ b) < 0)product = bitAdd(~product, 1);
	return product;
}
//λ����ʵ�ֳ���
/*�� bitMultiply_old ��˼·���ƣ�������ȥ����ֱ����ȳ���С�����Ĵ���������*/
int bitDivide_old(int a, int b) {
	//�������Ƿ�Ϊ0
	// 

	//��ȡ����ֵ
	int dividend = a > 0 ? a : bitAdd(~a, 1);//������
	int divisor = b > 0 ? b : bitAdd(~b, 1);//����
	if (dividend < divisor)return 0;//������С�ڳ�����ֱ�ӷ���0
	int quotient = 0;//��
	int reminder = 0;//����
	while (dividend >= divisor) {//ע��Ҫ��=
		dividend = bitSubstract(dividend, divisor);
		quotient = bitAdd(quotient, 1);
	}
	//ȷ���̵ķ���
	if ((a ^ b) < 0)quotient = bitAdd(~quotient, 1);
	//ȷ�������ķ���
	reminder = b > 0 ? dividend : bitAdd(~dividend, 1);
	return quotient;
}
//λ����ʵ�ֳ������Ż��棩
int bitDivide(int a, int b) {
	//�������Ƿ�Ϊ0
	// 

	//��ȡ����ֵ
	//int a3 = ~a;
	//int a2 = bitAdd(~a, 1);
	long int dividend = a > 0 ? a : bitAdd(~a, 1);//������
	if (a == -2147483648) dividend = 2147483647;//ת��

	int divisor = b > 0 ? b : bitAdd(~b, 1);//����
	if (dividend < divisor)return 0;//������С�ڳ�����ֱ�ӷ���0

	int quotient = 0;//��
	int reminder = 0;//����
	for (int i = 31; i >= 0; i--) {
		if ((dividend >> i) >= divisor) {
			quotient = bitAdd(quotient, 1 << i);
			dividend = bitSubstract(dividend, divisor << i);
		}
	}
	//ȷ���̵ķ���
	//int a2 = ~quotient;
	//int a3 = a2 + 1;
	if ((a ^ b) < 0) {
		if (quotient == 2147483647 || quotient == -2147483647||(a == -2147483648&& divisor==2))quotient = ~quotient;
		else quotient = bitAdd(~quotient, 1);
	}
	//ȷ�������ķ���
	reminder = b > 0 ? dividend : bitAdd(~dividend, 1);
	return quotient;
}
//λ����ʵ��ȡ������
int bitModulo(int a, int b) {
	return a - bitDivide(a, b) * b;
}
//λ����ʵ��������
int bitPow(int a, int n) {
	if (a == 0)return 0;
	if (a == 1 && n == 1)return a;
	int power = 1;
	while (n > 0) {
		power = bitMultiply(power, a);
		n = bitSubstract(n,1);
	}
	return power;
}
int bitSqrt(int x) {
	if (x == 0)return 0;
	int root = 1;
	while (bitPow(root, 2) <= x) {
		root = bitAdd(root, 1);
	}
	root = bitSubstract(root, 1);
	return root;
}

