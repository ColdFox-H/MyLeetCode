#pragma once
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

//���ֲ���
//ע��˴������nums�������
int binarySearch_h(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int middle;
    if (nums[left] <= target && nums[right] >= target) {//ֵ���������鷶Χ��
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
