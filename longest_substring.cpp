class Solution {
public:
    string longestPalindrome(string s) {
       int start = 0, left, right, max_l = 1, curr_l = 1, l, left_index = 0, i;
    l = s.length();
    for (i = 0; i < l; ++i) {
        start = i;
        left = i, right = i;
        while (right + 1 < l) {
            if (s[left] == s[right + 1]) {
                ++right;
            } else {
                break;
            }
        }
        while (left - 1 >= 0 && right + 1 < l) {
            if (s[left - 1] == s[right + 1]) {
                --left;
                ++right;
            } else {
                break;
            }
        }
        if (right - left + 1> max_l) {
            max_l = right - left + 1;
            left_index = left;
        }
    }
    string res = "";
    for (i = left_index; i < left_index + max_l; ++i) {
        res += s[i];
    }
   return res;
    }

};