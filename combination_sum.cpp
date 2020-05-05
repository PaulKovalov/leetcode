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
            path.push_back(c[i]);
            dfs(c, i, target - c[i], path, ans);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > answer;
        dfs(candidates, 0, target, {}, answer);
        return answer;
    }
};