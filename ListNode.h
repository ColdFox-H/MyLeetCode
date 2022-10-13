#pragma once
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createListNode(vector<int>nums) {
	ListNode* head = new ListNode;
}

ListNode* insertHead(ListNode* &head, int val) {
	ListNode* temp = new ListNode;
	temp->val = val;
	if (head == nullptr) {
		head = temp;
		head->next = nullptr;
	}
	else {
		temp->next = head;
		head = temp;
	}
	return head;
}