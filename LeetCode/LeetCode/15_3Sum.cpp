#include "questions.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        if (nums.size() < 3) {
            return {};
        }
        sort(nums.begin(), nums.end()); // Remove repetition
        set<vector<int>> res;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) // For time limit exceeded
                continue;
            unordered_map<int, int> d;
            for (int j = i + 1; j < nums.size(); j++) {
                if (d.count(nums[j]) == 0) {
                    d[-nums[i] - nums[j]] = 1; // Trick
                }
                else {
                    res.insert({nums[i], nums[j], -nums[i]-nums[j]});
                }
            }
        }

        vector<vector<int>> results;
        results.assign(res.begin(), res.end());

        return results;
    }
};

int UseThreeSum() {

    cout << "*************** 15. 3Sum ***************" << endl;

    vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> results;
    Solution S;
    results = S.threeSum(nums);
    cout << "The three numbers whose sum is 0 are: " << endl;
    for (vector<int>& result : results) {
        cout << "[";
        for (int res : result) {
            cout << res << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}