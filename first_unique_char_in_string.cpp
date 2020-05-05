class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        int first_index = 0;
        for (int i = 0; i < s.size(); ++i) {
            m[s[i]]++;
            if (m[s[i]] > 1 && s[first_index] == s[i]) {
                int k = first_index;
                while (k <= i && m[s[k]] > 1)
                    ++k;
                first_index = k;
            }
        }
        return m[s[first_index]] == 1 ? first_index: -1;
    }
};