#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());
	int left = 0, right = people.size() - 1;
	while (left < right+1) {
		//2명을 태울 수 있으면
		if (people[left] + people[right] <= limit)
			left++;
		right--;
		answer++;
	}
	return answer;
}


/*
	알고리즘 포인트
	=> '최대 2명'을 태운다가 핵심
	=> 내가 처음 했던 알고리즘은 (iterator 이용해서 limit-currentWeight를 넘지 않는 최대 값 구하기) 몇명이 탈지 모르는 상황에서 유효
	=> 2명만 탈것이므로 sort하고 가장 몸무게 작은 사람 + 몸무게 큰 사람이 limit을 넘지 않은지만 check해도 된다.
	why?) 굳이 limit을 넘지 않는 선에서 꽉꽉 채울 필요가 없기 때문. 2명이 최대이기 때문이다!

	*erase를 쓰니깐 (while문 이후 탈출 조건을 !people.empty() 로 설정) 시간 초과 -> 느리다
*/