#include <iostream>
#include <stack>
#include <string>
using namespace std;

//9012번 문제 (Parenthesis matching)

void ParenthesisMatching() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		stack <bool> st;
		string str;
		cin >> str;
		while (!str.empty()) {
			if (*str.begin() == '(') { // '(' 를 만나면 넣고
				st.push(true);
				str.erase(str.begin());
			}
			else { // ')'를 만나면 뺀다
				if (!st.empty()) { //처음부터 )가 들어올수도 있으니 그 경우 제외
					st.pop(); 
					str.erase(str.begin());
				}
				else { //비어져 있는 상태에서 )가 들어온건 parentheis matching이 안되므로 그냥 바로 탈출
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