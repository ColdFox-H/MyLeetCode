#pragma once
#include <vector>
using namespace std;

int countKDifference(vector<int>& nums, int k) {
    shellSort(nums);
    if (nums[nums.size() - 1] - nums[0] < k)return 0;
    int num = 0;
    for (int i = nums.size(); i >= 1; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] - nums[j] == k)num++;
        }
    }
    return num;
}

//void shellSort(vector<int>& nums) {
//    int len = nums.size();
//    for (int gap = floor((len / 2)); gap > 0; gap = floor(gap / 2)) {//È·¶¨¼ä¸ô
//        for (int i = gap; i < len; i++) {
//            int j = i;
//            int current = nums[i];
//            while (j - gap >= 0 && current < nums[j - gap]) {
//                nums[j] = nums[j - gap];
//                j = j - gap;
//            }
//            nums[j] = current;
//        }
//    }
//}