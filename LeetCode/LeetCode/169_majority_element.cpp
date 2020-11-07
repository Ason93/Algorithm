#include "questions.h"

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		// Cause: The majority element is the element that appears more than n / 2 times.
		int ans = nums[0];
		int cnt = 0;
		for (int num : nums) {
			if (num == ans) {
				cnt++;
			}
			else {
				--cnt;
				if (cnt == 0) {
					ans = num;
					cnt = 1;
				}
			}
		}
		return ans;
	}

};

int UseMajorityElement() {
	cout << "*************** 169. Majority Element ***************" << endl;
	vector<int> inputs = { 2, 2, 1, 1, 1, 2, 2 };
	Solution S;
	const int result = S.majorityElement(inputs);
	cout << "The Majority Element is: " << result << endl;
	return 0;
}