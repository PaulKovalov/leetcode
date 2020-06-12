#include <vector>
#include <algorithm>
using namespace std;

class Solution {
   public:
    vector<int> colors;
    vector<int> ans;
    vector<bool> used;

    bool check_cycle(vector<vector<int>> &v, int curr) {
        colors[curr] = 1;
        for (int i = 0; i < v[curr].size(); ++i) {
            int to = v[curr][i];
            if (colors[to] == 0) {
                if (check_cycle(v, v[curr][i])) return true;
            } else if (colors[to] == 1) {
                return true;
            }
        }
        colors[curr] = 2;
        return false;
    }

    void dfs(vector<vector<int>> &graph, int v) {
        used[v] = true;
        for (int i = 0; i < graph[v].size(); ++i) {
            int to = graph[v][i];
            if (!used[to])
                dfs(graph, to);
        }
        ans.push_back(v);
    }

    void topological_sort(vector<vector<int>> &graph, int v) {
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        if (prerequisites.size() == 0) {
            for (int i = 0; i < numCourses; ++i) {
                ans.push_back(i);
            }
            return ans;
        }
        colors.assign(numCourses, 0);
        used.assign(numCourses, false);
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            if (prerequisites[i].size() == 2) {
                graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (check_cycle(graph, i) == true) {
                return {};
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!used[i]) {
                dfs(graph, i);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};