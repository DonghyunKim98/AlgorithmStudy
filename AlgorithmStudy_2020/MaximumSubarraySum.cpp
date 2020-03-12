#include <iostream>

using namespace std;

template <class T>
T max(T a, T b);

int main() {
	int n;
	cout << "배열의 원소의 개수를 입력하세요: ";
	cin >> n;
	int* array = new int[n];
	cout << "배열의 원소를 입력하세요  \n";
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

	cout << "부분 배열의 최대 합은 " << best << "입니다"; 
	delete array;

}

template <class T>
T max(T a, T b) {
	if (a > b) return a;
	else return b;
}