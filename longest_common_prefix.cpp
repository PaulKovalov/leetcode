class Solution {
public:
    string lcs(vector<string>& strs, int l, int r) {
        if (l == r) {
            return strs[l];
        } else {
            int mid = (l + r)/2;
            string lcp_left = lcs(strs, l, mid);
            string lcp_right = lcs(strs, mid + 1, r);
            return common_prefix(lcp_left, lcp_right); 
        }
    }
    string common_prefix(string s1, string s2) {
        int m = min(s1.length(), s2.length());
        string prefix = "";
        for (int i = 0; i < m; ++i) {
            if (s1[i] != s2[i]) {
                return prefix;
            } 
            prefix += s1[i];
        }
        return prefix;
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.size() > 0) {
            return lcs(strs, 0, strs.size() - 1);   
        } else {
            return "";
        }
    }
};