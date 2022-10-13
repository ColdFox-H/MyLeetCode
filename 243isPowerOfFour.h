#pragma once

bool isPowerOfFour(int n) {
    if (n <= 0)return false;
    int num = 0;
    int bitLocation = 0;
    for (int i = 1; i <= 31; i++) {
        if (num > 1)return false;
        if ((n >> (i - 1)) & 1) {
            num++;
            bitLocation = i;
        }
    }
    if (bitLocation%2==1)return true;
    return false;
}