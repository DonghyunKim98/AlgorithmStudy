#include <bits/stdc++.h>
using namespace std;
const int MAX = 80 + 1;
long long solution(int N) {
	long long answer = 0;
	//memoizaton arr1->���簢���� ���� arr2->��ü�簢���� ����
	long long* arr1 = new long long[MAX];
	long long* arr2 = new long long[MAX];
	//base case
	arr1[1] = 1, arr1[2] = 1;
	arr2[1] = 4, arr2[2] = 6;
	if (N >= 3) {
		//n��° ���簢���� �� ���� ���� = (n-1) + (n-2)��° ���簢��
		//n��° ���簢���� ��ü �ѷ� ���� = (n-1)��° ���簢�� + n��° ���簢���� �� ���� ���� *2
		for (int i = 3; i <= N; i++) {
			arr1[i] = arr1[i - 1] + arr1[i - 2];
			arr2[i] = arr2[i - 1] + arr1[i] * 2;
		}
	}
	answer = arr2[N];
	return answer;
}