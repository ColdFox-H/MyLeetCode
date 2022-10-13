#pragma once

bool isPowerOfThree(int n) {
    if (n <= 0)return false;
    if (n % 2 == 0)return false;
    if (n == 1)return true;
    int num = 1;
    for (int i = 1; i <= 19; i++) {
        num *= 3;
        if (num > n)return false;
        if (num == n)return true;
    }
    return false;
}