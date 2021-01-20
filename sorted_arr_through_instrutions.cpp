#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
typedef unsigned long long ull;

class Solution {
    
   public:
    vector<int> t;

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        } else {
            int tm = (tl + tr) / 2;
            int left_sum = query(2 * v, tl, tm, l, min(tm, r));
            int right_sum = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
            return left_sum + right_sum;
        }
    }

    void update(int v, int tl, int tr, int x) {
        if (tl == tr) {
            t[v]++;
        } else {
            int tm = (tl + tr) / 2;
            if (x <= tm)
                update(2 * v, tl, tm, x);
            else
                update(2 * v + 1, tm + 1, tr, x);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    int createSortedArray(vector<int>& instructions) {
        int n = 100001, instructions_total = 0, mod = static_cast<int>(1e9 + 7);
        int tsize = 4 * n;
        t.resize(tsize, 0);
        int maxn = n - 1;
        for (int i = 0; i < instructions.size(); ++i) {
            // cout << "querying " << instructions[i] << endl;
            int less = query(1, 0, maxn, 0, instructions[i] - 1);
            int greater = query(1, 0, maxn, instructions[i] + 1, maxn);
            // cout << "{" << less << ", " << greater << "}" << endl; 
            instructions_total = (instructions_total + min(less, greater)) % mod;
            update(1,0, maxn, instructions[i]);
        }
        return instructions_total;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    Solution s;
    cout << s.createSortedArray(v) << endl; 
    return 0;
}
