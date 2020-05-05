class Solution {
public:
    typedef vector<int> vi;
    typedef vector<vector<int>> vvi;
    static bool cmp(const vi& a, const vi& b) {
        if (a[0] < b[0]) {
            return true;
        }
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return false;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vvi ans;
        auto it = upper_bound(intervals.begin(), intervals.end(), newInterval, cmp);
        int d = distance(intervals.begin(), it);
        int i = d, j = d - 1;
        vi new_interval = newInterval;
        for (i; i < intervals.size(); ++i) {
            if(new_interval[1] >= intervals[i][0]) {
                new_interval[1] =  max(intervals[i][1], new_interval[1]);
                new_interval[0] =  min(intervals[i][0], new_interval[0]);
            } else {
                break;
            }
        }
        for (j; j >= 0; --j) {
            if(new_interval[0] <= intervals[j][1]) {
                new_interval[0] =  min(intervals[j][0], new_interval[0]);
                new_interval[1] =  max(intervals[j][1], new_interval[1]);
            } else {
                break;
            }
        }
        for (int k = 0; k <= j; ++k) {
            ans.push_back(intervals[k]);
        }
        ans.push_back(new_interval);
        for (int k = i; k < intervals.size(); ++k) {
            ans.push_back(intervals[k]);
        }
        return ans;
    }
};