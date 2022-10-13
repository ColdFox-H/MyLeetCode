#pragma once
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

void Test217() {

}

void test217speed(vector<int>& nums,bool(*ptr)(vector<int>& nums)) {
    cout << "排序前：\n";
    for (int i = 0; i < nums.size(); i++)cout << nums[i] << " ";
    clock_t t_s = clock();
    bool isContainsDuplicate = ptr(nums);
    clock_t t_e = clock();
    cout << "\n排序后：\n";
    for (int i = 0; i < nums.size(); i++)cout << nums[i] << " ";
    if (isContainsDuplicate)cout << "\nTrue";
    else cout << "\nFalse";
    cout << "\n用时：" << t_e - t_s << "ms";
}

//void shellSort(vector<int>& nums) {
//    int len = nums.size();
//    for (int i = 0; i < nums.size(); i++) {
//        int index = i;
//        int current = nums[i];
//        for (int j = len / 2; j >= 1; j / 2) {
//            //if (nums[i + j] > )
//        }
//
//    }
//
//}
bool containsDuplicate(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] == nums[j])return true;
        }
    }
    return false;
}