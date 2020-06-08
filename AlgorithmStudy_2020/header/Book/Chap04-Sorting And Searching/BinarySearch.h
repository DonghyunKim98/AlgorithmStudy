#include <iostream>
#include <cstdlib>
using namespace std;

// ù��° ��� (Dictionary)

void FirstBinarySearch() {
	int n;
	cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++) {
		array[i] = i + 1;
	}
	int x = rand() % n;
	int a = 0, b = n - 1;
	while (a <= b) {
		int k = (a + b) / 2;
		if (array[k] == x) {
			//��ġ k���� x�� ã��
			cout << "��ġ " << k << "���� " << x << "�� ã�Ҵ�!" << endl;
			break;
		}
		if (array[k] < x) a = k + 1;
		else b = k - 1;
	}
	delete array;
	return;
}

//�ι�° ��� (���ʿ��� ���������� �ǳʶٱ�)
void SecondBinarySearch() {
	int n;
	cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++) {
		array[i] = i + 1;
	}
	int x = rand() % n;
	int k = 0;
	for (int b = n / 2; b >= 1; b /= 2) {
		while (k + b < n && array[k + b] <= x) k += b; // �ǳʶپ��µ� ������ ���ڰ� �۾ƾ� �װ����� �ٽ� �ٴ°���!
	}
	if (array[k] == x) {
		cout << "��ġ " << k << "���� " << x << "�� ã�Ҵ�!" << endl;
	}
	return;
}