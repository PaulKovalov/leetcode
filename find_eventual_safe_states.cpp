class Solution {
public:
    bool dfs(int* state, char* used, vector<vector<int>> &graph, int v) {
        used[v] = true;
        if (graph[v].size() == 0) {
            // terminal node
            return state[v] = true;
        }

        for (int i = 0; i < graph[v].size(); ++i) {
            int to = graph[v][i];
            if (used[to])
                if (state[to] == -1 || !state[to])
                    return state[v] = false;
            if (state[to] == -1)
                state[to] = dfs(state, used, graph, to);
            if (!state[to])
                return state[v] = false;
        }
        return state[v] = true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int state[graph.size()];
        char used[graph.size()];
        memset(state, -1, sizeof(state));
        memset(used, 0, sizeof(used));
        for (int i = 0; i < graph.size(); ++i) {
            if (state[i] == -1) {
                memset(used, 0, sizeof(used));
                dfs(state, used, graph, i);
            } 
        }
        for (int i = 0; i < graph.size(); ++i)
            if (state[i] == 1)
                ans.push_back(i);
        return ans;
    }
};