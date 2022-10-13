#pragma once
#include <vector>
#include<numeric>
#include <iostream>
using namespace std;

int findMin(vector<int>subNums, vector<int>& expIndex, int currentIndex);


int magicTower(vector<int>& nums) {
    int res = 0;
    vector<int> expIndex;
    if (accumulate(nums.begin(), nums.end(), 0) >= 0) {//保证可行性
        int blood = 0;//当前血量
        for (int i = 0; i < nums.size(); ++i) {
            blood = blood + nums[i];
            if (blood < 0) {
                blood -= findMin(nums, expIndex, i);
                ++res;
            }

        }
    }
    return res;
}
int findMin(vector<int>subNums, vector<int>& expIndex, int currentIndex) {
    int min = 0;
    int minIndex = 0;
    int label = 0;
    for (int i = 0; i <= currentIndex; ++i) {
        for (int j = 0; j < expIndex.size(); ++j) {
            if (i == expIndex[j]) {
                label = 1;
                break;
            }
        }
        if (label == 0) {
            if (subNums[i] < min) {
                min = subNums[i];
                minIndex = i;
            }
        }
        label = 0;
    }
    expIndex.push_back(minIndex);
    return min;
}
