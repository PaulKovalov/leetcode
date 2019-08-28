#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

void twoSum(vector<int> &nums, int n, int l, vector<vector<int> > &answer)
{
    unordered_map<int, int> values;
    for (int i = l; i < nums.size(); ++i)
    {
        int complimentary = n - nums[i];
        if (values.find(complimentary) != values.end())
        {
            vector<int> tmp;
            tmp.push_back(complimentary);
            tmp.push_back(nums[i]);
            tmp.push_back(-n);
            answer.push_back(tmp);
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        } else {
            values[nums[i]] = complimentary;
        }
    }
}
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int> > ans;
    // sort(nums.begin(), nums.end());
    if (nums.size() > 0) {
        if (nums[0] > 0) {
            return ans;
        }
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            twoSum(nums, -nums[i], i + 1, ans);
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    vector<vector<int> > v = threeSum(d);
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}