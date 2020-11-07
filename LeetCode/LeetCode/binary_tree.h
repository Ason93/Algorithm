#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
class BinaryTree
{
private:
	int* data;
	TreeNode* root;
	vector<vector<int>> data_ordered;
public:
	BinaryTree();
	~BinaryTree();
	TreeNode* CreateTree(int i, const int len);
	//TreeNode* CreateTree(int i);
	int UseLevelOrder();
	void LevelOrder(TreeNode* node, int depth);  // DFS
	void LevelOrder(TreeNode* root); // BFS
	int UseMaxDepth();
	//int MaxDepth(TreeNode* node); // DFS
	int MaxDepth(TreeNode* root); // BFS
	int UseMinDepth();
	//int MinDepth(TreeNode* node); // DFS
	int MinDepth(TreeNode* root); // BFS
};

#endif // !_BINARY_TREE_H_
