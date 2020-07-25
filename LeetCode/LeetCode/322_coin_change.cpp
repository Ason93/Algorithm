#include "questions.h"

int coinChange(vector<int>& coins, int amount) {
	const int n = coins.size();
	vector<int> DP(amount + 1, amount + 1);
	DP[0] = 0;
	for (int i = 1; i <= amount; i++) {
		for (int j = 0; j < n; j++) {
			if (coins[j] <= i) {
				DP[i] = min(DP[i], DP[i - coins[j]] + 1);
			}
		}
	}
	return DP[amount] > amount ? -1 : DP[amount];
}

int UseCoinChange() {
	cout << "*************** 322. Coin Change ***************" << endl;
	vector<int> coins = { 1, 2, 5 };
	const int amount = 11;
	const int result = coinChange(coins, amount);
	cout << "The Minmum Times of Coin Change is: " << result << endl;
	return 0;
}