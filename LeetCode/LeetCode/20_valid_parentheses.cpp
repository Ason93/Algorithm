#include "questions.h"

class Solution {
public:
	bool isValid(string s) {
		unordered_map<char, char> symbol_pair = {{')', '('},
												 {']', '['},
												 {'}', '{'}};
		stack<char> symbol_stack;
		for (char ch: s) {
			if (symbol_pair.count(ch) != 0) {
				if (symbol_stack.empty() || symbol_pair[ch] != symbol_stack.top()) {
					return false;
				}
				symbol_stack.pop();
			}
			else {
				symbol_stack.emplace(ch);
			}
		}
		return symbol_stack.empty();
	}
};

// 20. Valid Parentheses
int UseValidParentheses() {
	cout << "*************** 20.Valid Parentheses ***************" << endl;
	string parentheses = "[[[{}]]]()";
	Solution S;
	bool result = S.isValid(parentheses);
	cout << "Whether The String Is Parentheses: " << result << endl;

	return 0;
}

