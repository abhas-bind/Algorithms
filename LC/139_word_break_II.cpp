#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> sentences;
        string currSentence = "";

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        backtrack(s, wordSet, 0, currentSentence, sentences);
        return sentences;
    }

    void backtrack(const string& s, unordered_set<string>& wordSet, int idx, string& currentSentence, vector<string>& sentences) {
        if (idx == s.length()) {
            sentences.push_back(currentSentence);
            return;
        }

        for (int len = 1; len <= s.length() - idx; len++) {
            string word = s.substr(idx, len);
            if (!wordSet.contains(word)) continue;

            if (!currentSentence.empty()) currentSentence.push_back(' ');
            currentSentence += word;
            backtrack(s, wordSet, idx + len, currentSentence, sentences);
            
            for (int i = 0; i <= len && !currentSentence.empty(); i++) currentSentence.pop_back();
        }
    }
};


class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
};



class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> sentences;
        string currSentence = "";

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        backtrack(s, wordSet, 0, currentSentence, sentences);
        return sentences;
    }

    void backtrack(const string& s, unordered_set<string>& wordSet, int idx, string& currentSentence, vector<string>& sentences) {
        if (idx == s.length()) {
            sentences.push_back(currentSentence);
            return;
        }

        for (int len = 1; len <= s.length() - idx; len++) {
            string word = s.substr(idx, len);
            if (!wordSet.contains(word)) continue;

            if (!currentSentence.empty()) currentSentence.push_back(' ');
            currentSentence += word;
            backtrack(s, wordSet, idx + len, currentSentence, sentences);
            
            for (int i = 0; i <= len && !currentSentence.empty(); i++) currentSentence.pop_back();
        }
    }
};



int main() {
    return 0;
}