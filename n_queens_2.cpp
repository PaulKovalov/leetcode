class Solution {
public:
    public:
    typedef vector<vector<int>> vvi;
vvi board;
bool is_safe(int r, int c, int n) {
    // check queen at position board[r][c]
    // firstly check straight lines
    for (int i = 0; i <= n; ++i) {
        if (board[r][i] || board[i][c])
            return false;
    }
    // next check diagonals
    int r0 = r - min(r, c), c0 = c - min(r, c);
    int r1 = max(0, r - (n - c)), c1 = c + (min(r, n - c));
    while (r0 <= n && c0 <= n) {
        if (board[r0++][c0++])
            return false;
    }
    while (r1 <= n && c1 >= 0) {
        if (board[r1++][c1--])
            return false;
    }
    return true;
}

void backtrack_stupid(const int &n, int& total_solutions, int curr_row = 0) {
    if (curr_row >= n) {
        ++total_solutions;
		return;
    }
    for (int i = 0; i < n; ++i) {
        if (is_safe(curr_row, i, n - 1)) {
            board[curr_row][i] = 1;
            backtrack_stupid(n, total_solutions, curr_row + 1);
            board[curr_row][i] = 0;
        }
    }
}
    int totalNQueens(int n) {
        board.resize(n, vector<int>(n, 0));
        int total = 0;
        backtrack_stupid(n, total);
        return total;
    }
};