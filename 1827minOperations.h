#pragma once
#include <vector>
#include <iostream>
using namespace std;

int minOperations(vector<int>& nums) {
    if (nums.size() == 1)return 0;
    int res=0;
    for (int i = 0; i < nums.size() - 1; i++) {
        while (nums[i] >= nums[i + 1]) {
            int temp = nums[i + 1];
            nums[i + 1]=nums[i]+1;
            res=res+ nums[i+1]-temp;
        }
    }
    return res;
}
