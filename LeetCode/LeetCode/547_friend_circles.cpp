#include "questions.h"

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		const int m = M.size();
		const int n = M[0].size();
		assert(m == n);
		Circles circles(m);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (M[i][j] && i != j) {
					circles.unionCircle(i, j);
				}
			}
		}
		return circles.size();
	}
	
private:
	class Circles {
	public:
		Circles(const int n): roots_(n), count_(n) {
			iota(roots_.begin(), roots_.end(), 0);
		}

		int findRoot(const int x) {
			if (x != roots_[x]) {
				roots_[x] = findRoot(roots_[x]); // Path Compression.
			}
			return roots_[x];
		}

		void unionCircle(const int i, const int j) {
			int root_i = findRoot(i);
			int root_j = findRoot(j);
			if (root_i != root_j) {
				roots_[min(root_i, root_j)] = max(root_i, root_j);
				count_--;
			}
		}

		int size() {
			return count_;
		}

	private:
		vector<int> roots_;
		int count_;
};
};

int UseFriendCircles() {
	cout << "*************** 547.Friend Circles ***************" << endl;
	//vector<vector<int>> M = {
	//{1, 1, 0},
	//{1, 1, 1},
	//{0, 1, 1}
	//};
	//vector<vector<int>> M = {
	//{1, 1, 0},
	//{1, 1, 0},
	//{0, 0, 1}
	//};
	vector<vector<int>> M = {
	{1, 1, 1},
	{1, 1, 1},
	{1, 1, 1}
	};
	Solution S;
	const int result = S.findCircleNum(M);
	cout << "The Number of Friend Circles Is: " << result << endl;

	return 0;
}
