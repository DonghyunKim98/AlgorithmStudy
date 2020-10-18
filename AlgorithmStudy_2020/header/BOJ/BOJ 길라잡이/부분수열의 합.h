#include <bits/stdc++.h>
//1182번 문제
using namespace std;
int N, S;
vector<int> vc;
int ans = 0;
void DFS(int idx,int temp_sum) {
	if (idx == vc.size()) return;
	for (int i = idx; i < vc.size(); i++) {
		temp_sum += vc[i];
		if (temp_sum == S) ans++;
		DFS(i + 1,temp_sum);
		temp_sum -= vc[i];
	}
}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vc.push_back(temp);
	}
	/*
		부분배열 관리.
		i번째 끝나는 부분배열은 -> i번째 혼자만으로 이루어져 있던가
							  -> [0,i-1]번째에서 끝나는 부분배열에 i를 추가했거나
							  -> 근데 어차피 ㅋㅋ 안되네... 모든 부분배열을 다 살펴봐야 할듯=>O(n^2)

		=>단순 무식하게 2중첩 반복문으로 구현해도 되지만, DFS를 이용하는 편이 좀더 깔끔
	*/
	DFS(0,0);
	cout << ans;
}