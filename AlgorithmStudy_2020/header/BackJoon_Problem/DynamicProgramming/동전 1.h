#include <bits/stdc++.h>

using namespace std;

//2293번 문제 ->맞았음(O)
//https://sihyungyou.github.io/baekjoon-2293/ 참고.
void Coin1() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//n아 동전의 종류 개수 , k가 목표하는 액수
	int n, k;
	cin >> n >> k;
	int* coins = new int[n] {0, };
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coins[i] = temp;
	}
	//Memoization & Base Case
	//가치의 합이 10000원을  안 넘기 때문에 10001까지만 setting.
	int count[10001] = { 0, };
	count[0] = 1;
	//for문의 배치가 달라짐!! -> algorithm 핵심 포인트
	for (int i = 0; i < n; i++) {
		for(int j=coins[i];j<=k;j++){
			if (j - coins[i] >= 0) {
				count[j] += count[j - coins[i]];
			}
		}	
	}
	cout << count[k]<<"\n";
}

/*
	배운점들
	1) 내가 알고 있는 개념을 적용할려면 제대로 적용하자. 
	내가 배운 개념은 set를 이용해서 순서 "상관"있이 새는 방법이다.
	즉 1+2 와 2+1을 다르게 샌다는 것. 하지만 문제는 2개를 같게 취급하라 함!
	2) 이를 어떻게 해결했냐면 중첩된 for문 안에서 
	시작 조건을 int j=coins[x] 로 놓음으로서 한번 쓴 동전은 다시는 안쓰는걸로 처리!!
	(그러면 새롭게 들어오는 동전만 이용하면 되니깐!)
*/
