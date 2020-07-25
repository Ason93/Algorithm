#include "questions.h"

int BinaryTree::UseLevelOrder()
{
	cout << "*************** 102.Binary Tree Level Order Traversal ***************" << endl;
	LevelOrder(root, 0);
	cout << "[" << endl;
	for (auto out1 : data_ordered)
	{
		cout << "[";
		for (auto out2 : out1)
		{
			cout << out2 << ",";
		}
		cout << "]," << endl;
	}
	cout << "]" << endl;
	return 0;
}

void BinaryTree::LevelOrder(TreeNode* node, int depth)
{
	if (!node) 
		return;
	if (depth >= data_ordered.size())
		data_ordered.push_back(vector<int>{});
	data_ordered[depth].push_back(node->val);
	LevelOrder(node->left, depth + 1);
	LevelOrder(node->right, depth + 1);
}