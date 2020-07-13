#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), 1e9));
        vector<pair<int, int>> zeros;
        vector<pair<int, int>> ones;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    zeros.push_back(make_pair(i, j));
                    ans[i][j] = 0;
                }
                if (matrix[i][j] == 1) {
                    ones.push_back(make_pair(i, j));
                }
            }
        }
        for (int i = 0; i < ones.size(); ++i) {
            for (int j = 0; j < zeros.size(); ++j) {
                int d = abs(zeros[j].first - ones[i].first) + abs(zeros[j].second - ones[i].first);
                ans[ones[i].first][ones[i].second] = min(ans[ones[i].first][ones[i].second], d);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    ifstream fin("input.txt");
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> v[i][j];
        }
    }
    solution.updateMatrix(v);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}