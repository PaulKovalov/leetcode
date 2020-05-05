// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int m = (r - l) / 2 + l;
            if (isBadVersion(m)) {
                if (!isBadVersion(m - 1))
                    return m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};