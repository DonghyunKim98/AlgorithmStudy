#include <bits/stdc++.h>
//17140번 문제
using namespace std;
const int MAX = 100 + 1;
int r, c, k;
int arr[MAX][MAX];
int r_cnt, c_cnt;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

void Row_sort(int idx) {
	vector<pair<int, int>> Sorting_vc(MAX);
	for (int i = 1; i < MAX; i++) Sorting_vc[i] = { i,0 };
	for (int i = 1; i <= c_cnt; i++) {
		//0인 경우는 pass
		if (!arr[idx][i]) continue;
		Sorting_vc[arr[idx][i]].second++, arr[idx][i] = 0;
	}
	sort(Sorting_vc.begin(), Sorting_vc.end(), cmp);
	int sort_idx = 0;
	for (int i = 1; i < MAX - 1 && sort_idx < MAX; sort_idx++) {
		if (!Sorting_vc[sort_idx].second || !Sorting_vc[sort_idx].first)
			continue;
		c_cnt = max(c_cnt, i + 1);
		arr[idx][i] = Sorting_vc[sort_idx].first;
		arr[idx][i + 1] = Sorting_vc[sort_idx].second;
		i += 2;
	}
}

void Col_sort(int idx) {
	vector<pair<int, int>> Sorting_vc(MAX);
	for (int i = 1; i < MAX; i++) Sorting_vc[i] = { i,0 };
	for (int i = 1; i <= c_cnt; i++) {
		//0인 경우는 pass
		if (!arr[i][idx]) continue;
		Sorting_vc[arr[i][idx]].second++; arr[i][idx] = 0;
	}
	sort(Sorting_vc.begin(), Sorting_vc.end(), cmp);
	int sort_idx = 0;
	for (int i = 1; i < MAX - 1 && sort_idx < MAX; sort_idx++) {
		if (!Sorting_vc[sort_idx].second || !Sorting_vc[sort_idx].first)
			continue;
		r_cnt = max(r_cnt, i + 1);
		arr[i][idx] = Sorting_vc[sort_idx].first;
		arr[i + 1][idx] = Sorting_vc[sort_idx].second;
		i += 2;
	}
}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	r_cnt = 3, c_cnt = 3;
	while (arr[r][c] != k && cnt <= 100) {
		if (r_cnt >= c_cnt)
			for (int i = 1; i <= r_cnt; i++)
				Row_sort(i);
		else
			for (int i = 1; i <= c_cnt; i++)
				Col_sort(i);
		cnt++;
	}
	if (cnt == 101) cout << -1;
	else cout << cnt;
}