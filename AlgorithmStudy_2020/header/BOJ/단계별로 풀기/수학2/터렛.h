#include <bits/stdc++.h>
//1002�� ����
using namespace std;

void Turret() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	//���� ������ ����
	while (T > 0) {
		int xpos1, xpos2, ypos1, ypos2;
		int root1, root2;
		cin >> xpos1 >> ypos1 >> root1 >> xpos2 >> ypos2 >> root2;
		double point_distance = sqrt(pow(xpos1 - xpos2, 2) + pow(ypos1 - ypos2, 2));

		//��ġ�Ҷ�
		if (point_distance == 0 && root1 == root2) cout << -1 << "\n";
		//�ȿ��� �� ������ & �ۿ��� �� ������
		else if (point_distance > root1 + root2 || point_distance < abs(root1 - root2))	 cout << 0 << "\n";
		//�����Ҷ� & �����Ҷ�
		else if (point_distance == root1 + root2 || point_distance == abs(root1 - root2)) cout << 1 << "\n";
		//�������� ������
		else cout << 2 << "\n";
		T--;
	}
}