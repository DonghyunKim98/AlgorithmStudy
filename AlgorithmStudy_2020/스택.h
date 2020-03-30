#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 10828�� ����

void Stack() {
	int N;
	cin >> N;
	stack <int> st;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			//�� �κ�!! push�� ��ɾ� �϶��� temp�� �޴´ٴ°�!
			int temp;
			cin >> temp;
			st.push(temp);
		}
		else if (str == "top") {
			//empty ��ü�� bool�� return������ ������.
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
		else { //pop�� ��ɾ� �϶�
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