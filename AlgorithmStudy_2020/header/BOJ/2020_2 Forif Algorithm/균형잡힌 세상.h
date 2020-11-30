#include <bits/stdc++.h>
// 4949¹ø ¹®Á¦
using namespace std; 

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (true) {
		string temp;
		getline(cin, temp);
		if (temp == ".") break;
		stack<char> s;
		bool isMatch = true;
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == '(' || temp[i] == '[') s.push(temp[i]);
			else if (temp[i] == ')') {
				if (s.empty() || s.top() != '(') {
					isMatch = false;
					break;
				}
				else s.pop();
			}
			else if (temp[i] == ']') {
				if (s.empty() || s.top() != '[') {
					isMatch = false;
					break;
				}
				else s.pop();
			}
		}
		if (isMatch && s.empty()) cout << "yes\n";
		else cout << "no\n";
	}
}