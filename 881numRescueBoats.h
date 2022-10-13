#pragma once
#include "SortAlgorithm.h"

int numRescueBoats(vector<int>& people, int limit) {
    shellSort(people);
    int num = 0;
    int i = people.size() - 1;
    int j = 0;
    while (j < i) {
        if (people[i] + people[j] > limit) {
            num++;
            i--;
        }
        else {
            num++;
            i--;
            j++;
        }
    }
    return num;
}