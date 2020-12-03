class Solution {
    typedef unsigned long long ull;
public:
    ull MOD = 1e9 + 7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> freq(nums.size());
        unordered_map<int, int> starts;
        unordered_map<int, int> ends;
        for (auto &r: requests) {
            starts[r[0]]++;
            ends[r[1] + 1]++;
        }
        int t = 0;
        for (int i = 0; i < nums.size(); ++i) {
            t += starts[i];
            t -= ends[i];
            freq[i] = t;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        sort(nums.begin(), nums.end(), greater<int>());
        ull ans = 0;
        for (int i = 0; i < freq.size(); ++i) {
            if (freq[i] > 0 && nums[i] > 0) {
                ans += (static_cast<ull>(freq[i]) * static_cast<ull>(nums[i]));
                ans %= MOD;
            } else {
                break;
            }
        }
        return static_cast<int>(ans);
    }
};
