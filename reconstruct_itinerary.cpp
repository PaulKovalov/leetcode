#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

/**
The task here is to find an euler path
**/
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, int> m;
        int idx = 0, start = -1;
        for (int i = 0; i < tickets.size(); ++i) {
            string from = tickets[i][0];
            string to = tickets[i][1];
            if (m.find(from) == m.end()) {
                m[from] = idx++;
            }
            if (m.find(to) == m.end()) {
                m[to] = idx++;
            }
        }
        vector<vector<int>> g(idx, vector<int>(idx, 0));
        vector<string> ans;
        vector<pair<string, int>> sv(idx);
        vector<string> rev_map(idx);
        for (auto it = m.begin(); it != m.end(); ++it) {
            string v = it->first;
            int i = it->second;
            // I can pushback here, but that will be more expensive
            // as i is unique for each string, i can use as an index
            // anyway this array will be sorted later
            sv[i] = make_pair(v, i);
            rev_map[i] = v; // reversed mapping
            if (v == "JFK")
                start = i;
        }
        sort(sv.begin(), sv.end(), [](const pair<string, int>& a, const pair<string, int> &b){
            return a.first < b.first;
        });

        for (int i = 0; i < tickets.size(); ++i) {
            int from = m[tickets[i][0]];
            int to = m[tickets[i][1]];
            g[from][to]++;
        }
        
        if (start != -1) {
            stack<int> s;
            s.push(start);
            while (!s.empty()) {
                int v = s.top();
                int to = -1;
                for (int i = 0; i < sv.size(); ++i) {
                    if (g[v][sv[i].second]) {
                        to = sv[i].second;
                        break;
                    }
                }
                if (to == -1) {
                    ans.push_back(rev_map[v]);
                    s.pop();
                } else {
                    g[v][to]--;
                    s.push(to);
                }
            }
        } else {
            return {"JFK"};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<string>> v(n, vector<string>(2));
    for (int i = 0; i < n; ++i) {
        cin >> v[i][0] >> v[i][1];
    }
    Solution solution;
    vector<string> ans = solution.findItinerary(v);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
};
