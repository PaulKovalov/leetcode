class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }
            if (left == right) {
                ans = max(ans, right*2);
            }
            else if (right > left) {
                right = left = 0;
            }
        }
        right = left = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }
            if (left == right) {
                ans = max(ans, right*2);
            }
            else if (left > right) {
                right = left = 0;
            }
        }
        return ans;
    }
};