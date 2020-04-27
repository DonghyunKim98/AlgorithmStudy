#include <bits/stdc++.h>
using namespace std;
//10989번 문제 ->맞았음(O)
//https://league-cat.tistory.com/4 를 참고

void Sort3() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	//array를 N만큼만 할당하면 메모리초과 뜰거임 
	//index를 data value로 삼기로 했으니깐 그정도만 해도 됨
	int* array = new int[10001]{ 0, };
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		array[temp]++;
	}

	for (int i = 1; i < 10001; i++) {
		if (array[i] == 0) continue;
		else {
			for(int j=0;j<array[i];j++)
			cout << i<<"\n";
		}
	}
}

/*
	배워야 할 점
	1) 수행시간 어림짐작하기. 
	- 주어진 시간제한은 3초 / 메모리 제한은 8MB이다.
	- 주어진 입력값의 최대 개수 (Worst Case)는 1000만개.
	- 보통의 알고리즘인 O(n log n)을 하면 2000만 x 3 =6000만까지 밖에 커버를 못함
	- 즉 더 빠른 알고리즘이 필요한데, 중요한건 입력 데이터의 범위가 1부터 10000까지밖에 안된다는 점을 이용해야함!!
	2) <"입력 데이터의 개수"를 index로 하는 것이 아닌, "입력 데이터의 최대값"을 index로 하는것!!>
	- index에 해당하는 값이 들어오면 해당 index가 몇개가 있는지를 출력하는 것이다!
*/