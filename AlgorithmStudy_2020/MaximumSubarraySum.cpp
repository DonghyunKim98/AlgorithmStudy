#include <iostream>

using namespace std;

template <class T>
T max(T a, T b);

int main() {
	int n;
	cout << "�迭�� ������ ������ �Է��ϼ���: ";
	cin >> n;
	int* array = new int[n];
	cout << "�迭�� ���Ҹ� �Է��ϼ���  \n";
	for (int i = 0; i < n; i++) {
		int temp;
		cout << i + 1 << ":";
		cin >> temp;
		array[i] = temp;
	}

	int best = 0, sum = 0;
	for (int k = 0; k < n; k++) {
		sum = max(array[k], sum + array[k]);
		best = max(best, sum);
	}

	cout << "�κ� �迭�� �ִ� ���� " << best << "�Դϴ�"; 
	delete array;

}

template <class T>
T max(T a, T b) {
	if (a > b) return a;
	else return b;
}