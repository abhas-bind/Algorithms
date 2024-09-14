class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode () : isEnd(false), children(26, nullptr) {

    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (curr->children[ch - 'a'] == nullptr) curr->children[ch - 'a'] = new TrieNode();
            curr = curr->children[ch - 'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        return searchSuffix(word, 0, curr);
    }

private:
    bool searchSuffix(string& word, int idx, TrieNode* curr) {
        for (int i = idx; i < word.length(); i++) {
            if (word[i] == '.') {
                bool matched = false;
                for (int ch = 0; ch < 26; ch++) {
                    if (curr->children[ch] != nullptr) {
                        matched = matched | searchSuffix(word, i + 1, curr->children[ch]);
                        if (matched) return true;
                    } 
                }
                if (!matched) return false;
            }
            if (curr->children[word[i] - 'a'] == nullptr) return false;
            curr = curr->children[word[i] - 'a'];
        }
        return curr->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */