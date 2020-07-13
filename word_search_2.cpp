class Solution {
public:
    struct TrieNode {
        TrieNode* nodes[26];
        string word;
    };
    vector<string> ans;
    void dfs(TrieNode *root, vector<vector<char>> board, int i, int j) {
        if (root->nodes[board[i][j] - 'a'] == NULL)
            return;
        root = root->nodes[board[i][j] - 'a'];
        if (root->word != "") {
            ans.push_back(root->word);
            root->word = "";
        }
        board[i][j] = '-';
        if (i > 0 && board[i - 1][j] != '-')
            dfs(root, board, i - 1, j);
        if (i + 1 < board.size() && board[i + 1][j] != '-')
            dfs(root, board, i + 1, j);
        if (j > 0 && board[i][j - 1] != '-')
            dfs(root, board, i, j - 1);
        if (j + 1 < board[i].size() && board[i][j + 1] != '-')
            dfs(root, board, i , j + 1);
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();
        ans.clear();
        for (int i = 0; i < words.size(); ++i) {
            TrieNode* p = root;
            for (int j = 0; j < words[i].size(); ++j) {
                int c = words[i][j] - 'a';
                if (p->nodes[c] == NULL)
                    p->nodes[c] = new TrieNode();
                p = p->nodes[c];
            }
            p->word = words[i];
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                dfs(root, board, i, j);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};