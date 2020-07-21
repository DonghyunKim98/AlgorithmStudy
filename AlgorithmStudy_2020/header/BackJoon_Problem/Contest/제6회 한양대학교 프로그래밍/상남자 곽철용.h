#include <bits/stdc++.h>
//17947번 
using namespace std;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M, K;
	cin >> N >> M >> K;
	vector<int> vc(K);
	for (int i = 0; i < K; i++) {
		int cnt = 4 * N / K;
		//나누어 떨어지지 않는 경우 예외 처리
		if (i != 0 && i <= (4 * N) % K) cnt++;
		vc[i] = cnt;
	}
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		vc[n1 % K]--, vc[n2 % K]--;
	}
	int num1, num2;
	cin >> num1 >> num2;
	int gap = abs(num1 % K - num2 % K);
	vc[num1 % K]--, vc[num2 & K]--;

	//오름차순 정렬을 위한 입력
	vector<int> vc2;
	for (int i = 0; i < vc.size(); i++) {
		int cnt = vc[i];
		while (cnt > 0) {
			vc2.push_back(i);
			cnt--;
		}
	}

	int answer = 0;
	int start = 0, end = 1;
	int len = vc2.size() - 1;
	//아무리 pair가 많아도 최대 M-1개. 
	/*
		0 0 0 1 1 2 3 4
		(0,1) (0,1) (0,2), (3,4)
	*/
	map<int, bool> mp;
	while (end<=len&&answer<M-1) {
		//곽철용보다 점수가 높을때까지 일단 end index를 올려줌
		while (vc2[end] - vc2[start] <= gap) {
			end++;
			if (end > len) break;
		}
		if (end >len) break;
		/*
			알고리즘 포인트!!! => 사람들이 뽑는 것은 조합이지 중복조합이 아니다.
			따라서 start-end가 gap을 넘는 순간의 pari를 발견했으면 그 2개를 더이상 못쓰므로,
			start와 end를 둘다 증가시켜줘야 한다.
		*/
		//이전에 end가 방문한 곳이 아니라면 -> answer
		if (mp.count(start)==0) {
			mp[end] = true;
			answer++,start++,end++;
		}
		//이전에 end가 방문한 곳이라면 -> start만 하나 늘려줌
		else {
			start++;
		}
	}
	cout << answer;
}
/*
	two pointer method 이용
	=> O(n log n)이 걸림 (Sorting => n long n / pointer => n)
	=> 2개의 포인터를 이용해서 한 배열을 중복해서 2번돌지 않고 각각 처음부터 끝까지 2*N으로 돈다는 것에 있다.
*/