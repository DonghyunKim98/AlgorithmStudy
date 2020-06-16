#include <bits/stdc++.h>
//4949번 문제
using namespace std;

void Balanced() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector <string> vc;
	while (true) {
		string temp;
		getline(cin, temp);
		if (temp == ".") break;
		vc.push_back(temp);
	}

	for (int i = 0; i < vc.size(); i++) {
		stack <char> s;
		int j = 0;
		bool is_balanced = true;
		while (j<vc.at(i).length()) {
			if (vc.at(i)[j] == '[') 
				s.push('[');
			else if (vc.at(i)[j]==']') {
				if (!s.empty() && s.top() == '[') s.pop();
				else {
					is_balanced = false;
					break;
				}
			}
			else if (vc.at(i)[j] == '(') 
				s.push('(');
			else if (vc.at(i)[j] == ')') {
				if (!s.empty() && s.top() == '(') s.pop();
				else {
					is_balanced = false;
					break;
				}
			}
			j++;
		}
		if (is_balanced && s.empty()) cout << "yes\n";
		else cout << "no\n";
	}
}

/*
	stack을 사용할땐 항상
	=> s.top() 을 이용할때 s.empty()를 검사
	=> 맨 마지막에 틀린 조건으로 여전히 stack에 element가 남아있는지 검사
*/