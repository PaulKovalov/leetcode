#include <iostream>
#include <climits>
#include <vector>
using namespace std;
double median(vector<int> &v, vector<int>& v2) {
    if (v.size() > v2.size()) {
        return median(v2, v);
    }
    int x = v.size(), y = v2.size();
    int low = 0, high = x;
    while (low <= high) {
        int partitionX = (high + low)/2;
        int partitionY = (x + y + 1)/2 - partitionX;
        int maxLeftX = partitionX == 0 ? INT_MIN : v[partitionX - 1];
        int minRightX = partitionX == x ? INT_MAX : v[partitionX];
        int maxLeftY = partitionY == 0 ? INT_MIN : v2[partitionY - 1];
        int minRightY = partitionY == y ? INT_MAX : v2[partitionY];
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((x + y) % 2 == 0) {
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/ 2.0;
            } else {
                return max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;   
        }
        
    }
}
int main() {
    int x, y;
    cin >> x;
    vector<int> v(x);
    for (int i = 0; i < x; ++i) {
        cin >> v[i];
    }
    cin >> y;
    vector<int> v2(y);
    for (int i = 0; i < y; ++i) {
        cin >> v2[i];
    }
    cout << median(v, v2) << endl;
    return 0;
}