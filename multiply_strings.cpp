class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        vector<int> answer(num1.size() + num2.size(), 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num1.size(); ++i) {
            int a = (num1[i] - '0');
            int carry = 0;
            for (int j = 0; j < num2.size(); ++j) {
                int b = (num2[j] - '0');
                answer[i + j] += a*b + carry;
                carry = answer[i + j] / 10;
                answer[i + j] %= 10;
            }
            if (carry != 0) {
                answer[i + num2.size()] += carry;
            }
            carry = 0;
        }
        string ans = "";
        int i = answer.size() - 1;
        while (answer[i] == 0) {
            --i;
        }
        for (; i >= 0; --i) {
            ans += to_string(answer[i]);
        }
        return ans;
    }
};