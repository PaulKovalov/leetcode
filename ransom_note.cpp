class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int r = 0, m = 0;
        while(r < ransomNote.size() && m < magazine.size()) {
            if (ransomNote[r] == magazine[m]) {
                ++r;
                ++m;
            } else {
                ++m;
            }
        }
        if (r >= ransomNote.size())
            return true;
        return false;
    }
};