#include "questions.h"

class TrieNode {
public:
    TrieNode() : is_string(false) {

    }
    bool is_string;
    unordered_map<char, TrieNode*> leaves;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie(){
       root_ =  new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto* cur = root_;
        for (const auto& c : word) {
            if (!cur->leaves.count(c)) {
                cur->leaves[c] = new TrieNode();
            }
            cur = cur->leaves[c];
        }
        cur->is_string = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto* node = childSearch(word);
        if (node)
            return node->is_string;
        else
            return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return childSearch(prefix);
    }

    TrieNode* childSearch(const string& prefix) {
        auto* cur = root_;
        for (auto& c : prefix) {
            if (cur->leaves.count(c)) {
                cur = cur->leaves[c];
            }
            else {
                return nullptr;
            }
        }
        return cur;
    }

private:
    TrieNode* root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


int UseTrie()
{
    cout << "*************** 208. Implement Trie ***************" << endl;
    cout << endl;

	return 0;
}