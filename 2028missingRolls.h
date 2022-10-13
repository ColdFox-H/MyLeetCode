/*2028. 找出缺失的观测数据
现有一份 n + m 次投掷单个 六面 骰子的观测数据，骰子的每个面从 1 到 6 编号。
观测数据中缺失了 n 份，你手上只拿到剩余 m 次投掷的数据。
幸好你有之前计算过的这 n + m 次投掷数据的平均值 。
给你一个长度为 m 的整数数组 rolls ，其中 rolls[i] 是第 i 次观测的值。同时给你两个整数 mean 和 n 。
返回一个长度为 n 的数组，包含所有缺失的观测数据，且满足这 n + m 次投掷的 平均值 是 mean 。
如果存在多组符合要求的答案，只需要返回其中任意一组即可。如果不存在答案，返回一个空数组。
来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/find-missing-observations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#pragma once
#include <vector>
#include <iostream>
#include <time.h>
#include <numeric>
using namespace std;

void test2028(vector<int>& rolls, int mean, int n, vector<int>(*ptr)(vector<int>& rolls, int mean, int n)) {
	cout << "已知数据：";
	for (int i = 0; i < rolls.size(); i++)cout << rolls[i] << " ";
	cout << "\n数据平均值：" << mean << "\t缺失数据数量：" << n;
	vector<int>res = ptr(rolls, mean, n);
	cout << "结果：";
	for (int i = 0; i < n; i++)cout << res[i] << " ";
}
//方法一
//慢！
vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
	int sum = mean*(rolls.size() + n) - accumulate(rolls.begin(), rolls.end(), 0);//输出数组的和
	if (sum > n * 6 || sum < n)return {};//和在数组允许的范围内
	int avg = floor(sum / n);
	vector<int> res(n, avg);
	for (int i = 0; i < sum - avg * n; i++)res[i]++;
	return res;
}

vector<int> missingRolls1(vector<int>& rolls, int mean, int n) {
	int sum = mean * (rolls.size() + n) - accumulate(rolls.begin(), rolls.end(), 0);//输出数组的和
	if (sum > n * 6 || sum < n)return {};//和在数组允许的范围内
	if (sum % n == 0) {
		vector<int> res(n, sum / n);
		return res;
	}
	else {
		int avg = round(sum / n);
		int dis = sum - avg * n;
		if (dis > 0) {
			int shang = dis / (6 - avg);
			int yu = dis % (6 - avg);
			vector<int> res(n-shang-1, avg);
			res.insert(res.end(), shang, 6);
			res.insert(res.end(), avg + yu);
			return res;
		}
		else {
			dis = abs(dis);
			int shang = dis / (avg - 1);
			int yu = dis % (avg - 1);
			vector<int> res(n - shang-1, avg + 1);
			res.insert(res.end(), shang, 1);
			res.insert(res.end(), avg + 1 - yu);
			return res;
		}
	}
}

//else if (avg == 5) {
//	for (int i = 0; i < sum - avg * n; i++) {
//		res[i] = 6;
//	}
//}
//else if (avg == 4) {
//	int chu = sum - avg * n;
//	int shang = chu / 2;
//	int yu = chu % 2;
//	for (int i = 0; i < (int)chu / 2; i++) res[i] = 6;
//	res.end() = res.end() + 1;
//}
//else if (avg == 3) {
//	int chu = sum - avg * n;
//	int shang = chu / 2;
//	int yu = chu % 2;
//	for (int i = 0; i < (int)chu / 2; i++) res[i] = 6;
//	res.end() = res.end() + 1;
//}
//else if (avg == 2) {
//	int chu = sum - avg * n;
//	int shang = chu / 2;
//	int yu = chu % 2;
//	for (int i = 0; i < (int)chu / 2; i++) res[i] = 6;
//	res.end() = res.end() + 1;
//}
//else if (avg == 1) {
//	for (int i = 0; i < sum - avg * n; i++) res[i]++;
//}