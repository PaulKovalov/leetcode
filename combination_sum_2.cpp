class Solution {
public:
    void dfs(vector<int> &c, int v, int target, vector<int> path, vector<vector<int>> &ans) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = v; i < c.size(); ++i) {
            if (i > v && c[i] == c[i - 1]) continue;
            path.push_back(c[i]);                
            dfs(c, i + 1, target - c[i] , path, ans);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > answer;
        dfs(candidates, 0, target, {}, answer);
        return answer;
    }
};