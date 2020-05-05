class Solution {
public:
    int findComplement(int num) {
        if (num == 0)
            return 1;
        long long base = 1, res = 0;
        while (num) {
            res += base * !(num % 2);
            num /= 2;
            base *= 2;
        }
        return res;
    }
};