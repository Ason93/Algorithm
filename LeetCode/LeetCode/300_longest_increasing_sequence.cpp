#include "questions.h"

int lengthOfLIS(vector<int>& nums) {
	const int n = nums.size();
	int result = 1;
	if (n == 0) {
		return 0;
	}
	vector<int> LS(n, 1);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[j] < nums[i] ) {
				LS[i] = max(LS[i], LS[j] + 1);
			}
		}
		result = max(result, LS[i]);
	}
	return result;
}

int UseLongestIncreasingSubsequence() {
	cout << "*************** 300. Longest Increasing Subsequence ***************" << endl;
	vector<int> input = { 10, 9, 2, 5, 3, 7, 101, 18 };
	const int result = lengthOfLIS(input);
	cout << "The Num of Longest Increasing Subsequence is: " << result << endl;
	return 0;
}