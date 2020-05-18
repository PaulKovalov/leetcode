#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:

    vector<int> findAnagrams(string s, string p) {
        int psize = p.size(), ssize = s.size();
        vector<int> chars(26, 0);
        vector<int> ans;
        bool is_anagram = false;
        for (int i = 0; i < ssize; ++i) {
            if (i < psize) {
                chars[s[i] - 'a']++;
                chars[p[i] - 'a']--;
            } else {
                if (s[i] == s[i - psize]) {
                    if (is_anagram) {
                        ans.push_back(i - psize);
                    }
                    continue;
                }
                is_anagram = true;
                for (int j = 0; j < chars.size(); ++j) {
                    if (chars[j] != 0) {
                        is_anagram = false;
                        break;
                    }
                }
                chars[s[i] - 'a']++;
                chars[s[i - psize] - 'a']--;
                if (is_anagram) {
                    ans.push_back(i - psize);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s, p;
    cin >> s >> p;
    vector<int> ans = solution.findAnagrams(s, p);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}