#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());
	int left = 0, right = people.size() - 1;
	while (left < right+1) {
		//2���� �¿� �� ������
		if (people[left] + people[right] <= limit)
			left++;
		right--;
		answer++;
	}
	return answer;
}


/*
	�˰��� ����Ʈ
	=> '�ִ� 2��'�� �¿�ٰ� �ٽ�
	=> ���� ó�� �ߴ� �˰����� (iterator �̿��ؼ� limit-currentWeight�� ���� �ʴ� �ִ� �� ���ϱ�) ����� Ż�� �𸣴� ��Ȳ���� ��ȿ
	=> 2�� Ż���̹Ƿ� sort�ϰ� ���� ������ ���� ��� + ������ ū ����� limit�� ���� �������� check�ص� �ȴ�.
	why?) ���� limit�� ���� �ʴ� ������ �˲� ä�� �ʿ䰡 ���� ����. 2���� �ִ��̱� �����̴�!

	*erase�� ���ϱ� (while�� ���� Ż�� ������ !people.empty() �� ����) �ð� �ʰ� -> ������
*/