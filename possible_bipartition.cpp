#include <algorithm>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
typedef vector<vector<int> > graph;
class Solution {
public:
    
    vector<char> color;
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if (dislikes.size() == 0)
            return N > 0;
        bool check = false;
        color.resize(N, 0);
        // convert this input shit to normal adjacency list
        graph g(N,vector<int>());
        bool ans = true;
        for (int i = 0; i < dislikes.size(); ++i) {
            g[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
            g[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
        }
        for (int i = 0; i < g.size(); ++i) {
            if (!color[i]) {
                ans &= dfs_b(g, i, 1);
            }
        }
        return ans;
    }
    
    bool dfs_b(graph& g, int v, char c) {
        color[v] = c;
        for (int i = 0; i < g[v].size(); ++i) {
            if (color[g[v][i]] == 0) {
                dfs_b(g, g[v][i], invert(c));
            } else if (color[g[v][i]] == c) {
                return false;
            }
        }
        return true;
    }

    char invert(char c) {
        return c == 1 ? 2 : 1;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    graph g(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        cin >> g[i][0] >> g[i][1];
    }
    Solution solution;
    cout << solution.possibleBipartition(n, g) << endl;
    return 0;
}