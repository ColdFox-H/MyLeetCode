/*给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
*/
#pragma once
#include <vector>
#include <iostream>
#include <time.h>
#include <unordered_map>
#include "SortAlgorithm.h"
#include "SearchAlgorithm.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {};
};
//打印整个链表
void printListNode(ListNode* ln) {
	ListNode* pln = ln;
	while (pln!= nullptr) {
		cout << pln->val << " ";
		pln = pln->next;
	}
}
//用数组创建链表
void creatListNode(vector<int>nums, ListNode* ln) {
	for (int i = 0; i < nums.size(); i++) {
		
	}
}

//
void test2(ListNode* l1, ListNode* l2, ListNode(*ptr)(ListNode* l1, ListNode* l2)) {
	printListNode(l1);
	printListNode(l2);



}