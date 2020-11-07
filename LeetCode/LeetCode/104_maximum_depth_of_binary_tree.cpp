#include "questions.h"

//// DFS
//int BinaryTree::MaxDepth(TreeNode* node)
//{
//	if (!node)
//		return 0;
//	else
//		return max(MaxDepth(node->left), MaxDepth(node->right))+1;
//}

// BFS
int BinaryTree::MaxDepth(TreeNode* root) {

	int level_count = 0;

	if (!root)
		return level_count;

	queue<TreeNode*> Q;
	Q.push(root);
	
	while (!Q.empty()) {
		int level_size = Q.size();

		for (int i = 0; i < level_size; i++) {
			TreeNode* node = Q.front();
			Q.pop();
			if (node->left)
				Q.push(node->left);
			if (node->right)
				Q.push(node->right);
		}
		level_count++;
	}

	return level_count;
}

int BinaryTree::UseMaxDepth()
{
	cout << "*************** 104.Maximum Depth of Binary Tree ***************" << endl;
	const int max_depth = MaxDepth(root);
	cout << "Maximum depth of this tree is " << max_depth << endl;
	return 0;
}