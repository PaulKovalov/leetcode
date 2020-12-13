class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        // for every window length
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        vector<int> a = nums;
        a.insert(a.begin(), 1);
        a.push_back(1);
        for (int window = 1; window <= n; ++window) {
            // for every possible start of the window
            for (int left = 1; left <= n - window + 1; ++left) {
                // for every possible element int the window
                int right = left + window - 1;
                for (int i = left; i <= right; ++i) {
                    dp[left][right] = max(
                        dp[left][right],
                        a[i] * a[left - 1] * a[right + 1] + dp[left][i - 1] + dp[i + 1][right]);
                }
            }
        }
        return dp[1][n];
    }
};
