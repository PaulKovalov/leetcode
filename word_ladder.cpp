#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    
    int count_difference(string word1, string word2) {
        int count = 0;
        for (int i = 0; i < word1.length(); ++i) {
            if (word1[i] != word2[i])
                ++count;
        }
        return count;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int start = wordList.size(), end = -1;
        wordList.push_back(beginWord);
        vector<vector<int> > words(wordList.size());
        for (int i = 0; i < wordList.size(); ++i) {
            if (endWord == wordList[i]) {
                end = i;
            }
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (count_difference(wordList[i],wordList[j])  == 1) {
                    words[i].push_back(j);
                    words[i].push_back(i);
                }
            }
        }
        if (end == -1) {
            return 0;
        }
        queue<int> q;
        vector<int> d(wordList.size(), 0);
        vector<bool> used(wordList.size(), false);
        used[start] = true;
        q.push(start);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < words[v].size(); ++i) {
                int curr_v = words[v][i];
                if (curr_v == end) {
                    return d[v] + 2;
                }
                if (!used[curr_v]) {
                    d[curr_v] = d[v] + 1;
                    used[curr_v] = true;
                    q.push(curr_v);
                }
            }
        }
        return 0;
    }
};
int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    string w1, w2;
    cin >> w1 >>  w2;
    Solution solution;
    cout << solution.ladderLength(w1,w2,v) << endl;
    return 0;
}