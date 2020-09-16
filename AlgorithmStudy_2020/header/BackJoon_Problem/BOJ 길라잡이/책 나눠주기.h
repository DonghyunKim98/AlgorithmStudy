#include <bits/stdc++.h>
//9576번 문제
using namespace std;
typedef pair<int, int> pii;
int N, M;
vector<pii> vc(1010);
int work[1010];
bool finish[1010];

bool DFS(int idx) {
	int size = vc[idx].second - vc[idx].first + 1;
	for (int i = 0; i < size; i++) {
		int t = vc[idx].first + i;
		//이미 처리한 노드는 볼 필요가 없음
		if (finish[t]) continue;
		finish[t] = true;
		//비어있거나-> 처리는 했지만 연결은 안 시킴 
		//노드에 더 들어갈 공간이 있는 경우 -> 처리도 했고 연결도 했지만, 연결된 노드를 다른 노드로 바꿀수 있다면
		if (work[t] == 0 || DFS(work[t])) {
			work[t] =idx;
			return true;
		}
	}
	return false;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int ans = 0;
		cin >> N >> M;
		fill(work, work + 1010, 0);	vc.clear();
		vc.push_back({ 0, 0 });
		for (int i = 1; i <= M; i++) {
			int s, e;
			cin >> s >> e;
			vc.push_back({ s,e });
		}
		for (int i = 1; i <= M; i++) {
			fill(finish, finish + 1010, false);
			if (DFS(i)) {
				ans++;
			}
		}
		cout << ans << endl;
		
	}
	
}

/*
	알고리즘 -> 이분매칭 (Bipartire Matching)
*/