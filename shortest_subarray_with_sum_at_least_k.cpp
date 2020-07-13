#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    // int shortestSubarray(vector<int>& A, int K) {
    //     int l = 0, r = 0, sum = 0, ans = 1e9;
    //     while (r < A.size() && sum < K) {
    //         sum += A[r];
    //         if (sum < 0) {
    //             l = r + 1;
    //             sum = 0;
    //         }
    //         ++r;
    //     }
    //     if (sum >= K)
    //         ans = r - l;
    //     if (ans == 0)
    //         return 1;
    //     while (l < r) {
    //         sum -= A[l];
    //         ++l;
    //         while (l < r && A[l] <= 0) {
    //             sum -= A[l];
    //             ++l;
    //         }
    //         while (r < A.size() && sum < K) {
    //             sum += A[r];
    //             if (sum < 0) {
    //                 l = r + 1;
    //                 sum = 0;
    //             }
    //             ++r;
    //         }
    //         if (sum >= K)
    //             ans = min(ans, r - l);
    //     }
    //     if (ans == 1e9)
    //         return -1;
    //     return max(ans, 1);
    // }
    int shortestSubarray(vector<int>& A, int K) {
        int l = -1, r = 0, sum = 0, ans = 1e9;
        vector<int> negPref(A.size() + 1, 0);
        for (int i = 0; i < A.size(); ++i) {
            negPref[i + 1] = negPref[i] + min(A[i], 0);
        }
        for (int i = 0; i < A.size(); ++i) {        
            A[i] = max(A[i], 0);
        }
        auto negsum = [negPref](int l, int r) {return negPref[r + 1] - negPref[l];};
        while (l < r) {
            if (l >= 0)
                sum -= A[l];
            ++l;
            while (r < A.size() && sum + negsum(l, r) < K) {
                sum += A[r];
                ++r;
            }
            if (sum + negsum(l, r - 1) >= K) {
                cout << l << " " << r - 1 << endl;
                ans = min(ans, r - l - 1);
            }
        }
        if (ans == 1e9)
            return -1;
        return max(ans, 1);
    }
};


int main() {
    Solution solution;
    int k, n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cin >> k;
    cout << solution.shortestSubarray(v, k) << endl;
    return 0;
}