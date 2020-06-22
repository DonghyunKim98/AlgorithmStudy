#include <bits/stdc++.h>
//1932번 문제
using namespace std;

void IntegerTriangle() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	//입력 받을 때 마다 계산해서 작은것을 골라낸다.
	vector<int> arr[501];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			int temp;
			cin >> temp;
			//예외 처리
			//첫번째 줄

			if (i == 1) arr[i].push_back(temp);
			//첫번째 항 
			else if (j == 1) arr[i].push_back(temp + arr[i - 1].at(0));
			//마지막 항
			else if (j == i) arr[i].push_back(temp + arr[i - 1].at(i - 2));
			//위에서 선택할 수 있는 2가지 중 더 작은 값
			else arr[i].push_back(temp + max(arr[i - 1].at(j-2) , arr[i - 1].at(j -1)));
		}
	}
	sort(arr[N].rbegin(), arr[N].rend());
	cout << arr[N].at(0);
}