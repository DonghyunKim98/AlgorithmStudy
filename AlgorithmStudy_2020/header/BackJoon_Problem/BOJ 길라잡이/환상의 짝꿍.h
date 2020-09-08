#include <bits/stdc++.h>
//15711�� ����
using namespace std;
typedef long long ll;
const int MAX = 2000000 + 1;
bool is_prime[MAX];
vector<ll> prime_num;

bool isPrime(ll num) {
	for (int i = 0; i < (int)prime_num.size() && (ll)prime_num[i] * prime_num[i] <= num; i++) {
		if (num % prime_num[i] == 0) return 0;
	}
	return 1;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(is_prime, true, sizeof(is_prime));
	for (ll i = 2; i < MAX; i++) {
		//�̹� �ռ����� �Ǻ��� -> continue
		if (!is_prime[i]) continue;
		prime_num.push_back(i);
		for (ll j = 2 * i; j < MAX; j += i) {
			is_prime[j] = false;
		}
	}
	int T;
	cin >> T;
	while (T--) {
		ll a, b;
		cin >> a >> b;
		if (a + b < 4) {
			cout << "NO\n";
			continue;
		}
		if ((a + b) % 2 == 0) {
			cout << "YES\n";
			continue;
		}
		if (isPrime(a + b - 2)) cout << "YES\n";
		else cout << "NO\n";
	}
}

/*
	�迭�� ���Ұ� 200���� �Ǵ°��� �����Ҽ� ����. �� 200������ ���� �Ҽ����� �Ǹ��ϴ� ���� �Ұ���
	=> �׷� ��� Ư�� ���� �Ҽ��� ������ �̷������ �� ����?
	=> �ϴ� �������� �������� 4�̻��� ¦���� ������ ��
	=> 4�̻��� Ȧ���� ��쿣?
	=> ������ "2 + �Ҽ�" �� �̿��� 4�̻��� Ȧ���� ���� �� ���� (2�̻��� �Ҽ��� �� Ȧ���̱⶧��)
	=> �׷� a+b ���� 2�� ������ �Ҽ������� �Ǻ��ϸ� ��
	=> how?) ���� �̸� ���س��� �Ҽ���� ������ ���������� Ȯ��!
	=> � ���� �ռ������ ���μ��� �ִ� �߰����� root(���)���� �̿�!
	

	���� ���н����� ����.
*/