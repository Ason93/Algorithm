#include "questions.h"

class Solution {
protected:
	set< pair<int, int> > visited;
	int m = 0;
	int n = 0;
	const int x[4] = { -1, 1, 0, 0 };
	const int y[4] = { 0, 0, -1, 1 };
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) {
			return 0;
		}
		m = grid.size();
		n = grid[0].size();
		int count = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				count += floodFillDFS(i, j, grid);
			}
		}
		return count;
	}

	int floodFillDFS(const int i, const int j, vector<vector<char>>& grid) {
		if (!isValid(i, j, grid))
			return 0;
		visited.insert(make_pair(i, j));
		for (int k = 0; k < 4; k++) {
			floodFillDFS(i + x[k], j + y[k], grid);
		}
		return 1;
	}

	bool isValid(const int i, const int j, vector<vector<char>>& grid) {
		if (i < 0 || i >= m || j < 0 || j >= n) {
			return false;
		}
		if (grid[i][j] == '0' || visited.count(make_pair(i, j)) == 1) {
			return false;
		}
		return true;
	}
};

//class Solution {
//protected:
//	int m = 0;
//	int n = 0;
//	const int x[4] = { -1, 1, 0, 0 };
//	const int y[4] = { 0, 0, -1, 1 };
//public:
//	int numIslands(vector<vector<char>>& grid) {
//		if (grid.empty() || grid[0].empty()) {
//			return 0;
//		}
//		m = grid.size();
//		n = grid[0].size();
//		int count = 0;
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				count += floodFillDFS(i, j, grid);
//			}
//		}
//		return count;
//	}
//
//	int floodFillDFS(const int i, const int j, vector<vector<char>>& grid) {
//		if (i < 0 || i >=m || j < 0 || j >=n )
//			return 0;
//		if (grid[i][j] == '0')
//			return 0;
//		grid[i][j] = '0';
//		for (int k = 0; k < 4; k++) {
//			floodFillDFS(i + x[k], j + y[k], grid);
//		}
//		return 1;
//	}
//};


int UseNumIslands() {
	cout << "*************** 200.Number of Islands ***************" << endl;
	//vector<vector<char>> grid = {
	//	{'1', '1', '1', '1', '0'},
	//	{'1', '1', '0', '1', '0'},
	//	{'1', '1', '0', '0', '0'},
	//	{'0', '0', '0', '0', '0'}
	//};
	vector<vector<char>> grid = {
	{'1', '1', '0', '0', '0'},
	{'1', '1', '0', '0', '0'},
	{'0', '0', '1', '0', '0'},
	{'0', '0', '0', '1', '1'}
	};
	Solution S;
	const int result = S.numIslands(grid);
	cout << "The Number of Islands Is: " << result << endl;

	return 0;
}

