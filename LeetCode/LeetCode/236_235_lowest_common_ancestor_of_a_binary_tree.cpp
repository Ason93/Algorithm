#include "questions.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	// 236
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == p || root == q)
			return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		return left ? (right ? root : left): right;
    }

	//// 235(method 1)
	//TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	//	if(root->val > p->val && root->val > q->val)
	//		return lowestCommonAncestor(root->left, p, q);
	//	if (root->val < p->val && root->val < q->val)
	//		return lowestCommonAncestor(root->right, p, q);
	//	return root;
	//}

	//// 235(method 2)
	//TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	//	while (root) {
	//		if (root->val > p->val && root->val > q->val)
	//			root = root->left;
	//		else if (root->val < p->val && root->val < q->val)
	//			root = root->right;
	//		else
	//			return root;
	//	}
	//}
};


int UselowestCommonAncestor() {

	cout << "*************** 236/235. Lowest Common Ancestor of a Binary Tree ***************" << endl;

	BinaryTree* tree = new BinaryTree();

	Solution S;
	TreeNode* ancestor = S.lowestCommonAncestor(tree->root, tree->p, tree->q);

	cout << "Lowest Common Ancestor of a Binary Tree : " << ancestor->val << endl;

	delete tree;

	return 0;
}