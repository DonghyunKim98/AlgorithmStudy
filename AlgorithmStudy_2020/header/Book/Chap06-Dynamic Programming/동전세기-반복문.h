#include <bits/stdc++.h>

using namespace std;
//���� Ŭ���� �ۼ�
template <class T>
class Exception {
	private :
		T elemet;
	public:
		Exception(T element) {
			this.elemet = elemet;
		}
		T getElement() {
			return elemet;
		}
};
void coin1();
void coin2();
void coin3();
void MainCoin() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout << "�������� �����߿� � �� ���ðڽ��ϱ�?" << endl;
	cout << "1)���� ���� ���� �־��� ���� ���� �� �󸶳� ���� ������ �˾Ƴ���" << endl;
	cout << "2)���� ���� ���� �־��� ���� ���⶧ �� ���� ��� ����������� �˾Ƴ���" << endl;
	cout << "3)�־��� ������� �� x�� ����� ����� ���� ���� ����" << endl;

	try {
		string choice;
		cin >> choice;
		if (choice != "1" && choice != "2" && choice !="3") throw choice;
		else if (choice == "1") coin1();
		else if (choice == "2") coin2();
		else coin3();
	}
	catch(string s){
		cout << "�߸��� �Է�"<<s<<"�� �Է��߽��ϴ�"<< endl;
	}
	cout << "�������� ���� ��!" << endl;
}
//���� �⺻���� ��������
void coin1() {
	//Memoization
	int* value = new int[1000];

	cout << "��� ������ �ֽ��ϱ�?" << endl;
	int n;
	cin >> n;
	cout << "������ ��ġ�� �Է��ϼ���" << endl;
	set<int> coins;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coins.insert(temp);
	}
	cout << "�󸶸� ���߰� �ͽ��ϱ�?" << endl;
	int object;
	cin >> object;
	//�ݺ����� ���� ����
	value[0] = 0;
	for (int x = 1; x <= object; x++)
	{
		value[x] = 2147483647;
		for (auto c : coins) {
			if (x - c >= 0) {
				value[x] = min(value[x], value[x - c] + 1);
			}
		}
	}
	cout << "�ʿ��� ������ ���� " << value[object-1] << "�� �Դϴ�." << endl;
}

//�ش��� ��� �����Ǵ��� �˾ƺ��� ���� ����
void coin2() {
	//Memoization
	int* value = new int[1000];
	//� �ش���� ������ �˾ƺ��� ���� �迭
	int first[1000] = { 0, };
	
	cout << "��� ������ �ֽ��ϱ�?" << endl;
	int n;
	cin >> n;
	cout << "������ ��ġ�� �Է��ϼ���" << endl;
	set<int> coins;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coins.insert(temp);
	}
	cout << "�󸶸� ���߰� �ͽ��ϱ�?" << endl;
	int object;
	cin >> object;
	//�ݺ����� ���� ����
	value[0] = 0;
	for (int x = 1; x <= object; x++) {
		value[x] = 2147483647;
		for (auto c : coins) {
			if (x - c >= 0 && value[x - c] + 1 < value[x]) {
				value[x] = value[x - c] + 1;
				first[x] = c;
			}
		}
	}
	cout << "�ּ� " << value[object] << "���� ������ �̿��ؼ� " << object << "�� ���� �� �ֽ��ϴ�." << endl;
	cout << "�׸��� �� ���� ������ {";
	while (object > 0) {
		cout << first[object]<<",";
		object -= first[object];
	}
	cout << "} �Դϴ�." << endl;
}

//�ܼ��� ��ǥ�ϴ� ���ڸ� ������ ������ ���� �� �ִ�  ������ ���� ���ϱ�
void coin3() {
	//Memoization
	int* count = new int[1000]{ 0, };

	cout << "��� ������ �ֽ��ϱ�?" << endl;
	int n;
	cin >> n;
	cout << "������ ��ġ�� �Է��ϼ���" << endl;
	set<int> coins;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coins.insert(temp);
	}
	cout << "�󸶸� ���߰� �ͽ��ϱ�?" << endl;
	int object;
	cin >> object;
	//�ݺ����� ���� ����
	count[0] = 1;
	cout << "\n";
	for (int x = 1; x <= object; x++) {
		for (auto c : coins) {
			if(x-c>=0) count[x] += count[x - c];
		}
	}
	cout << "�� " << object << "�� ���� �� �ִ� ������ ��" << count[object] << "�� �Դϴ�." << endl;
}

/*
	������ 1) ������ ���� �������� �ٸ� �� �Է����� �� �׳� ƨ�� (Runtime Error)
			-> catch ������ ...������ �ݵ�� ���� ������ �Ѱ�����ϴµ� �� �Ѱ��༭ �׷���
			-> string���� ó���� (���߿� int ������ type convert�� �ؾ��ϳ�?)
			-> <�ذ�Ϸ�>
		   2) 2���������� first �迭�� ����ϴ� �������� ���� loop
			-> 0���� ũ�ų� '����'�� ó�� �Ǿ� �־ �׷���
			-> ������ ������ value[object -1] �� �ּҰ��� ��µǴ���,,,
			-> ��� �ּҰ��� �ƴ϶� ���� ó���� �ʱ�ȭ�� �ſ� ū��
			-> base case ������ �߸��ߴ�! �ٵ� ������ ���� Ʋ����!
			-> 3)�� ���� ����...
		   3) ������ ���� count[object-1]�� ����ϸ� �ּҰ� ���
			-> ���� �迭�� �����ϰ� �ʱ�ȭ�� �� �� ���� (�׻� �߻����� ��� ��������)
			-> �׷��� ���� Ʋ����??
			-> �� count[obeject]�� �����̳�... ���� �迭�� �ٸ��� index=0 �� ��ǥ �ݾ��� 0������ setting�� ���̴ϱ�..
			-> <�ذ� �Ϸ�>
*/