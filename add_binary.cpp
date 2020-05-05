class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() > b.length())
            swap(a, b);
        int bitb = 0, bita = 0, carry = 0, result = 0;
        for (int i = 0; i < b.size(); ++i) {
            bitb = b[b.size() - i - 1] - '0';
            if (i < a.size()) {
                bita = a[a.size() - i - 1] - '0';
            } else {
                bita = 0;
            }
            result = carry + bita + bitb;
            carry = result / 2;
            b[b.size() - i - 1] = (result % 2) + '0';
        }
        if (carry) {
            b.insert(b.begin(), carry + '0');
        }
        return b;
    }
};