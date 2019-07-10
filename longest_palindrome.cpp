#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string lcs(string s1, string s2) {
    int l1 = s1.length();
    int l2 = s2.length();
  
    vector<vector<int> > v(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                v[i][j] = v[i-1][j-1] + 1;
            } else {
                v[i][j] = max(v[i-1][j], v[i][j - 1]);
            }
        }
    }
    for (int i = 0; i <= l1; ++i) {
        for (int j = 0; j <= l2; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    // restore lcs
    int i = l1, j = l2;
    string result = "";
    while(i && j) {
        int m = max(v[i-1][j-1], max(v[i-1][j], v[i][j-1]));
        if (v[i-1][j-1] == m && v[i-1][j-1] != v[i][j]) {
            --i;
            --j;
            result += s1[i];
        } else if(v[i - 1][j] == m) {
            --i;
        } else {
            --j;
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2) << endl;
    
    // int start = 0, left, right, max_l = 1, curr_l = 1, l, left_index = 0, i;
    // l = s.length();
    // for (i = 0; i < l; ++i) {
    //     start = i;
    //     left = i, right = i;
    //     while (right + 1 < l) {
    //         if (s[left] == s[right + 1]) {
    //             ++right;
    //         } else {
    //             break;
    //         }
    //     }
    //     while (left - 1 >= 0 && right + 1 < l) {
            
    //         if (s[left - 1] == s[right + 1]) {
    //             --left;
    //             ++right;
    //         } else {
    //             break;
    //         }
    //     }
    //     if (right - left + 1> max_l) {
    //         max_l = right - left + 1;
    //         left_index = left;
    //     }
        
    // }
    // string res = "";
    // for (i = left_index; i < left_index + max_l; ++i) {
    //     res += s[i];
    // }
    // cout << res << endl;
    return 0;
}