#include <bits/stdc++.h>
//2661�� ����
using namespace std;
typedef long long ll;
int N;

void DFS(int cnt, string temp_ret) {
	//�������� �˻�.
	//ù��° for�� -> �˻��� ������ ���� ��ġ
	for (int i = 0; i < temp_ret.length(); i++) {
		int j = 0;
		//�ι�° while�� -> �˻��� ������ ������
		while(++j){
			if (i + (j * 2)-1 > temp_ret.length() - 1) break;
			//����° for�� -> ���� �˻��ϰ� �ִ� idx
			for (int k = 0; k < j; k++) {
				if (temp_ret[i + k] != temp_ret[i + j + k]) break;
				if (k == j - 1) return;
			}
		}
	}

	if (cnt == N) {
		//������ ���ʷ� ������ ������ ���̹Ƿ� �ٷ� ���
		cout << temp_ret;
		exit(0);
	}
	for (int i = 1; i <= 3; i++) {
		temp_ret+=to_string(i);
		DFS(cnt + 1, temp_ret);
		temp_ret.pop_back();
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	DFS(0,"");
}

/*
	1. �ܼ� 3^80���δ� �翬�� �ð��ʰ�. BackTracking idea�� �ʿ��ߴ�.
	2. for�� 3���� ��ø�ϴ� ������ �������. 
	ó���� 
	[������ ���� -> ������ ���� ��ġ -> ...] 
	������ ®�µ� ��ƴٴ� �� �˰� 
	[������ ���� ��ġ -> ������ ���� -> ���� idx]
	�� ®���� ���ߴ�
	3. Ư���ϰ� N�϶� ����� �ؾ��ϹǷ�, �������� �˻��ϰ� cnt�� N������ �ٷ� �˻��ؾ� �ߴ�.


	* �ٸ� ��� Ǯ�̵��� ����, substr�� ���� ���� ����. ���� ����ϵ��� ����.
*/