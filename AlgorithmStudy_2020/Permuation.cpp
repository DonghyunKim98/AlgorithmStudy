/*#include <iostream>
#include <vector>

using namespace std;

void search();
int n;
vector <bool> chosen;
vector <int> permutation;
int main() {
	cout << "������ ������ �Է��ϼ���" << endl;
	cin >> n;
	chosen.resize(n + 1);
	chosen[1] = false;
	search();
	return 0;
}

void search() { 
	if (permutation.size() == n) {
		//������ ó��
		cout << "[";
		for (int i = 0; i < permutation.size(); i++) {
			cout << permutation[i];
		}
		cout << "]" << endl;
		return;
	}
	else {		
		for (int i = 1; i <= n; i++) {
			if (chosen[i]) continue;
			chosen[i] = true;
			permutation.push_back(i);
			search();
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}
*/
/*
	�ظ̴� ����: �ϴ� �ƹ��� �����ص� c++���� �迭�� ������ ������ ���߿� �˷��ִ� �����
				 �������� �ʾҴ�. 
				 '������ ���� -> �迭 ����' �� �����ص� '�迭 ����-> ������ ���� -> �迭 �޸� �Ҵ�' �� 
				 �������� �ʴ´�.
				 �׷��� �׳� chosen ���� vector�� �ٲپ���. ���߿� resize method �� �̿��ϸ� �Ǵϱ�.
				 �׸��� chosen[1]�� false�� �ؾ� �˰���� 1�� �������ٵ� �װ� �����ߴ�.
	Algorithm Point : �����Ѵ� ���ߴٸ� bool �迭�� Ȯ���Ѵٴ� ���� �����ϴ�. 
	                  �׸��� ��ʹ� ���� �������ʾƵ�..
*/