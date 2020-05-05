class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
                    vector<int> v1, v2;
        for (int i = 0; i < s1.size(); ++i) {
        v1.push_back(s1[i]);
        v2.push_back(s2[i]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    bool c1 = true, c2 = true;
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] < v2[i])
            c1 = false;
    }
    for (int i = 0; i < v1.size(); ++i) {
        if (v2[i] < v1[i])
            c2 = false;
    }
    return c2 || c1;}
};