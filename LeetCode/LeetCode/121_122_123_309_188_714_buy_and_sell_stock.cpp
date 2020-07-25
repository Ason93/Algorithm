#include "questions.h"

// 122. as many transactions as you like
int maxProfit122(vector<int>& prices) {
	const int n = prices.size();
	int result = 0;
	if (n == 0) {
		return result;
	}
	vector<vector<int>> MP(n, vector<int>(2, 0));
	MP[0][0] = 0;  //  zero stock
	MP[0][1] = -prices[0]; // one stock

	for (int i = 1; i < n; i++) {
		MP[i][0] = max(MP[i - 1][0], MP[i - 1][1] + prices[i]);
		MP[i][1] = max(MP[i - 1][1], MP[i - 1][0] - prices[i]);
		result = max(result, MP[i][0]);
	}
	return result;
}

// 121. at most one transaction || 123. at most two transactions || 188. at most k transactions
int maxProfit188(const int k, vector<int>& prices) {
	const int n = prices.size();
	const int times = k <= n / 2 ? k : n / 2; // P.S.: if transaction times > days / 2 ,  transaction times = days / 2
	int result = 0;
	if (n == 0 || times == 0) {
		return result;
	}

	if (k > n / 2){ // P.S.: if transaction times > days / 2 ,  transaction times = as many transactions as you like
		vector<vector<int>> MP(n, vector<int>(2, 0));
		MP[0][0] = 0;  //  zero stock
		MP[0][1] = -prices[0]; // one stock

		for (int i = 1; i < n; i++) {
			MP[i][0] = max(MP[i - 1][0], MP[i - 1][1] + prices[i]);
			MP[i][1] = max(MP[i - 1][1], MP[i - 1][0] - prices[i]);
			result = max(result, MP[i][0]);
		}
	}
	else {
		// init all = -INT16_MAX, but everyday, transaction 0, no stack = 0, day 0, transaction 1, one stack = -prices[0]
		vector<vector<vector<int>>> MP(n, vector<vector<int>>(times + 1, vector<int>(2, -INT16_MAX)));
		MP[0][1][1] = -prices[0];
		for (int i = 0; i < n; i++) {
			MP[i][0][0] = 0;
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= times; j++) {
				MP[i][j][0] = max(MP[i - 1][j][0], MP[i - 1][j][1] + prices[i]); // zero stock
				MP[i][j][1] = max(MP[i - 1][j][1], MP[i - 1][j - 1][0] - prices[i]); // one stock
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= times; j++) {
				result = max(result, MP[i][j][0]);
			}
		}
	}
	return result;
}

// 309. as many transactions as you like, with cooldown
int maxProfit309(vector<int>& prices) {
	const int n = prices.size();
	int result = 0;
	if (n == 0) {
		return result;
	}

	// init all = 0, but day 0, cool down, one stack = -prices[0]
	vector<vector<vector<int>>> MP(n, vector<vector<int>>(2, vector<int>(2, 0)));
	MP[0][0][0] = 0;
	MP[0][0][1] = -prices[0];
	MP[0][1][0] = -INT16_MAX;
	MP[0][1][1] = -INT16_MAX;

	for (int i = 1; i < n; i++) {
			MP[i][0][0] = max(MP[i - 1][0][0], MP[i - 1][1][0]); // no cool down,  zero stock
			MP[i][0][1] = max(MP[i - 1][0][1], MP[i - 1][0][0] - prices[i]); // no cool down, one stock		
			MP[i][1][0] = max(MP[i - 1][1][0], MP[i - 1][0][1] + prices[i]); // cool down, zero stock 
			MP[i][1][1] = MP[i - 1][1][1]; // cool down, one stock 
			result = max(result, max(MP[i][0][0], MP[i][1][0]));
	}
	return result;
}

// 714. as many transactions as you like, with transaction fee
int maxProfit714(vector<int>& prices, const int fee) {
	const int n = prices.size();
	int result = 0;
	if (n == 0) {
		return result;
	}
	vector<vector<int>> MP(n, vector<int>(2, 0));
	MP[0][0] = 0;  //  zero stock
	MP[0][1] = -prices[0]; // one stock

	for (int i = 1; i < n; i++) {
		MP[i][0] = max(MP[i - 1][0], MP[i - 1][1] + prices[i] - fee);
		MP[i][1] = max(MP[i - 1][1], MP[i - 1][0] - prices[i]);
		result = max(result, MP[i][0]);
	}
	return result;
}

int UseBuyAndSellStock() {
	cout << "*************** 121. Best Time to Buy and Sell Stock ***************" << endl;
	//vector<int> input = { 7, 1, 5, 3, 6, 4 };
	//vector<int> input = { 1, 2, 3, 0, 2 };
	vector<int> input = { 1, 3, 2, 8, 4, 9 };
	const int result122 = maxProfit122(input);
	cout << "As Many Transactions as You Like, the Maximum Profit is: " << result122 << endl;

	const int k = 2;
	const int result188 = maxProfit188(k, input);
	cout <<  "At Most " << k << " Transaction, the Maximum Profit is: " << result188 << endl;

	const int result309 = maxProfit309(input);
	cout << "As Many Transactions as You Like, with Cooldown, the Maximum Profit is: " << result309 << endl;

	const int fee = 2;
	const int result714 = maxProfit714(input, fee);
	cout << "As Many Transactions as You Like, with Transaction Fee, the Maximum Profit is: " << result714 << endl;
	return 0;
}