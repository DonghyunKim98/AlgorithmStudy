#include <iostream>
#include <algorithm>

using namespace std;

int Numsort (){
	int size;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		int temp;
		cin >> temp;
		arr[i] = temp;
	}

	sort(arr, arr+size);

	for (int i = 0; i < size; i++) {
		cout << arr[i]<<"\n";
	}
	return 0;
}

/* 
	�޸� ���Ѷ�. -> �˰��� PriorityQueue ���� �ٽ� �غ���
	*/