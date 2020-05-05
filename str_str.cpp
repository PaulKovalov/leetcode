class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == haystack || needle == "") {
            return 0;
        }
        string s = needle + "#" + haystack;
        int n = s.length();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r)
                z[i] = min (r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        for (int i = needle.length(); i < n; ++i) {
            if (z[i] == needle.length()) {
                return i - needle.length() - 1;
            }
        }
        return -1;
    }
};