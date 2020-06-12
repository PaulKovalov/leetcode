#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        int pp = 1;
        for (int i = 0; i <= num; ++i) {
            
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    Solution solution;
    vector<int> res = solution.countBits(n);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}