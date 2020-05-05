class Solution {
public:
    int binSearch(vector<int> &v, int l, int r, int target) {
        if (l <= r) {
            int m = (r - l)/2 + l; 
            if (v[m] == target) {
                return m;
            } else if (v[m] > target) {
                return binSearch(v, l, m - 1, target);
            } else {
                return binSearch(v, m + 1, r, target);
            }
        } 
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }
        int idx = binSearch(nums, 0, nums.size() - 1, target);
        if (idx == -1) {
            return {-1, -1};
        } else {
            int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            return {l, r - 1};
        }
    }
};