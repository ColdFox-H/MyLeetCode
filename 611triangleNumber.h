#pragma once
#include <vector>
#include <iostream>
#include "SortAlgorithm.h"
using namespace std;

int triangleNumber(vector<int>& nums) {
    int res = 0;
    shellSort(nums);
    for (int i = nums.size() - 1; i >= 2; i--) {
        if (nums[i] >= nums[i - 1] + nums[i - 2])continue;
        int index = 1;
        for (int j = i - 1; j >= 1; j--) {
            int fin = nums[i] - nums[j];
            for (int k = j - index>=0? j - index:0; k >= 0; k--) {
                if (nums[k] > fin)index++;
                else {
                    res = res + index-1;
                    break;
                }   
            }
            res = res + index-1;
        }
    }
    return res;
}
