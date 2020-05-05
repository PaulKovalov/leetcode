#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    unordered_map<int, int> m;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (m.find(complement) != m.end()) {
                res.push_back(m[complement]);
                res.push_back(i);
                return res;
            }
            m[nums[i]] = i; 
        }
        return res;
    }
};