#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 10828번 문제

void Stack() {
	int N;
	cin >> N;
	stack <int> st;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			//이 부분!! push가 명령어 일때만 temp를 받는다는것!
			int temp;
			cin >> temp;
			st.push(temp);
		}
		else if (str == "top") {
			//empty 자체는 bool을 return값으로 가진다.
			if (!st.empty()) cout << st.top() << endl;
			else cout << "-1" << endl;
		}
		else if (str == "size") {
			cout<<st.size()<<endl;
		}
		else if (str == "empty") {
			if (st.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else { //pop이 명령어 일때
			if (!st.empty()) {
				cout << st.top() << endl;
				st.pop();
			}
			else {
				cout << "-1" << endl;
			}
		}
	}
	return ;
}