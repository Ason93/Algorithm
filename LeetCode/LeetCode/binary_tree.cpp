#include "binary_tree.h"

BinaryTree::BinaryTree()
{
	////data = new int[7]{ 3, 9, 20, NULL, NULL, 15, 7 };
	//data = new int[7]{ 3, 2, 20, NULL, NULL, 10, 30 };
	//root = CreateTree(0, 7);
	////root = CreateTree(0);

	data = new int[15]{ 6, 2, 8, -1, 4, 7, 9, NULL, NULL, 3, 5, NULL, NULL, NULL, NULL };
	root = CreateTree(0, 15);
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
		if (i == 3) p = node;
		if (i == 10) q = node;
		node->left = CreateTree(2 * i + 1, len);
		node->right = CreateTree(2 * i + 2, len);
	}
	return node;
}