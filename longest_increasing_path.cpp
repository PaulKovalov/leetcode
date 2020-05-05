class Solution {
public:
    vector<vector<int> > d;
    int dfs(vector<vector<int> > &m, int i, int j) {
        if (d[i][j] == 0) {
            if (i > 0 && m[i - 1][j] > m[i][j]) {
                d[i][j] = max(d[i][j], dfs(m, i - 1, j));
            }
            if (i + 1 < m.size() && m[i + 1][j] > m[i][j]) {
                d[i][j] = max(d[i][j], dfs(m, i + 1, j));
            }
            if (j + 1 < m[i].size() && m[i][j + 1] > m[i][j]) {
                d[i][j] = max(d[i][j], dfs(m, i, j + 1));
            }
            if (j > 0 && m[i][j - 1] > m[i][j]) {
                d[i][j] = max(d[i][j], dfs(m, i, j - 1));
            }
        }    
        return d[i][j] + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }

        d.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
        int m = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                m = max(m, dfs(matrix, i,j));
            }
        }
        return m;
    }
};