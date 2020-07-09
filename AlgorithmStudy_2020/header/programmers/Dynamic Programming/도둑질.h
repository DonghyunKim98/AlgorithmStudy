#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
//memoization
//arr -> 0번째 value를 포함하는 수열
int arr[MAX];
//brr -> 0번째 value를 포함하지 않는 수열
int brr[MAX];

int solution(vector<int> money) {
	int answer = 0;
	//base case 
	arr[0] = money[0], arr[1] = money[0], arr[2] = money[0];
	brr[0] = 0, brr[1] = money[1], brr[2] = max(money[1], money[2]);

	for (int i = 3; i < money.size(); i++) {
		arr[i] = max(arr[i - 1], arr[i - 2] + money[i - 1]);
		brr[i] = max(brr[i - 1], brr[i - 2] + money[i]);
	}
	return max(arr[money.size()-1], brr[money.size()-1]);
}