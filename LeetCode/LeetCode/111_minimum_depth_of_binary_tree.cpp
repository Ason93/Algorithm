#include "questions.h"

//// DFS
//int BinaryTree::MinDepth(TreeNode* node)
//{
//	if (!node)
//		return 0;
//	//if (!node->left)
//	//	return MinDepth(node->right) + 1;
//	//if (!node->right)
//	//	return MinDepth(node->left) + 1;
//
//	return min(MinDepth(node->left), MinDepth(node->right)) + 1;
//}

// BFS
int BinaryTree::MinDepth(TreeNode* root) {

	int level_count = 0;

	if (!root)
		return level_count;

	queue<TreeNode*> Q;
	Q.push(root);
	level_count++;

	while (!Q.empty()) {
		int level_size = Q.size();

		for (int i = 0; i < level_size; i++) {
			TreeNode* node = Q.front();
			Q.pop();
			if (!node->left)
				Q.push(node->right);
			if (!node->right)
				Q.push(node->left);
		}
		level_count++;
	}

	return level_count;
}

int BinaryTree::UseMinDepth()
{
	cout << "*************** 104.Minimum Depth of Binary Tree ***************" << endl;
	const int min_depth = MinDepth(root);
	cout << "Minimum depth of this tree is " << min_depth << endl;
	return 0;
}