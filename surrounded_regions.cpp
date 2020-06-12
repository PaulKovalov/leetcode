#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    typedef vector<vector<char>> board;
    bool check(board& b, int i, int j) {
        board used(b.size(), vector<char>(b[0].size(), 0));
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        while(!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            i = top.first;
            j = top.second;
            if (i == 0 || i == b.size() - 1 || j == 0 || j == b[i].size() - 1) {
                return false;
            }
            
            used[i][j] = true;
            if (b[i - 1][j] == 'O' && !used[i - 1][j])
                q.push(make_pair(i - 1, j));
            if (b[i + 1][j] == 'O' && !used[i + 1][j])
                q.push(make_pair(i + 1, j));
            if (b[i][j - 1] == 'O' && !used[i][j - 1])
                q.push(make_pair(i, j - 1));
            if (b[i][j + 1] == 'O' && !used[i][j + 1])
                q.push(make_pair(i, j + 1));
        }
        return true;
    }

    void color(board& b, int i, int j) {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        while(!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            i = top.first;
            j = top.second;
            b[i][j] = 'X';
            cout << "color " << i <<  " " << j << endl;
            if (b[i - 1][j] == 'O' && i - 1 > 0)
                q.push(make_pair(i - 1, j));
            if (b[i + 1][j] == 'O' && i + 1 < b.size())
                q.push(make_pair(i + 1, j));
            if (b[i][j - 1] == 'O' && j - 1 > 0)
                q.push(make_pair(i, j - 1));
            if (b[i][j + 1] == 'O' && j + 1 < b[i].size())
                q.push(make_pair(i, j + 1));
        }
    }

    void bad(board& bb, board& b, int i, int j) {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        while(!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            i = top.first;
            j = top.second;
            if (bb[i][j])
                continue;
            bb[i][j] = true;
            if (i - 1 > 0 && b[i - 1][j] == 'O')
                q.push(make_pair(i - 1, j));
            if (i + 1 < b.size() && b[i + 1][j] == 'O')
                q.push(make_pair(i + 1, j));
            if (j - 1 > 0 && b[i][j - 1] == 'O')
                q.push(make_pair(i, j - 1));
            if (j + 1 < b[i].size() && b[i][j + 1] == 'O')
                q.push(make_pair(i, j + 1));
        }
    }

    void solve(vector<vector<char>>& board) {
        if (!board.size())
            return;
        vector<vector<char>> bb(board.size(), vector<char>(board[0].size(), 0));
        for (int i = 0; i < board.size(); ++i){
            if (board[i][0] == 'O')
                bad(bb, board, i, 0);
            if (board[i].back() == 'O')
                bad(bb, board, i, board[i].size() - 1);
        }
        for (int i = 0; i < board[0].size(); ++i){
            if (board[0][i] == 'O')
                bad(bb, board, 0, i);
            if (board.back()[0] == 'O')
                bad(bb, board, board.size() - 1, i);
        }
        for (int i = 1; i < board.size() - 1; ++i) {
            for (int j = 1; j < board[i].size() - 1; ++j) {
                if (board[i][j] == 'O' && !bb[i][j]) {
                    if (check(board, i, j))
                        color(board, i, j);
                    else
                        bad(bb, board, i, j);
                }
            }
        }
    }
};

int main () {
    ifstream fin("input.txt");
    
    char c;
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> v[i][j];
        }
    }
    Solution s;
    s.solve(v);
    return 0;
}