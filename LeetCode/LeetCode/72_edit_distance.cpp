#include "questions.h"

int minDistance(string word1, string word2) {
	const int m = word1.length();
	const int n = word2.length();
	vector<vector<int>> DP(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= m; i++) {
		DP[i][0] = i;
	}
	for (int j = 0; j <= n; j++) {
		DP[0][j] = j;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (word1[i-1] == word2[j-1]) {
				DP[i][j] = DP[i-1][j-1];
			}
			else {
				DP[i][j] = min(DP[i - 1][j - 1], min(DP[i][j - 1], DP[i - 1][j])) + 1;
			}
		}
	}
	return DP[m][n];
}

int UseMinDistance() {
	cout << "*************** 72. Edit Distance ***************" << endl;
	const string word1 = "horse";
	const string word2 = "ros";
	const int result = minDistance(word1, word2);
	cout << "The Minmum Distance of Two Words is: " << result << endl;
	return 0;
}