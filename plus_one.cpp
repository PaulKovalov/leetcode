class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() == 0) {
            digits.push_back(1);
            return digits;
        }
        int i = digits.size() - 1, carry = 0;
        digits[i] += 1;
        while (digits[i] > 9) {
            carry = digits[i] / 10;
            digits[i] %= 10;
            --i;
            if (i < 0) {
                digits.insert(digits.begin(), 0);
                i = 0;
            }
            digits[i] += carry;
        }
        return digits;
    }
};