class Solution {
public:
    int mySqrt(int x) {
        int max_approx_root = 0;
        double min_diff = 1e9;
        unsigned long long powRes = 1;
        for (unsigned long long i = 1; powRes = i*i, powRes <= x; ++i) {
            unsigned long long curr_diff = 1;
            if (powRes < x) {
                curr_diff = x - powRes;   
            }  else {
                curr_diff = powRes - x;
            }
            if (curr_diff < min_diff) {
                min_diff = curr_diff;
                max_approx_root = i;
            }
        }
        return max_approx_root;
    }
};