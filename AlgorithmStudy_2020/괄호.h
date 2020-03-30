#include <iostream>
#include <stack>
#include <string>
using namespace std;

//9012�� ���� (Parenthesis matching)

void ParenthesisMatching() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		stack <bool> st;
		string str;
		cin >> str;
		while (!str.empty()) {
			if (*str.begin() == '(') { // '(' �� ������ �ְ�
				st.push(true);
				str.erase(str.begin());
			}
			else { // ')'�� ������ ����
				if (!st.empty()) { //ó������ )�� ���ü��� ������ �� ��� ����
					st.pop(); 
					str.erase(str.begin());
				}
				else { //����� �ִ� ���¿��� )�� ���°� parentheis matching�� �ȵǹǷ� �׳� �ٷ� Ż��
					st.push(false);
					break;
				}
			}
		}
		if (st.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return ;
}