class Solution {
public:
    vector<int> b;
    
    void build_sqrt_decompose(vector<int>& nums) {
        double n = static_cast<double>(nums.size());
        int blocks_cnt = static_cast<int>(ceil(sqrt(n)));
        b.resize(blocks_cnt, numeric_limits<int>::max());
        for (int i = 0; i < nums.size(); ++i) {
            int cur_block = i / blocks_cnt;
            b[cur_block] = min(b[cur_block], nums[i]);
        }
    }
    
    int query(vector<int>& nums, int l, int r) {
        int len = b.size();
        int left_block = l / len;
        int right_block = r / len;
        int query_result = numeric_limits<int>::max();
        
        if (left_block == right_block) {
            for (int i = l; i <= r; i++) {
                query_result = min(query_result, nums[i]);
            }
        } else {
            for (int i = l, end = (left_block + 1) * len; i < end; ++i) {
                query_result = min(query_result, nums[i]);
            }
            for (int i = left_block + 1; i < right_block; ++i) {
                query_result = min(query_result, b[i]);
            }
            for (int i = right_block * len; i <= r; ++i) {
                query_result = min(query_result, nums[i]);
            }
        }
        return query_result;
    }
    
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> mcs;
        build_sqrt_decompose(nums);
        int start = 0, to = nums.size() - k;
        while (mcs.size() != k) {
            int rmq = query(nums, start, to);
            for (int i = start; i <= to; ++i) {
                if (nums[i] == rmq) {
                    start = i + 1;
                    break;
                }
            }
            mcs.push_back(rmq);
            ++to;
        }
        return mcs;
    }
};
