#pragma once
#include <vector>
#include "SortAlgorithm.h"
using namespace std;

void wiggleSort(vector<int>& nums) {
    shellSort(nums);
    vector<int>res;
    res.insert(res.begin(), nums.begin() + ceil(nums.size() / 2.0), nums.end());
    for (int i = 0; i < res.size(); i++) {
        nums.insert(nums.begin() + 2 * i + 1, res[i]);
    
    }
    nums.erase(nums.end() - res.size(), nums.end());
}