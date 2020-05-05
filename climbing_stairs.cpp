class Solution {
public:
    int climbStairs(int n) {
        vector<int> d(n + 2, 0);
        d[0] = 0;
        d[1] = 1;
        for (int i = 2; i < n + 2; ++i) {
            d[i] = d[i - 1] + d[i - 2];
        }
        return d[n + 1];
    }
};