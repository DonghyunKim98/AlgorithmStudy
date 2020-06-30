#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size(); i++) {
        string s1 = phone_book[i];
        for (int j = i+1; j < phone_book.size(); j++) {
            string s2 = phone_book[j];
            if (s1 == s2.substr(0, s1.size())) return false;
        }
    }
    return true;
}