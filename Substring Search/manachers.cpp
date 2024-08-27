#include <bits/stdc++.h>
using namespace std;


string updateString(string s) {
    string updatedString = "#";
    for (char c : s) {
        updatedString.push_back(c);
        updatedString.push_back('#');
    }
    return updatedString;
}

vector<int> manacherOdd(string s) {
    s = updatedString(s);
    int n = s.length();

    vector<int> p(n);
    int l = 1, r = 1;

    for (int i = 1; i  < n ; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while (s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }

    return p;
}


int main () {
    return 0;
}