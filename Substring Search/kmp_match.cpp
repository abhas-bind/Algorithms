#include <bits/stdc++.h>
using namespace std;

class KmpMatching {
private:
    string pattern;
    vector<int> pi;

    void constructDFA() {
        for (int i = 1, j; i < pattern.length(); i++) {
            j = pi[i - 1];
            while (j && pattern[i] != pattern[j]) j = pi[j - 1];
            if (pattern[i] == pattern[j]) j++;
            pi[i] = j;
        }
    }

public:
    KmpMatching(string pattern) : pattern(pattern), pi(pattern.size(), 0) {

    }

    size_t findIn(string& text) const {
        if (text.length() == 0) return 0;
        int patternIndex = 0;
        
        for (int i = 0; i < text.length(); i++) {
            while (j && pattern[j] != text[i]) {
                j = pi[j - 1];
            }
            if (pattern[j] == text[i]) j++;
            if (j == pattern.length()) return i - pattern.length() + 1;
        }

        return text.length();
    }


};


int main () {

    KmpMatching kmp = KmpMatching("ababc");
    kmp.findIn("abababac");

    return 0;
}