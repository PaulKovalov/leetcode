#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <set>
using namespace std;

// fastest possible dijkstra

// class Solution {
// public:
//     typedef vector<vector<pair<int, int>>> graph;
//     int k;
    
//     void dfs(int v, graph& g, int* d, char* used) {
//         used[v] = true;
//         for (int i = 0; i < g[v].size(); ++i) {
//             int to = g[v][i].first;
//             int cost = g[v][i].second;
//             if (d[to] >= d[v] + cost && d[v] + cost <= k) {
//                 d[to] = d[v] + cost;
//                 if (!used[to])
//                     dfs(to, g, d, used);
//             }
//         }
//     }
    
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {    
//         graph g(n, vector<pair<int, int>>(1));
//         this->k = distanceThreshold;
//         for (int i = 0; i < edges.size(); ++i) {
//             int from = edges[i][0];
//             int to = edges[i][1];
//             int cost = edges[i][2];
//             g[from].push_back(make_pair(to, cost));
//             g[to].push_back(make_pair(from, cost));
//         }
//         int ans = 1e9, v = 0;
//         for (int i = 0; i < n; ++i) {
//             int d[n];
//             char used[n];
//             memset(d, 63, sizeof(d));
//             for (int i = 0; i < n; ++i) {
//                 cout << d[i] << " ";    
//             }
//             cout << endl;
//             memset(used, 0, sizeof(used));
//             d[i] = 0;
//             dfs(i, g, d, used);
//             int count = 0;
//             for (int j = 0; j < n; ++j) {
//                 if (d[j] <= k)
//                     ++count;
//             }
//             if (count <= ans) {
//                 v = i;
//                 ans = count;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    typedef vector<vector<pair<int, int>>> graph;
    int k;
    int dijkstra(int v, graph& g) {
        int n = g.size();
        vector<int> d(n, 1e9);
        d[v] = 0;
        auto comp = [&d](int a, int b) {
            return d[a] < d[b];
        };
        set<int, decltype(comp)> s(comp);
        s.insert(v);
        while (!s.empty()) {
            int v = *s.begin();
            s.erase(s.begin());
            for (int i = 0; i < g[v].size(); ++i) {
                int to = g[v][i].first;
                int cost = g[v][i].second;
                if (d[to] > d[v] + cost) {
                    if (s.find(to) == s.end())
                        s.erase(to);
                    d[to] = d[v] + cost;
                    s.insert(to);
                }
            }
        }
        int count = -1;
        for (int i = 0; i < n; ++i)
            if (d[i] <= k)
                ++count;
        cout << v << " " << count << endl;
        return count;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {    
        graph g(n, vector<pair<int, int>>());
        this->k = distanceThreshold;
        for (int i = 0; i < edges.size(); ++i) {
            int from = edges[i][0];
            int to = edges[i][1];
            int cost = edges[i][2];
            g[from].push_back(make_pair(to, cost));
            g[to].push_back(make_pair(from, cost));
        }
        int mm = 1e9, v = 0;
        for (int i = 0; i < n; ++i) {
            int count = dijkstra(i, g);
            if (count <= mm) {
                v = i;
                mm = count;
            }
        }
        return v;
    }
};
int main() {
    int n, k;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    cin >> k;
    Solution solution;
    int ans = solution.findTheCity(n, v, k);
    
    cout << ans << endl;
    return 0;
};

/// using faster Dijkstra 
// class Solution {
// public:
//     typedef vector<vector<pair<int, int>>> graph;
//     int k;
//     int dijkstra(int v, graph& g) {
//         int n = g.size();
//         int d[n];
//         memset(d, 63, sizeof(d));
//         d[v] = 0;
//         set<pair<int, int>> s;
//         s.insert(make_pair(d[v], v));
//         while (!s.empty()) {
//             int v = s.begin()->second;
//             s.erase(s.begin());
//             for (int i = 0; i < g[v].size(); ++i) {
//                 int to = g[v][i].first;
//                 int cost = g[v][i].second;
//                 if (d[to] > d[v] + cost) {
//                     s.erase(make_pair(d[to], to));
//                     d[to] = d[v] + cost;
//                     s.insert(make_pair(d[to], to));
//                 }
//             }
//         }
//         int count = -1;
//         for (int i = 0; i < n; ++i)
//             if (d[i] <= k)
//                 ++count;
//         return count;
//     }
    
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {    
//         graph g(n, vector<pair<int, int>>());
//         this->k = distanceThreshold;
//         for (int i = 0; i < edges.size(); ++i) {
//             int from = edges[i][0];
//             int to = edges[i][1];
//             int cost = edges[i][2];
//             g[from].push_back(make_pair(to, cost));
//             g[to].push_back(make_pair(from, cost));
//         }
//         int mm = 1e9, v = 0;
//         for (int i = 0; i < n; ++i) {
//             int count = dijkstra(i, g);
//             if (count <= mm) {
//                 v = i;
//                 mm = count;
//             }
//         }
//         return v;
//     }
// };
