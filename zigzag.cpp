#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int l, n, two_n;
    string s;
    cin >> s;
    cin >> n;
    if (n == 1) {
        cout << s << endl;
        return 0;
    }
    l = s.length();
    vector<int> v;
    two_n = 2*n;
    for (int i = 0; i < n; ++i) {
        v.push_back(i);
        for (int j = 1; j <= l/n; ++j) {
            int x = j*(two_n - 2);
            if (x - i < l) {
                if (v[v.size() - 1] != x - i)
                    v.push_back(x - i);
            }
            if (x + i < l) {
                if (v[v.size() - 1] != x + i)
                    v.push_back(x + i);
            }
        }
    }
    string res = "";
    for (int i = 0; i < l; ++i) {
        res += s[v[i]];
    }
    cout << endl << res << endl;
    return 0;
}