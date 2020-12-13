class Solution {
   public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        vector<int> dp(boxes.size() + 1, 0);  // dp[i] - min num of trips to deliver i boxes
        int weight = 0, trips = 2;            // one from storage and one back
        int left = 0;
        // sliding window
        for (int right = 0; right < boxes.size(); ++right) {
            if (right > 0 && boxes[right][0] != boxes[right - 1][0]) {
                ++trips;  // trips incremented if there is a different port
            }
            weight += boxes[right][1];
            // check if window needs to be shrinked from left
            while ((right - left) >= maxBoxes || weight > maxWeight || (left < right && dp[left] == dp[left + 1])) {
                if (boxes[left][0] != boxes[left + 1][0]) {
                    --trips;  // removing different port, so reduce number of trips
                }
                weight -= boxes[left][1];
                ++left;
            }
            dp[right + 1] = dp[left] + trips;
        }
        return dp.back();
    }
};
