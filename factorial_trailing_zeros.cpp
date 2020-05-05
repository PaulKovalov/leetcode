class Solution {
public:
    double binpow(double n, int power) {
        if (power == 0) {
            return 1;
        }
        if (power%2 == 1) {
            return n * binpow(n, power - 1);
        }
        else {
            double b = binpow(n, power/2);
            return b*b;
        }
    }
    int trailingZeroes(int n) {
        int sum = 0;
        for (int i = 1; i < 100; ++i) {
            int f =  floor((double)n/binpow(5,i));
            if (f > 0) {
                sum += f;
            } else {
                break;
            }
        }
        return sum;
    }
};