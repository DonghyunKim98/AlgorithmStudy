#include <bits/stdc++.h>
//9576�� ����
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
		//�̹� ó���� ���� �� �ʿ䰡 ����
		if (finish[t]) continue;
		finish[t] = true;
		//����ְų�-> ó���� ������ ������ �� ��Ŵ 
		//��忡 �� �� ������ �ִ� ��� -> ó���� �߰� ���ᵵ ������, ����� ��带 �ٸ� ���� �ٲܼ� �ִٸ�
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
	�˰��� -> �̺и�Ī (Bipartire Matching)
*/