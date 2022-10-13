#pragma once
#include <vector>
#include<numeric>
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int countNodes(TreeNode* root) {
    vector<TreeNode*>vNode;
    while (root || vNode.empty()) {
        if (root) {
            vNode.push_back(root);
            root = root->left;
        }
        else {
            root = vNode[0];
            vNode.erase(vNode.begin());
            root = root->right;
        }
    }
    return 0;
}