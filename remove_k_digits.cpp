#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <stack>
#include <set>

using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()) return "0";
        vector<char> stack;
        int i = 0;
        while(i < num.size()){
            while(k && stack.size() && stack.back() > num[i]){
                k--;
                stack.pop_back();
            }
            stack.push_back(num[i++]);
        }
        while(k-- > 0){
            stack.pop_back();
        }
        string res = "";
        while(!stack.empty()){
            res = stack.back() + res;
            stack.pop_back();
        }
        int z = 0;
        while (z < res.size() && res[z] == '0')
            ++z;
        res = res.substr(z);
        if (res.size() == 0)
            res = "0";
        return res;
    }
};

int main() {
    Solution solution;
    string s;
    int k;
    cin >> s >> k;
    cout << solution.removeKdigits(s, k) << endl;
    return 0;
}
static auto fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();