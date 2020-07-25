#include "questions.h"

int maxProduct(vector<int>& nums) {
	if (nums.empty())
		return 0;

	vector<vector<int>> states(2, vector<int>(nums.size()));
	states[0][0] = nums[0];
	states[1][0] = nums[0];

	for (int i = 1; i < nums.size(); i++) {
			states[0][i] = max(nums[i] * states[0][i - 1], max(nums[i] * states[1][i - 1], nums[i]));
			states[1][i] = min(nums[i] * states[1][i - 1], min(nums[i] * states[0][i - 1], nums[i]));
	}
	return *max_element(states[0].begin(), states[0].end());
}

int UseMaxProduct() {
	cout << "*************** 152. Maximum Product Subarray ***************" << endl;
	vector<int> input = {2, 3, -2, 4};
	const int result = maxProduct(input);
	cout << "The Maximum Product Subarray is: " << result << endl;
	return 0;
}