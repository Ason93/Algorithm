#include "questions.h"

int BinaryTree::MinDepth(TreeNode* node)
{
	if (!node)
		return 0;
	if (!node->left)
		return MinDepth(node->right) + 1;
	if (!node->right)
		return MinDepth(node->left) + 1;

	return min(MinDepth(node->left), MinDepth(node->right)) + 1;
}

int BinaryTree::UseMinDepth()
{
	cout << "*************** 104.Minimum Depth of Binary Tree ***************" << endl;
	const int min_depth = MinDepth(root);
	cout << "Minimum depth of this tree is " << min_depth << endl;
	return 0;
}