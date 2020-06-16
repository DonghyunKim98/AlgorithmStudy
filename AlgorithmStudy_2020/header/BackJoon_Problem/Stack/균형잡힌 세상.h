#include <bits/stdc++.h>
//4949�� ����
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
	stack�� ����Ҷ� �׻�
	=> s.top() �� �̿��Ҷ� s.empty()�� �˻�
	=> �� �������� Ʋ�� �������� ������ stack�� element�� �����ִ��� �˻�
*/