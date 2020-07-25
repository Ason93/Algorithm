#include "questions.h"

void NQueens(int n, vector<vector<int>>& results, vector<int> queens, vector<int> pie, vector<int> na)
{
	const int p = queens.size(); // num of row
	if (p == n)
	{
		results.push_back(queens);
		return;
	}

	for (int q = 0; q < n; q++) // col
	{
		vector<int>::iterator iq = find(queens.begin(), queens.end(), q);
		vector<int>::iterator ipie = find(pie.begin(), pie.end(), p+q);
		vector<int>::iterator ina = find(na.begin(), na.end(), p-q);

		if (iq == queens.end() && ipie == pie.end() && ina == na.end())
		{
			queens.push_back(q);
			pie.push_back(p + q);
			na.push_back(p - q);
			NQueens(n, results, queens, pie, na);
			// p.s.: if don't meet the conditions, remove it
			queens.pop_back();
			pie.pop_back();
			na.pop_back();
		}

	}
}

void PrintNQueens(vector<vector<int>>& results, vector<vector<string>>& QueenArrays, const int n)
{
	for (auto result : results)
	{
		vector<string> QueenArray;
		for (auto j : result)
		{
			string Queen("");
			for (int i = 0; i < n; i++)
			{
				if (i == j)
					Queen += "Q";
				else
					Queen += ".";
			}
			QueenArray.push_back(Queen);
		}
		QueenArrays.push_back(QueenArray);
	}

	for (auto QueenArray : QueenArrays)
	{
		for (auto Queen : QueenArray)
		{
			cout << Queen << endl;
		}
		cout << endl;
	}
}

int UseNQueens()
{
	cout << "*************** 51/52.N Queens ***************" << endl;
	const int n = 4;
	vector<vector<int>> results;
	NQueens(n, results, {}, {}, {});
	vector<vector<string>> QueenArrays;
	PrintNQueens(results, QueenArrays, n);

	//for (auto result : results)
	//{
	//	for (auto j : result)
	//	{
	//		for (int i = 0; i < n; i++)
	//		{
	//			if (i == j)
	//				cout << "Q";
	//			else
	//				cout << ".";
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//	cout << endl;
	//}


	return 0;
}