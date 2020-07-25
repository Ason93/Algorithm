#include "binary_tree.h"

BinaryTree::BinaryTree()
{
	data = new int[7]{ 3, 9, 20, NULL, NULL, 15, 7 };
	//root = CreateTree(0);
	root = CreateTree(0, 7);
}

BinaryTree::~BinaryTree()
{
	delete data;
	delete root;
}

TreeNode* BinaryTree::CreateTree(int i, const int len)
{
	TreeNode* node = NULL;
	if (data[i] && i<len)
	{
		node = new TreeNode(data[i]);
		node->left = CreateTree(2 * i + 1, len);
		node->right = CreateTree(2 * i + 2, len);
	}
	return node;
}