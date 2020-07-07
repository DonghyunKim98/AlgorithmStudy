#include <bits/stdc++.h>
const int MAX = 10000000;
using namespace std;

bool allUsed(int i, string numbers) {
	string si = to_string(i);
	//target number�� �ڸ��� ��ŭ
	for (int j = 0; j < si.size(); j++) {
		int index = numbers.find(si.substr(j, 1));

		//numbers���� �ش� ���ڰ� �߰ߵ��� ���� ���
		if (index >= numbers.size()) {
			return false;
		}
		//�ش� ���ڴ� ���� string�� �����.
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
	//1�� �Ҽ��� �ƴ�
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
		//�Ҽ����
		if (prime[i]) {
			//i�� numbers�� ��Ÿ�������� ���ڸ� answer++
			if (allUsed(i, numbers)) answer++;
		}
	}
	return answer;
}

/*
	�˰��� ����Ʈ
	=> numbers�� �̿��ؼ� ���ڸ� ����� (x)
	=> ���ڰ� numbers���� �̿��ؼ� ������� �� �ִ��� check�Ѵ�(o)

	* Binary Search���� ���ݰ��� ������ ���̵� ���
	-> ���� �������� ������ �ľ��ϰ� �� ������ ���� ���ǿ� �´��� Ȯ���Ѵ�(x)
	-> ������ ���� �����̿� �� �� �ִ��� �ľ��Ѵ�(o)

	=> ������ �ڸ�����ŭ loop�� ���ƾ� �Ѵٸ� "���ڸ� string"���� �ٲ� �Ŀ�(to_string�� ����) size()-1��ŭ �ݺ����� ���� �ȴ�.
*/