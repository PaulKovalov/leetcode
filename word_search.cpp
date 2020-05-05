class Solution {
public:
    bool exists_recursive(vector<vector<char>>& board, string word,int idx, int curr_x, int curr_y, vector<vector<bool> > used) {
        if (idx >= word.size()) {
            return true;
        }
        used[curr_x][curr_y] = true;
        bool result = false;
        if (curr_x > 0) {
            if (board[curr_x - 1][curr_y] == word[idx] && !used[curr_x - 1][curr_y]) {
                result = result || exists_recursive(board, word, idx+1, curr_x - 1, curr_y, used);
            }
        }
        if (curr_x < board.size() - 1) {
            if (board[curr_x + 1][curr_y] == word[idx] && !used[curr_x + 1][curr_y]) {
                result = result || exists_recursive(board, word, idx+1, curr_x + 1, curr_y, used);
            }
        }
        if (curr_y > 0) {
            if (board[curr_x][curr_y - 1] == word[idx] && !used[curr_x][curr_y - 1]) {
                result = result || exists_recursive(board, word, idx+1, curr_x, curr_y - 1, used);
            }
        }
        if (curr_y < board[0].size() - 1) {
            if (board[curr_x][curr_y + 1] == word[idx] && !used[curr_x][curr_y + 1]) {
                result = result || exists_recursive(board, word, idx+1, curr_x, curr_y + 1, used);
            }
        }
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool> > used(board.size(), vector<bool>(board[0].size()));
                    if (exists_recursive(board, word,1,i,j, used)) {
                        return true;
                    }
                }
            }
        }
        return res;
    }
};  