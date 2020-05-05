#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int curFurthest = 0;
    for (int i = 0; i < nums.size(); ++i) {
        curFurthest = max(i + nums[i], curFurthest);
        if (curFurthest == i && i != nums.size() - 1) {
            return false;
        }
    }
    return true;
    return 0;
}