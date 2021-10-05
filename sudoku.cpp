#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void backtrack(vector<vector<char>> board, vector<vector<char>>& answer) {
        int coord_i = -1, coord_j = -1;
        for (int i = 0; i < 9; ++i) {
            if (coord_i == -1) {
                for (int j = 0; j < 9; ++j) {
                    if (board[i][j] == '.') {
                        coord_i = i;
                        coord_j = j;
                        break;
                    }
                }
            }
        }
        if (coord_i == -1) {
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    cout << board[i][j] << " ";
                    answer[i][j] = board[i][j];
                }
                cout << endl;
            }
            return;
        }
        // get square top left corner coord
        int r = (coord_i / 3) * 3;
        int c = (coord_j / 3) * 3;
        int r_to = r + 3;
        int c_to = c + 3;
        // cout << coord_i << " " << j << " " << r << " " << c << " " << r_to << " " << c_to << endl;
        vector<int> available(10, 1);
        for (; r < r_to; ++r) {
            for (; c < c_to; ++c) {
                int taken = board[r][c] - '0';
                if (taken >= 1 && taken <= 9)
                    available[taken] = 0;
            }
        }
        for (int k = 0; k < 9; ++k) {
            int taken = board[coord_i][k] - '0';
            if (taken >= 1 && taken <= 9)
                available[taken] = 0;
            taken = board[k][coord_j] - '0';
            if (taken >= 1 && taken <= 9)
                available[taken] = 0;
        }
        for (int k = 1; k < 9; ++k) {
            if (available[k]) {
                board[coord_i][coord_j] = k + '0';
                backtrack(board, answer);
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, board);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution solution;
    solution.solveSudoku(board);
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
