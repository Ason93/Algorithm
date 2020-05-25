/**************************************************
			  Majority count(x)>n/2
Example1:
input:[1, 3, 3, 2, 3]
output:3
Example2:
input:[1, 1, 1, 0, 2]
output:1
***************************************************/

#include "questions.h"

int MyMajority(vector<int>& nums)
{
	// Time:  O(n)
	// Space: O(1)
	int ans = nums[0];
	int cnt = 1;
	for (const auto& i : nums)
	{
		if (i == ans)
			++cnt;
		else
		{
			--cnt;
			if (cnt == 0)
			{
				ans = i;
				cnt = 1;
			}
		}
	}
	return ans;
}

int UseMyMajority()
{
	cout << "*************** 169.Majority ***************" << endl;

	vector<int> nums{ 1, 3, 3, 2, 3 };
	int majority = MyMajority(nums);
	cout << "Majority of nums is: " << majority << endl;

	cout << endl;
	return 0;
}