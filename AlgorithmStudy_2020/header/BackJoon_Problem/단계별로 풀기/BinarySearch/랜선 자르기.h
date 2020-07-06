#include <bits/stdc++.h>
//1654번 문제
using namespace std;

void LanCutting() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int K, N;
	vector <long long> vc;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		long long temp;
		cin >> temp;
		vc.push_back(temp);
	}

	//parametric search
	sort(vc.begin(), vc.end());
	long long begin =1, end = vc[vc.size()-1];
	//while문의 조건이 핵심
	//while 문을 탈출 한다는 것은 end가 더 작아진다는 것은 왼쪽 끝값이 더 커진다는 것 . 이때 오른쪽 끝값이 바로 답.
	//why? 일단은 역전당하기 전에 cnt==N을 만족하는 begin과 end로 모여들잖아? 
	//예를 들어서 [100,105] 라고 하자고. 그런데 이때 우리는 begin을 계속 키울거니깐 end는 고정되어있음.
	//따라서 begin이 end를 초과할때의 end를 출력하면 end가 cnt==N을 만족하는 마지막 값이지. (예제에선 105)
	while (begin<=end) {
		long long k = (begin + end) / 2;
		long long cnt = 0;
		for (int i = 0; i < vc.size(); i++)
			cnt += vc.at(i)/ k;
		//자른게 넘치거나 같다 -> k 값을 올려야 함 -> begin 을 위로
		if (cnt >= N) begin = k + 1;
		//자른게 모자르다 -> k 값을 다운 시켜야 함. ->end를 아래로.
		else end = k - 1;
	}
	cout << end;
	
}

/*
	알고리즘 설명
	=> Parametric search https://coderkoo.tistory.com/8 참고
	=> 문제 핵심 구현은 https://navigator-ymin.tistory.com/7 참고


	실수한 부분
	-> Binary Search를 진행할때 start를 0으로 잡은것 (1로 잡자)
	-> 항상 가장 작은 원소와 1사이 에서 답이 발생할 것이라고 생각한것. => 가장 큰 원소를 end로 잡아줌
*/