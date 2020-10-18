#include <bits/stdc++.h>
//16471번 문제
using namespace std;
int N;
vector<int> vc1, vc2;
void solution(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vc1.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vc2.push_back(temp);
	}

	sort(vc1.rbegin(), vc1.rend());
	sort(vc2.rbegin(), vc2.rend());
	int ans = 0, idx1 = 0, idx2 = 0;
	while (idx1 < N && idx2 < N) {
		//고객이 이길 수 있는 숫자가 나왔을때
		if (vc1[idx1] < vc2[idx2]) {
			ans++, idx1++, idx2++;
		}
		else idx1++;
	}
	if (ans < (N + 1) / 2) cout << "NO";
	else cout << "YES";
}

/*
	절반 이상은 이겨야 한다.
	vc2에 있는 숫자들이 vc1에 있는 숫자들을 이길수 있는지를 확인.

	->사장님과 고객 모두 내림차순이후 idx=0 부터 비교해서
	  고객의 가장 큰 숫자로 이길 수 있는 가장 큰 숫자를 이겨야함
*/