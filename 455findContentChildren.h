#pragma once
#include <vector>
#include <iostream>
#include "SortAlgorithm.h"
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    //����
    shellSort(g);
    shellSort(s);
    //�����ǹ�����������θ����С�ĺ��ӣ�ֱ�ӷ���0
    if (g[0] > s[s.size() - 1])return 0;
    //ɸѡ��θ�ڳ�������ǹ��ĺ��ӣ�������
    //for(int i)
    //int res = 0;
    //for (int i = 0; i < g.size(); i++) {
    //    int index;
    //    for (int j = 0; j < s.szie(); j++) {

    //    }

    //}

}
