#include <bits/stdc++.h>
//17938�� ����
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	
	int position, T;
	cin >> position >> T;
	T %= 2 * N -1;

	int cnt_before = 0, cnt_after=0;
	for (int i = 1; i <= T; i++) {
		//���� ���� �ϴ� ���� ����
		int temp;
		if (i <= N) temp = i;
		else temp = 2 * N - i;
		if (i != T) cnt_before += temp;
		else cnt_after += (temp + cnt_before);
 	}
	//position�� N��° ��ġ������ ����ó��
	if (position == N) {

	}
	else if (position * 2 <= ) {

	}

}