#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void setSquare(vector<vector<char>> &v, int p1, int p2, char c) {
        if (c == '\\') {
            v[p1][p2] = 1;
            v[p1][p2 + 1] = 0;
            v[p1 + 1][p2] = 0;
            v[p1 + 1][p2 + 1] = 1;
        } else if (c == '/') {
            v[p1][p2] = 0;
            v[p1][p2 + 1] = 1;
            v[p1 + 1][p2] = 1;
            v[p1 + 1][p2 + 1] = 0;
        } else {
            v[p1][p2] = 0;
            v[p1][p2 + 1] = 0;
            v[p1 + 1][p2] = 0;
            v[p1 + 1][p2 + 1] = 0;
        }
    }
    void bfs(vector<vector<char>> &g, vector<vector<int>> &used, int i, int j) {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            used[i][j] = true;
            if (i > 0 && g[i - 1][j] == 0 && !used[i - 1][j]) {
                q.push(make_pair(i - 1, j));
            }
            if (i + 1 < g.size() && g[i + 1][j] == 0 && !used[i + 1][j]) {
                q.push(make_pair(i + 1, j));
            }
            if (j > 0 && g[i][j - 1] == 0 && !used[i][j - 1]) {
                q.push(make_pair(i, j - 1));
            }
            if (j + 1 < g[i].size() && g[i][j + 1] == 0 && !used[i][j + 1]) {
                q.push(make_pair(i, j + 1));
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        vector<vector<char>> g(grid.size() * 2, vector<char>(grid.size() * 2));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                setSquare(g, i*2, j*2, grid[i][j]);
            }
        }
        // for (int i = 0; i < g.size(); ++i) {
        //     for (int j = 0; j < g[i].size(); ++j) {
        //         cout <<( g[i][j] == 1 )<< " ";
        //     }
        //     cout << endl;
        // }
        int compcount = 0;
        vector<vector<int>> used(g.size(), vector<int>(g[0].size(), false));
        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
                if (!used[i][j]) {
                    ++compcount;
                    bfs(g, used, i, j);
                }
                    
            }
        }
        return compcount;
    }
};

int main() {

    Solution solution;
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    cout << solution.regionsBySlashes(s) << endl;
    return 0;
}