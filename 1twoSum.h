/*题目描述
给定一个整数数组 nums 和一个整数目标值 target，
请你在该数组中找出 和为目标值 target 的那两个整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。
来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#pragma once
#include <vector>
#include <iostream>
#include <time.h>
#include <unordered_map>
#include "SortAlgorithm.h"
#include "SearchAlgorithm.h"
using namespace std;
//测试可行性
void test1(vector<int>& nums,int target, vector<int>(*ptr)(vector<int>& nums,int target)) {
    cout << "序号：\n";
    for (int i = 0; i < nums.size(); i++)cout << i << " ";
    cout << "\n数组：\n";
    for (int i = 0; i < nums.size(); i++)cout << nums[i] << " ";
    clock_t t_s = clock();
    vector<int> indexs=ptr(nums,target);
    clock_t t_e = clock();
    cout << "\n目标的索引：";
    for (int i = 0; i < indexs.size(); i++)cout << indexs[i] << " ";
    cout << "\n用时：" << t_e - t_s << "ms";
}
//测试运行速度
void test1speed(int times, int size, vector<int>(*ptr)(vector<int>& nums, int target)) {
    vector<int> nums;
    int totalTime = 0;
    for (int i = 0; i < times; i++) {
        int target = rand();
        for (int j = 0; j < size; j++) nums.push_back(rand());
        clock_t t_s = clock();
        ptr(nums,target);
        clock_t t_e = clock();
        totalTime += t_e - t_s;
    }
    cout << "测试次数：" << times << " 数组长度：" << size << " 平均用时：" << totalTime / times << "ms";
}
//暴力穷举法(速度拉跨)
vector<int> twoSum1(vector<int>& nums, int target) {
    vector<int>indexs = {};
    for (int i = 0; i < nums.size()-1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                indexs.push_back(i);
                indexs.push_back(j);
                break;
            }
        }
    }
    return indexs;
}
//
//先排序，从两边向中间加
//!注意排序后会改变数组索引
vector<int> twoSum2(vector<int>& nums, int target) {
    int len = nums.size();
    vector<int>indexs;
    vector<int>numsIndexs;//储存原数组的索引
    for (int i = 0; i < nums.size(); i++) numsIndexs.push_back(i);
    for (int gap = floor((len / 2)); gap > 0; gap = floor(gap / 2)) {//确定间隔
        for (int i = gap; i < len; i++) {
            int j = i;
            int current = nums[i];
            int currentNumIdex = numsIndexs[i];
            while (j - gap >= 0 && current < nums[j - gap]) {
                nums[j] = nums[j - gap];
                numsIndexs[j] = numsIndexs[j - gap];

                j = j - gap;
            }
            nums[j] = current;
            numsIndexs[j] = currentNumIdex;

        }
    }
    for (int i = 0; i < len - 1; i++) {
        for (int j = len-1; j >= i+1; j--) {
            if (nums[i] + nums[j] == target) {
                indexs.push_back(numsIndexs[i]);
                indexs.push_back(numsIndexs[j]);
                break;
            }
            else if(nums[i] + nums[j] > target)len--;
        }
        if (indexs.size() != 0)break;
    }
    return indexs;
}

vector<int> twoSum3(vector<int>& nums, int target) {
    unordered_map<int, int>hashMap;
    for (int i = 0; i < nums.size(); i++) {
        hashMap[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++) {
        auto iter = hashMap.find(target - nums[i]);
        if (iter != hashMap.end()) {
            return { i,iter->second };
        }
    }
    return {};

}