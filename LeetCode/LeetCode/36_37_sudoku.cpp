#include "questions.h"
#include <array>

/**************************** 37 *******************************/
bool isValid(vector<vector<char>>& board, int i, int j, char c){
	const int n = board.size();
	for (int k = 0; k < n; k++) {
		if (board[i][k] != '.' && c == board[i][k]) {
			return false;
			}
		if (board[k][j] != '.' && c == board[k][j]) {
			return false;
		}
		if (board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] != '.'
			&& c == board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3]) {
			return false;
		}
	}
	return true;
}

bool Sudoku(vector<vector<char>>& board){
	const int row = board.size();
	const int col = board[0].size();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == '.') {
				for (char c = '1'; c <= '9'; c++) {
					if (isValid(board, i, j, c)) {
						board[i][j] = c;
						if (Sudoku(board))
							return true;
						else
							board[i][j] = '.';
					}
				}
				return false;
			}
		}
	}
	return true;
}

///**************************** 36 *******************************/
//bool isValid(vector<vector<char>>& board, int i, int j, char c) {
//	const int n = board.size();
//	for (int k = 0; k < n; k++) {
//		if (j != k && c == board[i][k]) {
//			return false;
//		}
//		if (i != k && c == board[k][j]) {
//			return false;
//		}
//		if (3 * (i / 3) + k / 3 != i && 3 * (j / 3) + k % 3 != j
//			&& c == board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3]) {
//			return false;
//		}
//	}
//	return true;
//}
//
//bool Sudoku(vector<vector<char>>& board) {
//	const int row = board.size();
//	const int col = board[0].size();
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			if (board[i][j] != '.') {
//				char c = board[i][j];
//				if (!isValid(board, i, j, c)) {
//					return false;
//				}
//			}
//		}
//	}
//	return true;
//}


int UseSudoku() {
	cout << "*************** 36/37.Sudoku ***************" << endl;
	// true
	vector<vector<char>> board = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	//// false
	//vector<vector<char>> board = {
	//	{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
	//	{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	//	{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	//	{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	//	{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	//	{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	//	{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	//	{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	//	{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	//};
	//// true
	//vector<vector<char>> board = {
	//	{'.', '8', '7', '6', '5', '4', '3', '2', '1'},
	//	{'2', '.', '.', '.', '.', '.', '.', '.', '.'},
	//	{'3', '.', '.', '.', '.', '.', '.', '.', '.'},
	//	{'4', '.', '.', '.', '.', '.', '.', '.', '.'},
	//	{'5', '.', '.', '.', '.', '.', '.', '.', '.'},
	//	{'6', '.', '.', '.', '.', '.', '.', '.', '.'},
	//	{'7', '.', '.', '.', '.', '.', '.', '.', '.'},
	//	{'8', '.', '.', '.', '.', '.', '.', '.', '.'},
	//	{'9', '.', '.', '.', '.', '.', '.', '.', '.'},
	//};

	cout << "The Questions of Sudoku is: " << endl;

	for (auto board_row : board) {
		for (auto num : board_row) {
			cout << num << ",";
		}
		cout << endl;
	}

	if (!board.empty()){
		bool flag = Sudoku(board);
		//bool flag = isValidSudoku(board);
		cout << "The Solution of Sudoku is: " << flag << endl;
		if (flag) {
			for (auto board_row : board) {
				for (auto num : board_row) {
					cout << num << ",";
				}
				cout << endl;
			}
		}
	}

	return 0;
}