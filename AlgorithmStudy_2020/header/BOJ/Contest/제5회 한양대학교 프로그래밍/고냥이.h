#include<bits/stdc++.h>
//16472�� ����
using namespace std;
int N;
int arr[26];

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	string s;
	cin >> s;
	memset(arr, 0, sizeof(arr));
	int ptr1 = 0, ptr2 = 0, ans=0, cnt=0;
	while (1) {
		//�κ� string���� ���ĺ��� ������ N���� ŭ-> ���� �����͸� ��ĭ ���������� �ű�
		if (cnt>N) {
			//���������Ϳ� �ش��ϴ� ���ĺ��� ������ �ϴ� ��������
			arr[s[ptr1] - 'a']--;
			if (arr[s[ptr1] - 'a'] == 0) cnt--;
			ptr1++;
		}
		//������ �����Ͱ� ������ ��
		else if (ptr2 == s.size()) break;
		//������ �����Ͱ� ������ ���� ����
		else {
			arr[s[ptr2]-'a']++;
			if (arr[s[ptr2] - 'a'] == 1) cnt++;
			ptr2++;
		}

		//���� ����� �ش��ϴ� �κ� string�� �ش��ϴ� ���ĺ��� ������ N���� �۴ٸ� ans ����
		if (cnt <= N) ans = max((ptr2-ptr1), ans);
	}
	cout << ans;
}

/*
	Two pointer method���� �߿�����
	1. ���ʰ� �������� ���ÿ� ��Ʈ��
	2. ������ �ű�� ���� => �κ���(�迭)�� ������ �������� ��������
	3. �������� �ű�� ���� => ������ �������� ���� && ������ �����Ͱ� ������ �Ȱ��� ���
						  => �������� ��ĭ �����϶� ������ �����ϴ��� �� �ϴ����� Ȯ�� X
*/