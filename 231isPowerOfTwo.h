/*
231. 2 的幂
 给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。
*/

#pragma once
#include <iostream>

//方法一,除法
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
//方法二，乘法
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
//方法二，移位
bool isPowerOfTwo3(int n) {
    if (n <= 0)return false;
    int num = 0;
    for (int i = 1; i <= 31; i++) {
        if (num > 1)return false;
        num += ((n >> (i - 1)) & 1);
    }
    if (num == 1)return true;
}


