#include <bits/stdc++.h>
const int MAX = 10000000;
using namespace std;



int solution(string numbers) {
	//1~999999 
	bool* prime = new bool[MAX];
	fill_n(prime, MAX, true);
	//1은 소수가 아님
	for (int i = 2; i <= MAX; i++) {
		if (prime[i] == false) continue;
		for (int j = i * 2; j <= MAX; j += i) 
			prime[j] = false;
	}

	
}

/*
	알고리즘 포인트
	=> numbers를 이용해서 숫자를 만든다 (x)
	=> 숫자가 numbers만을 이용해서 만들어질 수 있는지 check한다(o)

	=> Binary Search에서 간격관련 문제와 아이디어가 비슷
	-> 집과 집사이의 간격을 파악하고 이 간격이 문제 조건에 맞는지 확인한다(x)
	-> 간격이 집과 집사이에 들어갈 수 있는지 파악한다(o)
*/