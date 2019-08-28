class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int s = nums.size();
        set<vector<int> > ans;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < s; ++i) {
            for (int j = s - 1; j > 2; --j) {
                int left = i + 1, right = j - 1;
                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right] + nums[j];
                    if (sum < target) {
                        ++left;
                    } else if (sum > target) {
                        --right;
                    } else {
                        vector<int> tmp = {nums[i], nums[left], nums[right], nums[j]};
                        ans.insert(tmp);
                        while (left < right && nums[left] == nums[left + 1]) {++left;}
                        while (left < right && nums[right] == nums[right - 1]) {--right;}
                        ++left;
                        --right;
                    }
                    
                }
                
            }
        }
        vector<vector<int> > t;
        for (set<vector<int> >::iterator it = ans.begin(); it != ans.end(); ++it) {
            t.push_back(*it);
        }
        return t;
    }
};