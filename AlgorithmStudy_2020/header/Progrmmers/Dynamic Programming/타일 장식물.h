#include <bits/stdc++.h>
using namespace std;
const int MAX = 80 + 1;
long long solution(int N) {
	long long answer = 0;
	//memoizaton arr1->정사각형의 길이 arr2->전체사각형의 길이
	long long* arr1 = new long long[MAX];
	long long* arr2 = new long long[MAX];
	//base case
	arr1[1] = 1, arr1[2] = 1;
	arr2[1] = 4, arr2[2] = 6;
	if (N >= 3) {
		//n번째 정사각형의 한 변의 길이 = (n-1) + (n-2)번째 정사각형
		//n번째 직사각형의 전체 둘레 길이 = (n-1)번째 직사각형 + n번째 정사각형의 한 변의 길이 *2
		for (int i = 3; i <= N; i++) {
			arr1[i] = arr1[i - 1] + arr1[i - 2];
			arr2[i] = arr2[i - 1] + arr1[i] * 2;
		}
	}
	answer = arr2[N];
	return answer;
}