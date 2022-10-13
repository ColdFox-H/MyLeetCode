#pragma once
#include <vector>
#include <iostream>
#include "SortAlgorithm.h"
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    //排序
    shellSort(g);
    shellSort(s);
    //最大的糖果都不能满足胃口最小的孩子，直接返回0
    if (g[0] > s[s.size() - 1])return 0;
    //筛选除胃口超过最大糖果的孩子，不考虑
    //for(int i)
    //int res = 0;
    //for (int i = 0; i < g.size(); i++) {
    //    int index;
    //    for (int j = 0; j < s.szie(); j++) {

    //    }

    //}

}
