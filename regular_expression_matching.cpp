class Solution {
public:

    bool isMatch(string s, string p) {
        vector<vector<int> > d(s.size() + 1, vector<int>(p.size() + 1, 0));
        d[s.size()][p.size()] = 1;
        for (int i = s.size(); i >= 0; --i) {
            for (int j = p.size() - 1; j >= 0; --j) {
                bool first_match = false;
                if (i < s.size() && (p[j] == s[i] || p[j] == '.')) {
                    first_match = true;
                }
                if (j + 1 < p.size() && p[j + 1] == '*') {
                    d[i][j] = d[i][j + 2] || (first_match && d[i + 1][j]);
                } else {
                    d[i][j] = first_match && d[i + 1][j + 1];
                }
            }
        }
        return d[0][0];
    }
};