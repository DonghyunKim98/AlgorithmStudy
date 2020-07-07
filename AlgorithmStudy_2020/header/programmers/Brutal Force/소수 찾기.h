#include <bits/stdc++.h>
const int MAX = 10000000;
using namespace std;

bool allUsed(int i, string numbers) {
	string si = to_string(i);
	//target number의 자리수 만큼
	for (int j = 0; j < si.size(); j++) {
		int index = numbers.find(si.substr(j, 1));

		//numbers에서 해당 숫자가 발견되지 않을 경우
		if (index >= numbers.size()) {
			return false;
		}
		//해당 숫자는 지운 string을 만든다.
		else {
			numbers.erase(numbers.begin() + index);
		}
	}
	return true;
}

int solution(string numbers) {
	int answer = 0;
	//1~999999 
	bool* prime = new bool[MAX];
	fill_n(prime, MAX, true);
	//1은 소수가 아님
	for (int i = 2; i <= MAX; i++) {
		if (prime[i] == false) continue;
		for (int j = i * 2; j <= MAX; j += i) 
			prime[j] = false;
	}

	vector<char> vc(numbers.size());
	for (int i = 0; i < numbers.size(); i++)
		vc[i] = numbers[i];
	sort(vc.begin(), vc.end(),greater<int>());
	int MAX = 0;
	for (int i = 0; i < vc.size(); i++)
		MAX +=int(vc[i]-'0') * pow(10, vc.size() - 1 - i);

	vector<char>::iterator it;
	for (int i = 2; i <= MAX; i++) {
		//소수라면
		if (prime[i]) {
			//i가 numbers로 나타내어지는 숫자면 answer++
			if (allUsed(i, numbers)) answer++;
		}
	}
	return answer;
}

/*
	알고리즘 포인트
	=> numbers를 이용해서 숫자를 만든다 (x)
	=> 숫자가 numbers만을 이용해서 만들어질 수 있는지 check한다(o)

	* Binary Search에서 간격관련 문제와 아이디어가 비슷
	-> 집과 집사이의 간격을 파악하고 이 간격이 문제 조건에 맞는지 확인한다(x)
	-> 간격이 집과 집사이에 들어갈 수 있는지 파악한다(o)

	=> 숫자의 자리수만큼 loop를 돌아야 한다면 "숫자를 string"으로 바꾼 후에(to_string을 쓴다) size()-1만큼 반복문을 돌면 된다.
*/