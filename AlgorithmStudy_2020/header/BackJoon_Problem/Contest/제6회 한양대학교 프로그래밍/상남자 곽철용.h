#include <bits/stdc++.h>
//17947�� 
using namespace std;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M, K;
	cin >> N >> M >> K;
	vector<int> vc(K);
	for (int i = 0; i < K; i++) {
		int cnt = 4 * N / K;
		//������ �������� �ʴ� ��� ���� ó��
		if (i != 0 && i <= (4 * N) % K) cnt++;
		vc[i] = cnt;
	}
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		vc[n1 % K]--, vc[n2 % K]--;
	}
	int num1, num2;
	cin >> num1 >> num2;
	int gap = abs(num1 % K - num2 % K);
	vc[num1 % K]--, vc[num2 & K]--;

	//�������� ������ ���� �Է�
	vector<int> vc2;
	for (int i = 0; i < vc.size(); i++) {
		int cnt = vc[i];
		while (cnt > 0) {
			vc2.push_back(i);
			cnt--;
		}
	}

	int answer = 0;
	int start = 0, end = 1;
	int len = vc2.size() - 1;
	//�ƹ��� pair�� ���Ƶ� �ִ� M-1��. 
	/*
		0 0 0 1 1 2 3 4
		(0,1) (0,1) (0,2), (3,4)
	*/
	map<int, bool> mp;
	while (end<=len&&answer<M-1) {
		//��ö�뺸�� ������ ���������� �ϴ� end index�� �÷���
		while (vc2[end] - vc2[start] <= gap) {
			end++;
			if (end > len) break;
		}
		if (end >len) break;
		/*
			�˰��� ����Ʈ!!! => ������� �̴� ���� �������� �ߺ������� �ƴϴ�.
			���� start-end�� gap�� �Ѵ� ������ pari�� �߰������� �� 2���� ���̻� �����Ƿ�,
			start�� end�� �Ѵ� ����������� �Ѵ�.
		*/
		//������ end�� �湮�� ���� �ƴ϶�� -> answer
		if (mp.count(start)==0) {
			mp[end] = true;
			answer++,start++,end++;
		}
		//������ end�� �湮�� ���̶�� -> start�� �ϳ� �÷���
		else {
			start++;
		}
	}
	cout << answer;
}
/*
	two pointer method �̿�
	=> O(n log n)�� �ɸ� (Sorting => n long n / pointer => n)
	=> 2���� �����͸� �̿��ؼ� �� �迭�� �ߺ��ؼ� 2������ �ʰ� ���� ó������ ������ 2*N���� ���ٴ� �Ϳ� �ִ�.
*/