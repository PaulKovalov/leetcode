class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        int left_insert_pos = 0, right_insert_pos = nums.size() - 1;
        while (right_insert_pos > 0 && nums[right_insert_pos] == 2) {
            --right_insert_pos;
        }
        while (left_insert_pos + 1 < nums.size() && nums[left_insert_pos] == 0) {
            ++left_insert_pos;
        }
        if (left_insert_pos >= right_insert_pos) {
            return;
        }
        for (int i = left_insert_pos; i <= right_insert_pos; i = max(i + 1, left_insert_pos)) {
            if (nums[i] == 2) {
                swap(nums[i], nums[right_insert_pos]);
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[left_insert_pos]);
            }
            while (left_insert_pos + 1 < nums.size() && nums[left_insert_pos] == 0) {
                ++left_insert_pos;
            }
            while (right_insert_pos > 0 && nums[right_insert_pos] == 2) {
                --right_insert_pos;
            }
        }
        if (left_insert_pos <= right_insert_pos) {
            swap(nums[left_insert_pos], nums[right_insert_pos]);
        }
    }
};