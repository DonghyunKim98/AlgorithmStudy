#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000 + 1;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

string solution(string number, int k) {
	string answer = "";
	int numSize = number.size() - k;
	int start = 0;
	for (int i = 0; i < numSize; i++) {
		char maxNum = number[start];
		int maxIdx = start;
		for (int j = start; j <= k + i; j++) {
			if (maxNum < number[j]) {
				maxNum = number[j];
				maxIdx = j;
			}
		}
		start = maxIdx + 1;
		answer += maxNum;
	}
	return answer;
}

/*
	내림차순 -> 오름차순 으로 이어지는 Greedy를 생각했는데 그게 아니었다 ㅠㅠㅠ

	답은 처음부터 시작해서 [idx,idx+k] 내에서 제일 큰 값만 골라서 넣는 것. 
	why?) [idx+k+1,end) 내에서 최적의 답이 있다고 하더라도 길이가 number.size()-k 만큼이여야 하는 제약이 걸려있기 때문
*/