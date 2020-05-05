class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> d(nums.size(), 0);
        d[0] = nums[0];
        int maxx = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            d[i] = nums[i] +  (d[i - 1] < 0 ? 0 : d[i - 1]);
            maxx = max(d[i], maxx);
        }
        return maxx;
    }
};