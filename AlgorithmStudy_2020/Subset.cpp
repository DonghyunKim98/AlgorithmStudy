/*#include <iostream>
#include <vector>

using namespace std;
//�κ����� ó���ϴ� �Լ�
void search(int k);
//������ ������ ����
int n;
//�κ�����
vector <int> subset;
int main() {
	cout << "������ ������ �Է��ϼ���" << endl;
	cin >> n;
	search(0);
	return 0;
}


void search(int k) {
	if (k == n + 1) {
		//�κ����� ó��
		cout << '{';
		for (int i = 0;i < subset.size();i++){
			if (i == subset.size() - 1)
				cout << subset[i] ;
			else
				cout << subset[i] << ',';
		}
		cout << '}'<<endl;
		return;
	}
	else {
		//k�� �κ����տ� ���Խ�Ų��
		subset.push_back(k);
		search(k + 1);
		subset.pop_back();
		//k�� �κ����տ� ���Խ�Ű�� �ʴ´�
		search(k + 1);
	}
}
*/
/* 
	�ظ̴� ����: subset�� �����ŭ�� �κ������� ó���Ҷ� for���� ���ƾ��ϴµ�
				 n���� �����ؼ� ������ �� ������ ������ ������ŭ ���� �Ѱ��� ��������.
				 'element�� ����'��� ���信 ��������� '� vector'�� ���������� �ľ����� ���Ѱ��� �� 
*/