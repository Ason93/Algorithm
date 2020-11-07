#include "questions.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> lookup;

        for (int i = 0; i < nums.size(); i++) {
            if (lookup.count(target - nums[i])) {
                return { lookup[target - nums[i]], i };
            }
            lookup[nums[i]] = i;
        }

        return {};
    }
};

int UseTwoSum() {

    cout << "*************** 1. Two Sum ***************" << endl;

    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    vector<int> results;
    Solution S;
    results = S.twoSum(nums, target);
    cout << "The sum of the two numbers is " << target << ": " << endl;
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}