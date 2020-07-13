#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double, int>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int from = edges[i][0];
            int to = edges[i][1];
            double cost = succProb[i];
            graph[from].push_back(move(make_pair(cost, to)));
            graph[to].push_back(move(make_pair(cost, from)));
        }
        vector<double> d(n, 0);
        using pid = pair<double, int>;
        auto compare =  [](pid &a, pid &b){return a.first < b.first;};
        priority_queue<pid, vector<pid>, decltype(compare)> q(compare);
        q.push({start, 1});
        for (int i = 0; i < n; ++i) {            
            // choose the vertex from not marked
            int v = q.top().second;
            double cost = q.top().first;
            q.pop();
            if (d[v] != cost)
                continue;
            
            for (int j = 0; j < graph[v].size(); ++j) {
                int to = graph[v][j].first;
                double prob = graph[v][j].second;
                if (d[to] < d[v] * prob) {
                    d[to] = d[v] * prob;
                    q.push({d[to], to});
                }
            }
        }
        return d[end];
    }
};
int main() {

    return 0;
}