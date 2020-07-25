#include "questions.h"

class TrieNode {
public:
	TrieNode() :is_string(false) {

	}
	~TrieNode() {
		for (auto& leave : leaves) {
			if (leave.second) {
				delete leave.second;
			}
		}
	}
	void insert(string word) {
		auto* cur_ = this;
		for (const auto& c : word) {
			if (!cur_->leaves.count(c)) {
				cur_->leaves[c] = new TrieNode();
			}
			cur_ = cur_->leaves[c];
		}
		cur_->is_string = true;
	}

	bool is_string;
	unordered_map<char, TrieNode*> leaves;
};


class Trie {
public:
	Trie() {
		root_ = new TrieNode();
	}

	// 79.Word Search
	bool exist(vector<vector<char>>& board, string word) {
		TrieNode trie;
		trie.insert(word);

		const int row = board.size();
		const int col = board[0].size();
		string result;
		vector<vector<char>> visited(row, vector<char>(col, false));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (findWordDFS(board, &trie, i, j, visited, result))
					return true;
			}
		}
		return false;
	}

	bool findWordDFS(vector<vector<char>>& board, TrieNode* trie, int i, int j, vector<vector<char>>& visited, string result) {

		const int row = board.size();
		const int col = board[0].size();
		if (i < 0 || i >= row || j < 0 || j >= col) {
			return false;
		}

		char& c = board[i][j];
		if (visited[i][j] || !trie->leaves.count(c)) {
			return false;
		}

		result += c;
		visited[i][j] = true;
		trie = trie->leaves[c];
		if (trie->is_string)
			return true;

		bool flag = findWordDFS(board, trie, i, j - 1, visited, result) ||
			findWordDFS(board, trie, i, j + 1, visited, result) ||
			findWordDFS(board, trie, i - 1, j, visited, result) ||
			findWordDFS(board, trie, i + 1, j, visited, result);

		visited[i][j] = false;

		return flag;
	}

	// 212.Word Search II
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		string result;
		vector<string> results;
		for (const auto& word : words) {
			root_->insert(word);
		}

		const int row = board.size();
		const int col = board[0].size();
		vector<vector<bool>> visited(row, vector<bool>(col, false));

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				findWordDFS(board, visited, root_, i, j, result, results);
			}
		}
		return results;
	}

	void findWordDFS(vector<vector<char>>& board, vector<vector<bool>>& visited, TrieNode* trie, int i, int j, string result, vector<string>& results) {

		const int row = board.size();
		const int col = board[0].size();
		if (!trie || i < 0 || i >= row || j < 0 || j >= col) {
			return;
		}

		char& word = board[i][j];
		if (!trie->leaves[word] || visited[i][j])
			return;

		result += word;
		visited[i][j] = true;
		TrieNode* nextNode = trie->leaves[word];
		if (nextNode->is_string) {
			vector<string>::iterator it = find(results.begin(), results.end(), result);
			if(it == results.end())
				results.push_back(result);
		}

		int x[4] = { -1, 1, 0, 0 };
		int y[4] = { 0, 0, -1, 1 };

		for (int k = 0; k < 4; k++) {
			findWordDFS(board, visited, nextNode, i + x[k], j + y[k], result, results);
		}
		visited[i][j] = false;
	}

private:
	TrieNode* root_;
};

int UseFindWords() {
	cout << "*************** 79/212. Word Search ***************" << endl;

	//vector<vector<char>> board = {
	//	{'o', 'a', 'a', 'n'},
	//	{'e', 't', 'a', 'e'},
	//	{'i', 'h', 'k', 'r'},
	//	{'i', 'f', 'l', 'v'}
	//};
	//vector<string> words = { "oath", "pea", "eat", "rain" };

	vector<vector<char>> board = {
	{'a', 'a'}
	};
	string word = "a";
	vector<string> words = { "a" };

	Trie trie;
	bool flag = trie.exist(board, word);
	vector<string> results = trie.findWords(board, words);
	cout << "The Result of Word Search is: " << flag << endl;
	for (const auto& result : results) {
		cout << result << ",";
	}
	cout << endl;

	return 0;
}