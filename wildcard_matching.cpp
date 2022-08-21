#include <iostream>

class Solution {
public:

    bool isMatch(string s, string p) {
        if (p == s)
            return true;
        if (p.size() == 0)
            return false;
        string np = "";
        for (int i = 0; i < p.size(); ++i) {
            if (i > 0 && p[i] == '*' && p[i - 1] == '*')
                continue;
            np += p[i];
        }
        vector<vector<int> > dp(s.size() + 1, vector<int>(np.size() + 1, 0));
        dp[s.size()][np.size()] = 1;
        dp[s.size()][np.size() - 1] = np.back() == '*';
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = np.size() - 1; j >= 0; --j) {
                if (s[i] == np[j] || np[j] == '?')
                    dp[i][j] = dp[i + 1][j + 1];
                else if (np[j] == '*')
                    dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
                
            }
        }
        return dp[0][0];
    }
};
