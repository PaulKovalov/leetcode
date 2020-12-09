class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int arr[60] = {0};
        for (int i = 0; i < time.size(); ++i) {
            arr[time[i] % 60]++;
        }
        int ans = ((arr[0]) * (arr[0] - 1)) / 2; // those with remainder = 0 combinations from n of two
        for (int i = 1; i < 30; ++i) {
            ans += arr[i] * arr[60 - i];
        }
        ans += ((arr[30]) * (arr[30] - 1)) / 2;
        return ans;
    }
};
