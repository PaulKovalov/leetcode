class Solution {
public:
    typedef vector<vector<int>> vvi;
    typedef vector<int> vi;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vvi new_intervals;
        sort(intervals.begin(), intervals.end(), [](const vi& a, const vi& b) {
             if (a[0] < b[0]) {
            return true;
        } else if (a[0] > b[0]) {
            return false;
        } else {
            return a[1] < b[1];
        }
        });
        if (intervals.size() == 0) {
            return new_intervals;
        }
        new_intervals.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            int curr_start = new_intervals.back()[0];
            int curr_end = new_intervals.back()[1];
            int next_start = intervals[i][0];
            int next_end = intervals[i][1];
            if (curr_end >= next_start) {
                new_intervals.back()[0] = min(curr_start, next_start);
                new_intervals.back()[1] = max(curr_end, next_end);
            } else {
                new_intervals.push_back(intervals[i]);
            }
        }
        return new_intervals;
    }
};