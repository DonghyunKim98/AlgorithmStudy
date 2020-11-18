#include <bits/stdc++.h>
using namespace std;

bool isRight(string str) {
    stack<char> s;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') s.push(str[i]);
        else {
            if (s.empty()) return false;
            else s.pop();
        }
    }
    return true;
}

int makeRightStartIdx(string str) {
    int leftParenthesis = 0, rightParenthesis = 0;
    for (int i = 0; i < str.size(); i++) {
        str[i] == '(' ? leftParenthesis++ : rightParenthesis++;
        if (leftParenthesis == rightParenthesis) return i;
    }
}

string reverse(string str) {
    for (int i = 0; i < str.size(); i++) {
        str[i] == '(' ? str[i] = ')' : str[i] = '(';
    }
    return str;
}

string process(string str) {
    string ret="";
    if (str == "") return ret;
    if (!isRight(str)) {
        string leftStr, rightStr;
        int leftEndIdx = makeRightStartIdx(str);
		leftStr = str.substr(0, leftEndIdx + 1), rightStr = str.substr(leftEndIdx+1);
        if (isRight(leftStr)) {
            ret = leftStr + process(rightStr);
        }
        else {
            leftStr = reverse(leftStr.substr(1, leftStr.size() - 2));
            rightStr = '(' + process(rightStr) + ')';
            ret = rightStr + leftStr;
        }
    }
    else ret = str;
    return ret;
}

string solution(string p) {
    string answer = process(p);
    return answer;
}