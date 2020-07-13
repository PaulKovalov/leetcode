#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j)
                    continue;
                int r = nums[i] % nums[j];
            }
        }
    }
};


int main() {
    int a = 3, b = 17;
    cout << a % b << " " << b % a << endl;
    return 0;
};
