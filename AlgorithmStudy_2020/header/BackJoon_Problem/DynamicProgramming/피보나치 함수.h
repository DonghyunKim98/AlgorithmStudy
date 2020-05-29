#include <bits/stdc++.h>

using namespace std;

//1003번 문제 ->맞았음
//https://hongku.tistory.com/164 의 코드. -> 표를 그리자! (점화식을 확인할 수 있는 다른 방법)

//Memoization을 위한 배열 -> 모든 원소를 애초에 0으로 초기화 시킴으로써  값이 들어갔나 안들어갔나 확인하는 ready 배열이 없어도 됨
int value[41] = { 0, };

int Calculate(int);

void Fibonacci() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	//base case
	value[0] = 0;
	value[1] = 1;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (temp == 0) cout << "1 0\n";
		else if (temp == 1) cout << "0 1\n";
		else {
			Calculate(temp);
			cout << value[temp - 1] << " " << value[temp] << "\n";
		}
	}
}

int Calculate(int a) {
	if (a == 0 || a == 1) return value[a];
	else if (value[a] != 0) //이미 계산이 되었다는 의미 
	{
		return value[a];
	}
	else {
		return value[a] =Calculate(a - 1) + Calculate(a - 2);
	}
}

/*
	배운점들
	1) '규칙'을 파악하는데에는 역시 표가 좋음
	2) Memorization을 할 때 반드시 배열 2개를 선언해서
	하나는 value를 하나는 그 value가 채워졌는지 확인하는 boolean type의 배열을 선언할 이유는 없다
	3) return 문에서 계산하면 코드를 1줄이라도 줄일 수 있다.
*/