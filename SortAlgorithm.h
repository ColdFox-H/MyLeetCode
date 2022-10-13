#pragma once
#include <vector>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

void testSort(vector<int>& nums, void(*ptr)(vector<int>& nums)) {
    cout << "排序前：\n";
    for (int i = 0; i < nums.size(); i++)cout << nums[i] << " ";
    clock_t t_s = clock();
    ptr(nums);
    clock_t t_e = clock();
    cout << "\n排序后：\n";
    for (int i = 0; i < nums.size(); i++)cout << nums[i] << " ";
    cout << "\n用时：" << t_e - t_s << "ms";
}

void testSortSpeed(int times, int size, void(*ptr)(vector<int>& nums)) {
    vector<int> nums;
    int totalTime = 0;
    for (int i = 0; i < times; i++) {
        for (int j = 0; j < size; j++) nums.push_back(rand());
        clock_t t_s = clock();
        ptr(nums);
        clock_t t_e = clock();
        totalTime += t_e - t_s;
    }
    cout << "排序次数：" << times << " 数组长度：" << size << " 平均用时：" << totalTime / times<<"ms";
}
//交换
void numSwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
//小的在前
void minSwap(int& a, int& b) {
	if (b < a)numSwap(a, b);
}
//大的在前
void maxSwap(int& a, int& b) {
	if (a > b)numSwap(a, b);
}
//冒泡排序
void bubbleSort(vector<int>& nums) {
	for (int i = 0; i < nums.size() - 1; i++) 
        for(int j=0;j<nums.size()-1-i;j++) maxSwap(nums[i], nums[i + 1]);
}
//插入排序
void insertionSort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        int j = i;
        //int preIndex = j - 1;
        int current = nums[j];
        while (j>= 1&&nums[j-1] > current) {//前面大
            nums[j] = nums[j-1];
            j--;
        }
        nums[j] = current;
    }
}
//选择排序
void selectionSort(vector<int>& nums) {
    for (int i = 0; i < nums.size()-1; i++) {//注意i前进的方向要和有序列推进的方向一致
        int minIndex = i;
        int minNum = nums[i];
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[j] < minNum) {
                minIndex = j;
                minNum = nums[j];
            }
        }
        nums[minIndex] = nums[i];
        nums[i] = minNum;
    }
}
//希尔排序
void shellSort(vector<int>& nums) {
    int len = nums.size();
    for (int gap = floor((len / 2)); gap > 0; gap = floor(gap / 2)) {//确定间隔
        for (int i = gap; i < len; i++) {
            int j = i;
            int current = nums[i];
            while (j - gap >= 0 && current < nums[j - gap]) {
                nums[j] = nums[j - gap];
                j = j - gap;
            }
            nums[j] = current;
        }
    }
}



