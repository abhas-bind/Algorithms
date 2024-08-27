#include <bits/stdc++.h>
using namespace std;

int search(string pattern, string text) {
    int textSize = text.length();
    int patternSize = pattern.length();

    int patternPointer, textPointer;

    for (textPointer = 0, patternPointer = 0; textPointer < n && patternPointer < m; textPointer++) {
        if (pattern[patternPointer] == text[textPointer]) j++;
        else {
            textPointer -= patternPointer;
            patternPointer = 0;
        }
    }
    if (patternPointer == patternSize) return textPointer - patternSize;
    return textSize;
}

int main () {
    return 0;
}