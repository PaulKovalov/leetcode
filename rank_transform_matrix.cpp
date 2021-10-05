#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:

    void normalize(vector<vector<int>>& matrix) {
        int m = numeric_limits<int>::max();
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                m = min(m, matrix[i][j]);
            }
        }
        if (m > 0)
            return;
        m = -m + 1;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                matrix[i][j] += m;
            }
        }
    }
    void dfs(set<pair<int, int>>& s, vector<vector<bool>>& used, vector<vector<int>>& matrix, int val, int r, int c, int vi, int vj) {
        used[r][c] = true;
        s.insert({r, c});
        if (matrix[r][c] == val) {
            if (r + 1 < matrix.size() && !used[r + 1][c])
                dfs(s, used, matrix, val, r + 1, c, 1, 0);
            if (r - 1 >= 0 && !used[r - 1][c]) {    
                dfs(s, used, matrix, val, r - 1, c, -1, 0);
            }
            if (c + 1 < matrix[0].size() && !used[r][c + 1]) {
                dfs(s, used, matrix, val, r, c + 1, 0, 1);
            }
            if (c - 1 >= 0 && !used[r][c - 1]) {
                dfs(s, used, matrix, val, r, c - 1, 0, -1);
            }
        } else {
            if (r + vi < matrix.size() && c + vj < matrix[0].size()) {
                dfs(s, used, matrix, val, r + vi, c + vj, vi, vj);
            }
        }
    }
    void adj(set<pair<int, int>> &s, vector<vector<int>>& matrix, int r, int c) {
        for (int i = 0; i < matrix.size(); ++i) {
            s.insert({i, c});
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            s.insert({r, i});
        }
    }

    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        normalize(matrix);
        vector<pair<int, int>> v;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                v.push_back({i, j});
            }
        }
        sort(v.begin(), v.end(), [&matrix](const pair<int, int>&a, const pair<int, int>&b){
            return matrix[a.first][a.second] < matrix[b.first][b.second];
        });
        
        for (auto const& p : v) {
            int new_val = 1;
            int cur_val = matrix[p.first][p.second];
            set<pair<int, int>> s; // component of point p
            vector<vector<bool>> used(matrix.size(), vector<bool>(matrix[0].size(), false));
            // dfs(s, used, matrix, cur_val, p.first, p.second, 0, 0);
            adj(s, matrix, p.first, p.second);
            set<int> vals;
            for (auto pp: s) {
                // cout << pp.first << ", " << pp.second << endl;
                vals.insert(matrix[pp.first][pp.second]);
            }
            // cout << "---" << endl;
            for (auto it = vals.begin(); it != vals.end(); ++it) {
                if (*next(it) == cur_val) {
                    new_val = (*it) + 1;
                    break;
                }
            }
            // cout << "new val " << new_val << endl;
            if (new_val >= cur_val) {
                continue;
            }
            for (auto pp: s) {
                if (matrix[pp.first][pp.second] == cur_val) {
                    matrix[pp.first][pp.second] = new_val;
                }
            }
            // for (int i = 0; i < matrix.size(); ++i) {
            //     for (int j = 0; j < matrix[i].size(); ++j) {
            //         cout << matrix[i][j] <<" ";
            //     }
            //     cout << endl;
            // }
            // cout << "-----" << endl;
        }
        return matrix;
    }
};
