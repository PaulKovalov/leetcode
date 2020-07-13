#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    typedef unsigned long long ll;
    const int P = 31;
    string longestDupSubstring(string S) {
        vector<ll> h(S.size() + 1);
        vector<ll> p(S.size() + 1);
        p[0] = 1;
        h[0] = 0;
        int len = S.size();
        for(int i = 0; i < len; ++i) {
            h[i + 1] = h[i] * P + S[i];
            p[i + 1] = p[i] * P;
        }
        int K = len/2, step = K/2;
        while (K < S.size() && step) {
            bool ans = check_K_exists(h, p, K);
            if (ans) {
                K += step;
            } else {
                K -= step;
            }
            step /= 2;
        }
        string ans = "";
        while (K > 0 && !check_K_exists(h, p, K--)) {}
        while (K < S.size() && check_K_exists(h, p, K))
            ans = get_substr_K(h, p, K++, S);
        return ans;
    }

    bool check_K_exists(vector<ll> &h, vector<ll> &p,  int k) {
        auto get_hash = [&](int l, int r) {
            return h[r + 1] - h[l] * p[r - l + 1];
        };
        unordered_set<ll> s;
        for (int i = 0; i < h.size() - k; ++i) {
            ll substr = get_hash(i, i + k - 1);
            if (s.find(substr) == s.end())
                s.insert(substr);
            else
                return true;
        }
        return false;
    }
    string get_substr_K(vector<ll> &h, vector<ll> &p,  int k, string S) {
        auto get_hash = [&](int l, int r) {
            return h[r + 1] - h[l] * p[r - l + 1];
        };
        unordered_set<ll> s;
        for (int i = 0; i < h.size() - k; ++i) {
            ll substr = get_hash(i, i + k - 1);
            if (s.find(substr) == s.end())
                s.insert(substr);
            else
                return S.substr(i, k);
        }
        return "";
    }
};

int main() {
    string s;
    cin >> s;
    Solution solution;
    cout << solution.longestDupSubstring(s) << endl;
    return 0;
}