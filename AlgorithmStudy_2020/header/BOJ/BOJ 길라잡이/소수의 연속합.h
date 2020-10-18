#include <bits/stdc++.h>
//1644�� ����
using namespace std;
const int MAX = 4000000 + 1;
int N;
bool is_prime[MAX];
vector<int> prime_num;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	//base case
	fill_n(is_prime, MAX, true);
	for (int i = 2; i <= N; i++) {
		//�̹� �ռ����� �Ǻ��� -> continue
		if (!is_prime[i]) continue;
		//i�� �Ҽ����, vector�� ����ְ� i*2���� [i*3,i*4...,N]���� �ռ������ ����
		prime_num.push_back(i);
		for (int j = 2 * i; j <= N; j += i) {
			is_prime[j] = false;
		}
	}
	int ptr1 = 0, ptr2 = 0;
	int ans = 0, temp_sum = 0;
	while (1) {
		//�κ����� ŭ -> ���� �����͸� ��ĭ ���������� �ű� (�κ��տ��� ���� �����Ͱ� �ű�� ���� �ش��ϴ� ���� ����)
		if (temp_sum >= N) {
			temp_sum -= prime_num[ptr1++];
		}
		//������ �����Ͱ� ������ �� -> Ż��
		else if (ptr2 == prime_num.size()) break;
		//������ �����Ͱ� ������ ���� ���� -> �����Ϳ� �ش��ϴ� ���� sum�� �߰��ϰ� ��ĭ �ű�
		else temp_sum += prime_num[ptr2++];

		//���� ����� N�� ���ٸ� ans �߰�
		if (temp_sum == N) ans++;
	}
	cout << ans;
}

/*
	Two pointer method(�� ������ ���) �� �̿��� ��ǥ���� ����
	=> �κй迭�� ���� Ư�� ���� ���� ���� �κй迭 ã��.
	=> ����, ������ �����͸� �̿��ؼ� ����
	=> ���� Ư�� ���� ���� �Ѿ��ٸ�, ���������͸� ��ĭ ������
	=> ���� �ʾҴٸ�, �����������͸� ��ĭ ������
	=> ��������� ����������, ������������ �Ѵ� ��ü �迭�� 1���� ���캸�Ƿ� O(N)�� �ȴ�.
*/