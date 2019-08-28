class Solution {
public:
    string intToSet(int n) {
        switch(n) {
            case 2:{
                return "abc";
            }
            case 3:{
                return "def";
            }
            case 4:{
                return "ghi";
            }
            case 5:{
                return "jkl";
            }
            case 6:{
                return "mno";
            }
            case 7:{
                return "pqrs";
            }
            case 8:{
                return "tuv";
            }
            case 9:{
                return "wxyz";
            }
        }
        return "";
    } 
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        for (int i = 0; i < digits.size(); ++i) {
            string s = intToSet(digits[i] - '0');
            if (ans.size() == 0) {
                for (int j = 0; j < s.size(); ++j) {
                    string t = "";
                    t += s[j];
                    ans.push_back(t);
                }
            } else {
                vector<string> new_ans;
                for (int j = 0; j < ans.size(); ++j) {
                    for (int k = 0; k < s.size(); ++k) {
                        new_ans.push_back(ans[j] + s[k]);
                    }
                }
                new_ans.swap(ans);
            }
        }
        return ans;
    }
};