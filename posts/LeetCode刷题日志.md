# LeetCode刷题日志

**Date 2025-12-30 Trie 前缀树（字典树）**
``` cpp
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    TrieNode() {
        children.clear();
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); ++i) {
            if (cur->children.count(word[i]) == 0)
                cur->children[word[i]] = new TrieNode();
            cur = cur->children[word[i]];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); ++i) {
            if (cur->children.count(word[i]) == 0)
                return false;
            cur = cur->children[word[i]];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.length(); ++i) {
            if (cur->children.count(prefix[i]) == 0)
                return false;
            cur = cur->children[prefix[i]];
        }
        return true;
    }
};
```