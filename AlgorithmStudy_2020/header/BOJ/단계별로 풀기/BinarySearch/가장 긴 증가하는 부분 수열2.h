#include <bits/stdc++.h>
//12015번 문제
//https://eine.tistory.com/entry/%EA%B0%80%EC%9E%A5-%EA%B8%B4-%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4LIS-Longest-Increasing-Subsequence 참고
using namespace std;

void LIS() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector <int> vc;

	vc.push_back(INT_MIN);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (temp > vc.back()) {
			vc.push_back(temp);
			cnt++;
		}
		else {
			vector<int>::iterator low = lower_bound(vc.begin(), vc.end(), temp);
			*low = temp;
		}
	}
	cout << cnt;
}

/*
	N이 10만이므로 그냥 O(n^2) 으론 Time Limit Exceeded
	-> 이분 탐색을 이용해야 함

	알고리즘 포인트
	=> length를 각각 계산해서 DP로 계산하는 것이 아닌 LIS 배열 자체를 만드는 것
	=> 즉 입력받는 대로 증가하는 수열로 만들어서 넣자!
	how?) 입력받은 수가 LIS의 마지막 수(가장 큰 수)보다 큼 -> 맨 마지막에 넣어
		  입력받은 수가 LIS의 마지막 수보다 작음 -> 이진탐색을 통해 넣어야 하는 위치에다가 바꾸어주면 됨 (lower_bound 이용)
		  -> 이때, 그렇게 바꾸어버리면 안되잖아! 라고 생각이 드는데 어차피 우리가 구하는건 LIS자체가 아닌 LIS에서 원소의 '개수'
		  -> 따라서 이렇게 해도 됨.
*/