#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    int N, n;
    cin >> N;
    cin >> n;
    vector<vector<int>> trust(n, vector<int>(2));
    for (int i = 0; i < n; ++i)
    {
        cin >> trust[i][0] >> trust[i][1];
    }
    unordered_map<int, set<int>> m;
    set<int> all_trustee;
    for (int i = 0; i < trust.size(); ++i) {
        m[trust[i][1]].insert(trust[i][0]);
        all_trustee.insert(trust[i][0]);
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second.size() == N - 1) {
            if (all_trustee.find(it->first) == all_trustee.end()) {
                cout << it->first << endl;
                return 0;
            }
            
        }
    }
    cout << -1 << endl;
    return 0;
}