#include "questions.h"

int BinaryTree::MaxDepth(TreeNode* node)
{
	if (!node)
		return 0;
	else
		return max(MaxDepth(node->left), MaxDepth(node->right))+1;
}

int BinaryTree::UseMaxDepth()
{
	cout << "*************** 104.Maximum Depth of Binary Tree ***************" << endl;
	const int max_depth = MaxDepth(root);
	cout << "Maximum depth of this tree is " << max_depth << endl;
	return 0;
}