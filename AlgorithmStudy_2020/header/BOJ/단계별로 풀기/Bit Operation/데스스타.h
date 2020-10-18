#include <bits/stdc++.h>
//11811번 문제
using namespace std;
const int MAX = 1000 + 1;
int N;
int Array[MAX];

void DeathStar() {
	//setting
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input & process
	cin >> N;
	int temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			if (i == j) continue;
			Array[i] = Array[i] | temp;
		}
	}


	//output
	for (int i = 1; i <= N; i++) {
		cout << Array[i]<<" ";
	}
}

/*
	문제점) 기존의 값의 결과물을 계속 가져가야 함.
	=>내 첫 구현: 가정
	=>실제 답 : 기존의 값을 활용하여 비트연산을 함

	배울점) 메모리 관리에 있어서 단 한번만 처리하고 갈 뿐인 자료는 굳이 저장할 이유가 없다.
	=> 이 문제에서 행렬
*/