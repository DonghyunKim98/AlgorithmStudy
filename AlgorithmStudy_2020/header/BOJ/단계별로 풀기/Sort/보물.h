#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Treasure() {
	int size;
	cin >> size;
	int* arr1 = new int[size];
	int* arr2 = new int[size];

	for (int i = 0; i < size; i++) {
		int temp;
		cin >> temp;
		arr1[i] = temp;
	}
	for (int i = 0; i < size; i++) {
		int temp;
		cin >> temp;
		arr2[i] = temp;
	}
	//첫번째 int는 arr2의 배열, 두번째 int는 priority
	vector<pair<int,int>> vc;

}

/*
	arr1배열을 재배열 할건데 순서는 arr2의 순서를 따르는 것.
	즉 arr2의 배열의 원소의 크기의 역순으로 배열하면 됨
	ex ) arr1 : 3 2 4 1 2

	     arr2 : 5 1 0 4 2
	  -> arr1 : 1 3 4 2 2
*/