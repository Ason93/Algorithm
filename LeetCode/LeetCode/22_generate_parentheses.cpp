#include "questions.h"

void GenerateParentheses(vector<string>& results, const int n, int left, int right, string bracket)
{
	if (left == n && right == n) {
		results.push_back(bracket);
		return;
	}
	if (left < n)
		GenerateParentheses(results, n, left+1, right, bracket + "(");

	if (right < left && right < n)
		GenerateParentheses(results, n, left, right+1, bracket + ")");

	//if (left < n)
	//	GenerateParentheses(results, n, left+1, right, bracket.append("("));

	//if (right < left && right < n)
	//	GenerateParentheses(results, n, left, right+1, bracket.append(")"));
}

int UseGenerateParentheses()
{
	cout << "*************** 22.Generate Parentheses ***************" << endl;
	vector<string> results;
	const int n = 3;
	string bracket("");
	GenerateParentheses(results, n, 0, 0, bracket);
	cout << "Generate Parentheses: " << endl;
	for (auto result : results) {
		cout << result << endl;
	}
	return 0;
}