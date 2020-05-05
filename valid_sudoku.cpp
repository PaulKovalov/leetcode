class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_map<char, int> s;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    s[board[i][j]]++;
                    if (s[board[i][j]] > 1) {
                        return false;
                    }
                }
            }
            unordered_map<char, int>().swap(s);
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] != '.') {
                    s[board[j][i]]++;
                    if (s[board[j][i]] > 1) {
                        return false;
                    }
                }
            }
        } 
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                unordered_map<char, int> s;
                for (int r = 0; r < 3; ++r) {
                    for (int c = 0; c < 3; ++c) {
                        if (board[r + 3*i][c + 3*j] != '.') {
                            s[board[r + 3*i][c + 3*j]]++;
                            if (s[board[r + 3*i][c + 3*j]] > 1) {
                                return false;
                            }
                        }
                    }
                }    
            }
        }
        return true;
    }
};