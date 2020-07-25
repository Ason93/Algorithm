#include"questions.h"

int minimumTotal(vector<vector<int>>& triangle) {
	vector<int> min_per_layer = triangle[triangle.size()-1];
	for (int i = triangle.size() - 2; i >= 0; i--) {
		for (int j = 0; j < triangle[i].size(); j++) {
			min_per_layer[j] = triangle[i][j] + min(min_per_layer[j], min_per_layer[j + 1]);
		}
	}
	return min_per_layer[0];
}

int UseMinimumTotal() {
	cout << "*************** 120. Triangle ***************" << endl;
	vector<vector<int>> input = {
		{2},
		{3, 4},
		{6, 5, 7},
		{4, 1, 8, 3}
	};
	const int result = minimumTotal(input);
	cout << "The Minimum of Triangle is: " << result << endl;
	return 0;
}