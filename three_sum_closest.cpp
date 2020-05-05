class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = 0;
        if (nums.size() > 0) {
            closest = nums[0] + nums[1] + nums[2];
            sort(nums.begin(), nums.end());
            int s = nums.size();
            for (int i = 0; i < s; ++i) {
                int j = i + 1;
                int k = s - 1;
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                while (j < k) {
                    int tmp_sum = nums[j] + nums[k] + nums[i];
                    if (abs(target - tmp_sum) < abs(target - closest)) {
                        closest = tmp_sum;
                    }
                    if (tmp_sum < target) {
                        ++j;
                    } else if (tmp_sum > target) {
                        --k;
                    } else {
                        return tmp_sum;
                    }
                }
            }
        }
        return closest;
    }
};