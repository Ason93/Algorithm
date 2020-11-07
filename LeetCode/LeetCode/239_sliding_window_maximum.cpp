#include "questions.h"

// P.S.: Must have index info, otherwise, we don't know whether is out of window.
class Solution {
public:
	// Method 1 Priority Queue. O(nlog(k))
	vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
		
		if (nums.empty()) {
			return {};
		}
		vector<int> results;
		priority_queue<pair<int, int>> window;
		for (int i = 0; i < nums.size(); i++) {
			while (!window.empty() && window.top().second <= i - k)
				window.pop();
			window.push({nums[i], i});
			if (i >= k - 1) {
				results.push_back(window.top().first);
			}
		}

		return results;
    }

	// Method 2 Queue. O(n)
	vector<int> maxSlidingWindow2(vector<int>& nums, int k) {

		vector<int> results;
		deque<int> max_index;
		if (nums.empty()) {
			return {};
		}
		max_index.push_front(0);
		for (int i = 0; i < nums.size(); i++) {
			if (i >= k && max_index[0] <= i - k)
				max_index.pop_front();
			while (!max_index.empty() && nums[max_index.back()] <= nums[i])
				max_index.pop_back();
			max_index.push_back(i);
			if (i >= k - 1) {
				results.push_back(nums[max_index[0]]);
			}
		}

		return results;
	}
};

// 239. Sliding Window Maximum
int UseSlidingWindowMaximum() {

	cout << "*************** 239.Sliding Windows Maximum ***************" << endl;
	vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
	int k = 3;

	//vector<int> nums = { 1, -1 };
	//int k = 1;

	Solution S;
	vector<int> results = S.maxSlidingWindow1(nums, k);
	cout << "Sliding Windows Maximum is: " << endl;
	for(int result: results)
		cout  << result << endl;
	return 0;
}