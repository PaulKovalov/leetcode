#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i) {
            int element = arr[i];
            int complement = 0;
        }
    }
};

int main() {
    int n, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
    cin >> k;
}