#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    class DSU {
        public:
        vector<int> parent;
        DSU (int n) {
            parent.resize(n);
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }
        int find_parent(int x) {
            if (parent[x] == x)
                return x;
            parent[x] = find_parent(parent[x]);
            return parent[x];
        }
        void union_sets(int x, int y) {
            x = find_parent(x);
            y = find_parent(y);
            if (x != y)
                parent[y] = x;
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, unordered_set<int>> vs;
        DSU dsu(accounts.size());
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                vs[accounts[i][j]].insert(i);
            }
        }
        for (auto it = vs.begin(); it != vs.end(); ++it) {
            int p = *it->second.begin();
            for (auto itt = it->second.begin(); itt != it->second.end(); ++itt) {
                dsu.union_sets(p, *itt);
            }
        }
        for (int i = 0; i < dsu.parent.size(); ++i) {
            dsu.parent[i] = dsu.find_parent(i);
        }
        vector<vector<string>> ans;
        unordered_map<int, unordered_set<string>> m;
        for (int i = 0; i < accounts.size(); ++i) {
            m[dsu.parent[i]].insert(accounts[i].begin() + 1, accounts[i].end());
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            ans.push_back({});
            ans.back().push_back(accounts[it->first][0]); // insert name
            std::copy(it->second.begin(), it->second.end(), std::back_inserter(ans.back()));
            sort(ans.back().begin() + 1, ans.back().end());
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<string>> vs({{"John", "johnsmith@mail.com","john_newyork@mail.com"}, {"John","johnsmith@mail.com","john00@mail.com"}, {"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}});
    vs = s.accountsMerge(vs);
    for (int i = 0; i < vs.size(); ++i) {
        for (int j = 0; j < vs[i].size(); ++j) {
            cout << vs[i][j] << " ";
        }
        cout<< endl;
    }
    return 0;
}