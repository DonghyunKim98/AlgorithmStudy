#include <bits/stdc++.h>
//1932�� ����
using namespace std;

void IntegerTriangle() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	//�Է� ���� �� ���� ����ؼ� �������� ��󳽴�.
	vector<int> arr[501];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			int temp;
			cin >> temp;
			//���� ó��
			//ù��° ��

			if (i == 1) arr[i].push_back(temp);
			//ù��° �� 
			else if (j == 1) arr[i].push_back(temp + arr[i - 1].at(0));
			//������ ��
			else if (j == i) arr[i].push_back(temp + arr[i - 1].at(i - 2));
			//������ ������ �� �ִ� 2���� �� �� ���� ��
			else arr[i].push_back(temp + max(arr[i - 1].at(j-2) , arr[i - 1].at(j -1)));
		}
	}
	sort(arr[N].rbegin(), arr[N].rend());
	cout << arr[N].at(0);
}