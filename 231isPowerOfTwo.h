/*
231. 2 ����
 ����һ������ n�������жϸ������Ƿ��� 2 ���ݴη�������ǣ����� true �����򣬷��� false ��
*/

#pragma once
#include <iostream>

//����һ,����
bool isPowerOfTwo1(int n) {
    if (n <= 0)return false;
    else {
        while (n % 2 == 0 && n != 1) {
            n = n / 2;
        }
        if (n == 1)return true;
        else return false;
    }
}
//���������˷�
bool isPowerOfTwo2(int n) {
    if (n == 1)return true;
    int num = 1;
    for (int i = 1; i <= 31; i++) {
        num *= 2;
        if (num > n)return false;
        if (num == n)return true;
    }
    return false;
}
//����������λ
bool isPowerOfTwo3(int n) {
    if (n <= 0)return false;
    int num = 0;
    for (int i = 1; i <= 31; i++) {
        if (num > 1)return false;
        num += ((n >> (i - 1)) & 1);
    }
    if (num == 1)return true;
}


