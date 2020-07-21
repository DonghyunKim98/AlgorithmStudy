#include <bits/stdc++.h>
//17939번 문제
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<int> vc(N + 1);
	//index 포함하는 배열!! => 한번 했던 것.
	vector<pair<int, int>> brr(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> vc[i];
		brr[i] = { vc[i],i };
	}
	//내림차순으로 정렬
	sort(brr.begin()+1, brr.end());
	reverse(brr.begin() + 1, brr.end());

	int start = 1, end = N, idx = 1, answer=0;
	while (start < end) {
		/*
			n+1번째로 큰 수가 n번째 큰수보다 뒤에 나온다면 문제가 없겠지만
			앞에 나온다면, idx가 start보다도 뒤쳐지는 사태가 발생.
			-> idx를 끌어올려줌
		*/
		while (brr[idx].second < start) idx++;
		int MAX_IDX = brr[idx].second, MAX=brr[idx].first, tempSum = 0;
		for (int i = start; i <= MAX_IDX; i++) {
			tempSum += vc[i];
		}
		answer += (brr[idx].first * (MAX_IDX - start + 1) - tempSum);
		start = MAX_IDX + 1;
	}
	cout << answer;
}

/*
	반례찾기!! 그냥 예제만 보고 그것만 된다고 생각하지말고 다양한 생각을 하자.
	더 큰수가 뒤에 나온다면 존버를 해야한다는 것을..
	구현력은 계속 여러 코드들을 보면서 생각하고 준비하자.
	예외에 대해서 계속 고민해봐야하고 생각해봐야 한다.
*/