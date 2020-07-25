#include "questions.h"

int main()
{
	// 50.Pow
	UseMyPow();
	// 169.Majority
	UseMyMajority();
	// 122.Buy/Sell Stocks
	UseBuySellStocks();

	BinaryTree binary_tree;
	// 102.Binary Tree Level Order Traversal
	binary_tree.UseLevelOrder();
	// 104.Maximum Depth of Binary Tree
	binary_tree.UseMaxDepth();
	// 111.Minimum Depth of Binary Tree
	binary_tree.UseMinDepth();

	// 22.Generate Parentheses
	UseGenerateParentheses();

	// 51/52.N_Quees
	UseNQueens();

	// 36/37.Sudoku
	UseSudoku();

	// 367/69.Sqrt
	UseSqrt();

	// 208.Trie
	UseTrie();

	// 79/212.Word Search
	UseFindWords();

	// 191.Number of 1 Bits
	UseHammingWeight();

	// 70.Climbing Stairs
	UseClimbStairs();

	// 120.Triangle
	UseMinimumTotal();

	// 152.Maximum Product Subarray
	UseMaxProduct();

	// 121/122/123/309/188/714.Buy and Sell Stock
	UseBuyAndSellStock();

	// 300.Longest Increasing Subsequence
	UseLongestIncreasingSubsequence();

	// 322.Coin Change
	UseCoinChange();

	// 72.Edit Distance
	UseMinDistance();

	// 200.Number of Islands
	UseNumIslands();

	// 547.Friend Circles
	UseFriendCircles();

	// 146.LRU Cache
	UseLRUCache();

	return 0;
}