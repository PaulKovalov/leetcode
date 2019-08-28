#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_safe(vector<vector<int> > board, int row, int column, int n) {
	int t_r = row, t_c = column;

	// check row at the left
	while (t_c >= 0)  {
		if (board[row][t_c] == 1) return false;
		--t_c;
	}

	// check row at the right
	t_c = column;
	while (t_c < n) {
		if (board[row][t_c] == 1) return false;
		++t_c;
	}

	// check column a the top
	while (t_r >= 0) {
		if (board[t_r][row] == 1) return false;
		--t_r;
	}
	
	t_r = row;
	// check column at the bottom
	while(t_r < n) {
		if (board[t_r][row] == 1) return false;
		++t_r;
	}
	
	
	// check top left diagonal
	t_r = row, t_c = column;
	while (t_c >= 0 && t_r >= 0) {
		if (board[t_r][t_c] == 1) return false;
		--t_c;
		--t_r;
	}
	// check top right diagonal
	t_r = row, t_c = column;
	while (t_c >= 0 && t_r < n) {
		if (board[t_r][t_c] == 1) return false;
		--t_c;
		++t_r;
	}
	return true;
	// // check bottom right diagonal
	// t_r = row, t_c = column;
	// while (t_c < n && t_r < n) {
	// 	if (board[t_c][t_r] == 1) return false;
	// 	++t_c;
	// 	++t_r;
	// }	

	// // check bottom left diagonal
	// t_r = row, t_c = column;
	// while (t_c < n && t_r >= 0) {
	// 	if (board[t_c][t_r] == 1) return false;
	// 	++t_c;
	// 	--t_r;
	// }		
	
}
vector<vector<int> > foo(vector<vector<int> > board, int row, int n) {
	// if came to the last row - solution is found
	if (row == n) {
		return board;
	}
	// start at the row
	for (int i = row; i < n; ++i) {
		// loop over each column and try to place a queen
		for (int j = 0; j < n; ++j) {
			if (is_safe(board, j, i, n)) {
				board[i][j] = 1;
				foo(board, row + 1, n);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<int> > board(n, vector<int>(n, 0));
	vector<vector<int> > result = foo(board, 0, board.size());
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result.size(); ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}