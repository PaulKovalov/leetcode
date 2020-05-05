class Solution {
public:
    typedef unsigned long long ull;
    int numTrees(int n) {
        vector<ull> d(n + 1);
        d[0] = 1;
        for (int i = 1; i <= n; ++i) {
            d[i] = d[i - 1] * (4*i - 2) / (i + 1);    
        }
        return d[n];        
    }
};