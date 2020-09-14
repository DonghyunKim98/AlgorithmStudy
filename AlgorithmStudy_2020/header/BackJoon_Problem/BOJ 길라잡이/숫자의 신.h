#include <bits/stdc++.h>
//1422번 문제
using namespace std;
int K, N;
vector<string> vc;

bool cmp(string a, string b) {
	if (a == b) return a < b;
	if (a + b == b + a) return a.length() > b.length();
	else return a + b > b + a;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> K >> N;
	int max_num = 0;
	for (int i = 0; i < K; i++) {
		string temp;
		cin >> temp;
		vc.push_back(temp);
		max_num = max(max_num, stoi(temp));
	}
	sort(vc.begin(), vc.end(), cmp);
	string answer;
	bool is_max_used = false;
	for (int i = 0; i < K; i++) {
		if (stoi(vc[i]) == max_num&& !is_max_used) {
			for (int j = 0; j < N - K + 1; j++) {
				answer += vc[i];
			}
			is_max_used = true;
			continue;
		}
		answer += vc[i];
	}
	cout << answer;
}


/*
	<1단계 생각>
		1. 일단 왼쪽부터 차근차근 비교해가면서, 숫자가 큰 것이 앞에 가도록 한다
		2. 만약 완벽히 자리수가 같다면, 다시 처음으로 돌아가서 비교한다.
		ex) 7747 vs 774785 같은 경우 4자리 비교후, 7747의 다시 0번째 idx를 비교해서
			7과 8을 비교한다.
		3. 만약 완벽히 같은 숫자라면 그냥 아무거나 먼저 와도 상관없다. -> 제일먼저 분기점
		=> 문제점: 자리수가 더 커지면, 그걸 더 많이 쓰는게 이득이다.
		   ex) 47 9 가 있고 3번 쓰라 하면
			   9947 보다 94747이 이득임.
	<2단계 생각>
		1. <1단계 생각>에서 분류한대로 와야 하는 것은 맞음
		   다만 어떤 숫자가 가장 많이 반복되야 하는가?
				=> 자리수가 가장 큰 수중에 가장 먼저오는 수!
				=> 이를 입력단계에서 관리해야할 것 같다.

	<3단계 생각>
		1. 부분적으로 반복되는 수가 cmp에서 infinite loop를 돈다
			ex) 123 과 123123


	<4단계 생각>
		1.결국 다시 돌고 돌아서 정렬이 제대로 이루어지지 않고 계속 예외가 발생해서
		  a+b와 b+a중 더 큰값으로 정렬하면 된다. =>핵심!
		2.만약 2개가 같다면, 더 자릿수가 큰 값이 앞으로 가면 된다.
*/
