class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        vector<int> d(nums.size(), 0);
        int m = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            d[i] = i > 1 ? max(d[i - 1], nums[i] + d[i - 2]) : max(m, nums[i]);
            if (d[i] > m)
                m = d[i];
        }
        return m;
    }
};