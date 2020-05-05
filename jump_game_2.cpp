class Solution {
public:
    int jump(vector<int>& nums) {
        int currEnd = 0, currFurthest = 0, jumps = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            currFurthest = max(i + nums[i], currFurthest);
            if (i == currEnd) {
                ++jumps;
                currEnd = currFurthest;
            }
        }
        return jumps;
    }
};