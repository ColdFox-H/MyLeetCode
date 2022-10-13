#pragma once
#include <vector>
#include<numeric>
#include <iostream>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
	//����
	int cols = grid[0].size();
	//����
	int rows = grid.size();
	int cout = 0;
	for (int i = 0; i < cols; i++) {
		if (grid[0][i] == 1 )cout++;		//��һ��
		if (grid[rows - 1][i] == 1)cout++;	//���һ��
		for (int j = 0; j < rows-1; j++) {
			if ((grid[j][i] == 1) ^ (grid[j + 1][i] == 1))cout++;
		}
	}
	for (int i = 0; i < rows; i++) {
		if (grid[i][0] == 1)cout++;		//��һ��
		if (grid[i][cols - 1] == 1)cout++;	//���һ��
		for (int j = 0; j < cols-1; j++) {
			if ((grid[i][j] == 1) ^ (grid[i][j+1] == 1))cout++;
		}
	}
	return cout;

}