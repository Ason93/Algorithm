#include "questions.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValid(root, LONG_MIN, LONG_MAX); // if INT32_MAX£¬can not pass
	}

	bool isValid(TreeNode* root, long minVal, long maxVal) {
		if (root == nullptr)
			return true;
		if (root->val >= maxVal || root->val <= minVal)
			return false;
		return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal);
	}
};


int UseIsValidBST() {

	cout << "*************** 98. Validate Binary Search Tree ***************" << endl;

	BinaryTree* tree  = new BinaryTree();

	Solution S;
	bool results = S.isValidBST(tree->root);

	cout << "Whether the Tree is Validate Binary Search Tree : " << results << endl;

	delete tree;

	return 0;
}