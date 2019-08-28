class Solution {
public:
    vector<string> answer;
    void backtrack(int n, string s = "", int left = 0, int right = 0) {
        if (s.length() == 2*n) {
            answer.push_back(s);
            return;
        }
        if (left < n) {
            backtrack(n, s + "(", left + 1, right);
        }
        if (right < left) {
            backtrack(n, s + ")", left, right + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack(n);
        return answer;
    }
};