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
	메모리 제한뜸. -> 알고리즘 PriorityQueue 배우고 다시 해보자
	*/