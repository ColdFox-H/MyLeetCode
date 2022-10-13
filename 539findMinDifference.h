#pragma once
#include <vector>
#include <iostream>
#include "SortAlgorithm.h"
using namespace std;

int stringToTime(string s) {
    int a, b;
    sscanf(s.data(), "%d:%d", &a, &b);
    return a * 60 + b;
}
int findMinDifference(vector<string>& timePoints) {
    int size = timePoints.size();
    vector<int>vTimePoints(size);
    for (int i = 0; i < size; i++) {
        vTimePoints[i]=stringToTime(timePoints[i]);
    }
    shellSort(vTimePoints);
    int minTime = 1440;
    for (int i = 0; i < size - 1; i++) {
        int time = (vTimePoints[i + 1] - vTimePoints[i] > 720) ? 1440 - (vTimePoints[i + 1] - vTimePoints[i]) : vTimePoints[i + 1] - vTimePoints[i];
        minTime = time < minTime ? time : minTime;
    }
    return minTime;
}
