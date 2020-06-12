#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
    typedef unsigned long long ull;
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<ull>> dp(matrix.size(), vector<ull>(matrix[0].size()));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int d = (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0);
                int l = j > 0 ? dp[i][j - 1]: 0;
                int r = i > 0 ? dp[i - 1][j]: 0;
                dp[i][j] = l + r + matrix[i][j] - d;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int k = 1;
                if (matrix[i][j])
                    ++ans;
                int base = i > 0 && j > 0 ? dp[i - 1][j - 1] : 0;
                while (k + i < rows && k + j < cols) {
                    int top = i > 0 ? dp[i - 1][j + k]: 0;
                    int left = j > 0 ? dp[i + k][j - 1]: 0;
                    if ((k + 1)*(k+ 1) == (dp[k+ i][k+j] + base - top - left))
                        ++ans;
                    ++k;
                }
            }
        }
        return ans;
    }
};
static auto fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution solution;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }
    cout << solution.countSquares(v);
    return 0;
}