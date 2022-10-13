#pragma once
//位运算实现加法
/*分别考虑不进位和只进位的情况，然后迭代到没有进位*/
int bitAdd(int a, int b) {
	if (b == 0)return a;
	int sum = a ^ b;//异或运算，当且仅当只有一个1时取1，计算不进位的情况
	unsigned int carry = (unsigned int)(a & b) << 1;//进位情况，当且仅当11时为1，随后左移一位
	while (carry != 0) {
		a = sum;
		b = carry;
		sum = a ^ b;
		carry = (unsigned int)(a & b) << 1;
	}
	return sum;
}
//位运算实现减法
/*把减一个数转成加一个负数，再用加法计算
整数改变符号的方法：取反加一（使用取反运算符~）*/
int bitSubstract(int a, int b) {
	return bitAdd(a, bitAdd(~b, 1));
}
//位运算实现乘法
int bitMultiply_old(int a, int b) {
	if (a == 0 || b == 0)return 0;
	//先取绝对值
	int multiplicand = a < 0 ? bitAdd(~a, 1) : a;
	int multiplier = b < 0 ? bitAdd(~b, 1) : b;
	int product = 0;
	int times = 0;
	if (a < b) {//优化速度，使循环次数少
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
//位运算实现乘法（优化）
int bitMultiply(int a, int b) {
	if (a == 0 || b == 0)return 0;
	//先取绝对值
	int multiplicand = a < 0 ? bitAdd(~a, 1) : a;
	int multiplier = b < 0 ? bitAdd(~b, 1) : b;
	int product = 0;
	if (multiplicand < b) {//优化速度，使循环次数少
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
//位运算实现除法
/*与 bitMultiply_old 的思路相似，反复减去除数直到差比除数小，减的次数就是商*/
int bitDivide_old(int a, int b) {
	//检查除数是否为0
	// 

	//先取绝对值
	int dividend = a > 0 ? a : bitAdd(~a, 1);//被除数
	int divisor = b > 0 ? b : bitAdd(~b, 1);//除数
	if (dividend < divisor)return 0;//被除数小于除数，直接返回0
	int quotient = 0;//商
	int reminder = 0;//余数
	while (dividend >= divisor) {//注意要加=
		dividend = bitSubstract(dividend, divisor);
		quotient = bitAdd(quotient, 1);
	}
	//确定商的符号
	if ((a ^ b) < 0)quotient = bitAdd(~quotient, 1);
	//确定余数的符号
	reminder = b > 0 ? dividend : bitAdd(~dividend, 1);
	return quotient;
}
//位运算实现除法（优化版）
int bitDivide(int a, int b) {
	//检查除数是否为0
	// 

	//先取绝对值
	//int a3 = ~a;
	//int a2 = bitAdd(~a, 1);
	long int dividend = a > 0 ? a : bitAdd(~a, 1);//被除数
	if (a == -2147483648) dividend = 2147483647;//转成

	int divisor = b > 0 ? b : bitAdd(~b, 1);//除数
	if (dividend < divisor)return 0;//被除数小于除数，直接返回0

	int quotient = 0;//商
	int reminder = 0;//余数
	for (int i = 31; i >= 0; i--) {
		if ((dividend >> i) >= divisor) {
			quotient = bitAdd(quotient, 1 << i);
			dividend = bitSubstract(dividend, divisor << i);
		}
	}
	//确定商的符号
	//int a2 = ~quotient;
	//int a3 = a2 + 1;
	if ((a ^ b) < 0) {
		if (quotient == 2147483647 || quotient == -2147483647||(a == -2147483648&& divisor==2))quotient = ~quotient;
		else quotient = bitAdd(~quotient, 1);
	}
	//确定余数的符号
	reminder = b > 0 ? dividend : bitAdd(~dividend, 1);
	return quotient;
}
//位运算实现取余运算
int bitModulo(int a, int b) {
	return a - bitDivide(a, b) * b;
}
//位运算实现幂运算
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

