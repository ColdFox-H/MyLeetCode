#pragma once
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

//二分查找
//注意此处输入的nums是有序的
int binarySearch_h(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int middle;
    if (nums[left] <= target && nums[right] >= target) {//值必须在数组范围内
        while ((right - left) > 1) {
            middle = floor((right + left) / 2);
            if (nums[middle] == target)return middle;
            else if (nums[middle] > target)right = middle;
            else if (nums[middle] < target)left = middle;
        }
        if (nums[right] == target)return right;
        else if (nums[left] == target)return left;
        else return -1;
    }
    else return -1;
}
