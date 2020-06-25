#include <bits/stdc++.h>
//2110번 문제
using namespace std;

void RouterInstall() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, C;
	cin >> N >> C;
	vector<long long> vc(N);
	for (int i = 0; i < N; i++)
		cin >> vc.at(i);
	sort(vc.begin(), vc.end());

	//가능한 최소거리 -> 1
	//가능한 최대거리 -> 마지막과 첫집사이의 거리
	int begin = 1, end = vc.at(vc.size() - 1) - vc.at(0);
	while (begin <= end) {
		//gap 설정 -> 집과 집 사이의 거리가 이 gap보다 멀면 설치! 안 멀면 설치 x
		int gap = (begin + end) / 2;
		//일단 vc[0]에 무조건 설치하고 가기 때문에 cnt는 1을 설정해야함.
		int cnt = 1;
		//cnt가 갱신됐다는 것은 공유기를 설치했다는 것. 그러면 그 집으로 부터 새롭게 간격을 측정해야 하므로
		//std 변수를 측정해준다.
		int std = vc.at(0);
		
		for (int i = 1; i < N; i++) {
			if (vc.at(i) - std >= gap) {
				cnt++;
				std = vc.at(i);
			}
		}

		if (cnt >= C) begin = gap + 1;
		else end = gap - 1;
	}
	cout << end;
}

/*
	Brutal force => 조합. O(n!)

	알고리즘 아이디어
	=> 결국 집과 집사이의 '간격' 에 초점을 맞춰야 하는 것.
	=> 이 간격을 parameter search로 찾아가면서 문제의 조건에 부합하는지를 확인.
	(적어도 이 간격을 유지하면서 원하는 공유기의 개수만큼 설치할 수 있는가?)

	내가 한 실수
	1) 일단 집과 집사이의 간격을 일일이 알아낼려고 함. 그러니깐 집이
	[1,2,4,8,9] 가 있을때 집과 집사이의 간격인 [1,2,4,1] 를 알아내고 이거를 이용하려 했다는 점이 문제를 어렵게 만듦
	내가 간격 자체를 설정하고 설정한 간격보다 넓으면 count를 늘리고 좁으면 count를 늘리지 않는 방식.
	내가 왜 처음에 집과 집사이의 간격을 알아내서 변수로 삼으려 했는가?
	=> 공유기의 개수를 처음부터 이용할려고 했기 때문 즉 C대 설치 해야 하는 것을 처음부터 신경썻기 때문이다.
	2) cnt를 처음에 1로 설정하는 것. 맨 처음집은 무조건 설치할 것이기 때문!
*/