class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res(candies.size(), false);
        int g = candies[0];
        for (int i = 1; i < candies.size(); ++i) {
            if (g < candies[i]) {
                g = candies[i];
            }
        }
        for (int i = 0; i < candies.size(); ++i) {
            if (candies[i] + extraCandies >= g) {
                res[i] = true;
            }
        }
        return res;
        
    }
};