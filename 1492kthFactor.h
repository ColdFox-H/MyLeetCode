#pragma once

int kthFactor(int n, int k) {
    int j = 0;
    if (n % 2 == 0) {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)j++;
            if (j == k)return i;
        }
    }
    else {
        for (int i = 1; i <= n; i += 2) {
            if (n % i == 0)j++;
            if (j == k)return i;
        }
    }
    return -1;
}