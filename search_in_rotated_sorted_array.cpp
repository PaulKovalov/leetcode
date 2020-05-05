class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (r - l) / 2 + l;

            // chcek if it's the element we are looking for
            if (nums[m] == target) {
                return m;
            }
            // at this point, at least one of the subhalves is fully sorted
            // now check which half is sorted and try to find value there
            
            if (nums[l] < nums[m]) {
                // left half is sorted    
                // check if the element is inside the sorted half
                if (target >= nums[l] && m > 0 && target <= nums[m - 1]) {
                    // it is - continue search in this region
                    r = m - 1;
                } else {
                    // target element is not in this half, so search it in another half
                    l = m + 1;
                }
            } else  {
                // right half is sorted
                // check if the element is inside the sorted half
                if (m < nums.size() - 1 && target >= nums[m + 1] && target <= nums[r]) {
                    // target is within the sorted region, continue search here
                    l = m + 1;
                } else {
                    // target is in the another half
                    r = m - 1;
                }
            }
            
            
        }
        return -1;
        
    }
};