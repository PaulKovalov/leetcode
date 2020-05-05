class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, string> t;
        for (int i = 0; i < strs.size(); ++i) {
            string tmp = strs[i]; 
            sort(tmp.begin(), tmp.end());
            t[i] = tmp;
        }
        unordered_map<string, vector<int> > v;
        for (auto it = t.begin(); it != t.end(); ++it) {
            v[it->second].push_back(it->first);
        }
        vector<vector<string> > ans;
        for (auto it = v.begin(); it != v.end(); ++it) {
            vector<string> tmp_v;
            for (int i = 0; i < it->second.size(); ++i) {
                tmp_v.push_back(strs[it->second[i]]);               
            }
            ans.push_back(tmp_v);
        }
        return ans;
    }
};