/**************************************************
			  Buy/Sell Stocks

持有1股或者0股，
买卖无数次

Example1:
input:[7, 1, 5, 3, 6, 4]
output:7
Example2:
input:[1, 2, 3, 4, 5]
output:4
Example3:
input:[7, 6, 3, 2]
output:0
***************************************************/
#include "questions.h"

//Greedy O(n)
int BuySellStocks(vector<int> stock_prices)
{
	int profit = 0;
	for (int i = 0; i < stock_prices.size()-1; i++)
	{
		if (stock_prices[i + 1] - stock_prices[i]>0)
		{
			profit += stock_prices[i + 1] - stock_prices[i];
		}
	}
	return profit;
}

int UseBuySellStocks()
{
	cout << "*************** 122.Buy/Sell Stocks ***************" << endl;
	vector<int> stock_prices{ 7, 1, 5, 3, 6, 4 };
	int profit = BuySellStocks(stock_prices);
	cout << "The max profit of this stock is: " << profit << endl;
	return 0;
}

