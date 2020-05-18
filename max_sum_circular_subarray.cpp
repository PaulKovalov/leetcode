#include <vector>
#include <iostream>

using namespace std;

class Solution {
    typedef long long ll;
public:
    int maxSubarraySumCircular(vector<int>& A) {
        ll sum = 0, minans = 0, maxans = 0, maxarr = -1e9, arrsum = 0, asize = A.size();
        for (int i = 0; i < asize; ++i) {
            if (A[i] > maxarr)
                maxarr = A[i];
            arrsum += A[i];
        }
        for (int i = 0; i < asize; ++i) {
            sum += A[i];
            maxans = max(maxans, sum);
            sum = max((ll)0, sum);
        }
        sum = 0;
        for (int i = 0; i < asize; ++i) {
            sum += A[i];
            minans = min(minans, sum);
            sum = min((ll)0, sum);                
        }
        if (maxarr <= 0) {
            return maxarr;
        }
        return max(maxarr, max(arrsum - minans, maxans));
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    Solution solution;
    cout << solution.maxSubarraySumCircular(v) << endl;
    return 0;
}