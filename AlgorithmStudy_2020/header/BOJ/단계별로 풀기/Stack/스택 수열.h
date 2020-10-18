#include <bits/stdc++.h>
//1874�� ����
//�˰��� ���� =>https://blog.naver.com/PostView.nhn?blogId=occidere&logNo=220812563361
//�ڵ� ���� =>https://sihyungyou.github.io/baekjoon-1874/
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
	�˰��� ����
	=> NO�� ����ϴ� ������ ���� �����丵 �� �� �ִ�.
	=> ���� ������ �׳� stack�� ������ ���ؼ� pop�� �� ������ �ϰ� ���ϸ� �ְ� �ܼ��ϰ� �����Ѱ�.
*/