class Solution {
public:
    bool isPalindrome(int x) {
        long long xx = x;
        if (x != abs(xx)) {
            return false;
        }
        vector<int> v;
        while (x) {
            v.push_back(x%10);
            x /= 10;
        }
        
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != v[v.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};