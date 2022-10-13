#pragma once
#include <vector>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

void testSort(vector<int>& nums, void(*ptr)(vector<int>& nums)) {
    cout << "����ǰ��\n";
    for (int i = 0; i < nums.size(); i++)cout << nums[i] << " ";
    clock_t t_s = clock();
    ptr(nums);
    clock_t t_e = clock();
    cout << "\n�����\n";
    for (int i = 0; i < nums.size(); i++)cout << nums[i] << " ";
    cout << "\n��ʱ��" << t_e - t_s << "ms";
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
    cout << "���������" << times << " ���鳤�ȣ�" << size << " ƽ����ʱ��" << totalTime / times<<"ms";
}
//����
void numSwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
//С����ǰ
void minSwap(int& a, int& b) {
	if (b < a)numSwap(a, b);
}
//�����ǰ
void maxSwap(int& a, int& b) {
	if (a > b)numSwap(a, b);
}
//ð������
void bubbleSort(vector<int>& nums) {
	for (int i = 0; i < nums.size() - 1; i++) 
        for(int j=0;j<nums.size()-1-i;j++) maxSwap(nums[i], nums[i + 1]);
}
//��������
void insertionSort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        int j = i;
        //int preIndex = j - 1;
        int current = nums[j];
        while (j>= 1&&nums[j-1] > current) {//ǰ���
            nums[j] = nums[j-1];
            j--;
        }
        nums[j] = current;
    }
}
//ѡ������
void selectionSort(vector<int>& nums) {
    for (int i = 0; i < nums.size()-1; i++) {//ע��iǰ���ķ���Ҫ���������ƽ��ķ���һ��
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
//ϣ������
void shellSort(vector<int>& nums) {
    int len = nums.size();
    for (int gap = floor((len / 2)); gap > 0; gap = floor(gap / 2)) {//ȷ�����
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



