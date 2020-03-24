#include <iostream>
#include <cstdlib>
using namespace std;

// 첫번째 방법 (Dictionary)

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
			//위치 k에서 x를 찾음
			cout << "위치 " << k << "에서 " << x << "를 찾았다!" << endl;
			break;
		}
		if (array[k] < x) a = k + 1;
		else b = k - 1;
	}
	delete array;
	return;
}

//두번째 방법 (왼쪽에서 오른쪽으로 건너뛰기)
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
		while (k + b < n && array[k + b] <= x) k += b; // 건너뛰었는데 여전히 숫자가 작아야 그곳에서 다시 뛰는거지!
	}
	if (array[k] == x) {
		cout << "위치 " << k << "에서 " << x << "를 찾았다!" << endl;
	}
	return;
}