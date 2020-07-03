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
	�������� -> �������� ���� �̾����� Greedy�� �����ߴµ� �װ� �ƴϾ��� �ФФ�

	���� ó������ �����ؼ� [idx,idx+k] ������ ���� ū ���� ��� �ִ� ��. 
	why?) [idx+k+1,end) ������ ������ ���� �ִٰ� �ϴ��� ���̰� number.size()-k ��ŭ�̿��� �ϴ� ������ �ɷ��ֱ� ����
*/