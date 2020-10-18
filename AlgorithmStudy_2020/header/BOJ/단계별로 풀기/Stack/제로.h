#include <iostream>
#include <stack>

using namespace std;
//10773¹ø ¹®Á¦
void Zero() {
	int N;
	cin >> N;
	stack <int> st;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp == 0) st.pop();
		else st.push(temp);
	}
	int sum = 0;
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum;

	return ;
}