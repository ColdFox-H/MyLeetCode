#pragma once
#include <vector>
#include <iostream>
using namespace std;

bool rotateString(string s, string goal) {
    string temp = s;
    for (int i = 0; i < temp.size(); i++) {
        s = s + temp;
    }
    int pos = s.find(goal);
    if (pos == -1)return false;
    return true;
}