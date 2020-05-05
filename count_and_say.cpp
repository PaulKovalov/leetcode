class Solution {
public:
    string rec_countsay(int n, string s) {
        if (n == 0) {
            return s;
        }
        int curr_count = 0;
        char curr_n = s[0];
        string ans = "";
        for (int i = 0; i < s.length(); ++i) {
            ++curr_count;
            if (curr_n != s[i]) {
                ans += to_string(curr_count - 1);
                ans += curr_n;
                curr_count = 1;
                curr_n = s[i];
            }
        }
        
            ans += to_string(curr_count);
            ans += curr_n;
        
        return rec_countsay(n - 1, ans);
        
        
    }
    string countAndSay(int n) {
        if (n == 0) {
            return "";
        } else {
            string s = "1";
            return rec_countsay(n - 1, s);
        }
        
    }
};