#pragma once
#include <vector>
#include <iostream>
using namespace std;

int integerReplacement(int n) {
    int min = 0, max = 0;
    while (pow(2, min) < n) {
        min++;
    }
    if (pow(2, min) == n)return min;
    else {
        max = min;
        min = min - 1;
    }
    int maxN = pow(2, max);
    int minN = pow(2, min);
    int ti = maxN - n < n - minN ? maxN - n : n - minN;
    return min + ti;
}