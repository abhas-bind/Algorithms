#include <bits/stdc++.h>
using namespace std;

int search(string pattern, string text) {
    int n = text.length();
    int m = pattern.length();

    int i, j;

    for (i = 0, j = 0; i < n && j < m; i++) {
        if (pattern[j] == text[i]) j++;
        else {
            i -= j;
            j = 0;
        }
    }
    if (j == m) return i - m;
    return n;
}

int main () {
    return 0;
}