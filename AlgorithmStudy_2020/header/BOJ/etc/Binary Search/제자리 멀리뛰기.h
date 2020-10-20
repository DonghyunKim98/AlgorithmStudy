#include<bits/stdc++.h>
//6029번 문제
using namespace std;
int D, N, M;
vector<int> vc;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> D >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vc.push_back(temp);
	}
	vc.push_back(0), vc.push_back(D);
	sort(vc.begin(), vc.end());
	int start = 0, end=*(vc.end()-1);
	int ans = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = 0, prev = vc[0];
		for (int i = 1; i < (int)vc.size(); i++) {
			int gap = vc[i] - prev;
			//최소거리인 mid보다 더 뛴다면 제거하지 않음
			if (gap >= mid) {
				prev = vc[i];
			}
			//덜 뛴다면 제거함. prev 유지
			else cnt++;
		}
		//더 지웠음 -> 최소 간격이 너무 큼 -> end를 줄여서 mid값을 줄여함
		if (cnt > M) {
			end = mid - 1;
		}
		//덜 지웠음 -> 최소 간격이 너무 작음 -> start를 늘려서 mid값을 늘려야함
		else {
			start = mid + 1;
			ans = mid;
		}

	}
	cout << ans;
}