#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    class TrieNode {
      public:
        unordered_map<char, TrieNode*> c;
        TrieNode() {};
    };
    TrieNode* head;
    Trie() {
        head = new TrieNode();
    }
    void _insert(TrieNode*& node, const string &word, int k) {
        if (k >= word.size()) {
            node->c['-'] = NULL; // signals that word ends here
            return;
        }
        if (node->c.find(word[k]) == node->c.end())
            node->c[word[k]] = new TrieNode();
        _insert(node->c[word[k]], word, k + 1);
    }
    bool _search(TrieNode*& node, const string& word, int k) {
        if (k >= word.size()) {
            return true;
        }
        if (node->c.find(word[k]) == node->c.end()) {
            return false;
        }
        return _search(node->c[word[k]], word, k + 1);
    }
    bool _starts_with(TrieNode*& node, const string& word, int k) {
        if (k >= word.size()) {
            return true;
        }
        if (node->c.find(word[k]) == node->c.end()) {
            return false;
        }
        return _starts_with(node->c[word[k]], word, k + 1);
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        int k = 0;
        _insert(head, word, k);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int k = 0;
        return _search(head, word + "-", k);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int k = 0;
        return _starts_with(head, prefix, k);
    }
};
static auto fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    string word = "word", prefix = "wo";
    Trie* obj = new Trie();
    obj->insert(word);
    bool param_2 = obj->search(word);
    bool param_3 = obj->startsWith(prefix);
    cout << param_2 << " " << param_3 << endl;
}