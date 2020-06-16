#include <bits/stdc++.h>
//1874번 문제
//알고리즘 참고 =>https://blog.naver.com/PostView.nhn?blogId=occidere&logNo=220812563361
//코드 참고 =>https://sihyungyou.github.io/baekjoon-1874/
using namespace std;

void StackSequence() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	stack <int> s;
	vector <int> vc(N);
	vector <char> ans;
	
	for (int i = 0; i < N; i++)
		cin >> vc.at(i);
	

	int j = 0;
	for (int i = 1; i <= N; i++) {
		s.push(i);
		ans.push_back('+');
		while (!s.empty() && s.top() == vc.at(j)) {
			s.pop();
			ans.push_back('-');
			j++;
		}
	}

	if (!s.empty()) cout << "NO";
	else for (int i = 0; i < ans.size(); i++) cout << ans.at(i) << '\n';

}

/*
	알고리즘 설명
	=> NO를 출력하는 과정을 좀더 리팩토링 할 수 있다.
	=> 지금 과정은 그냥 stack과 수열을 비교해서 pop할 수 있으면 하고 못하면 넣고를 단순하게 구현한것.
*/