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
	//ù��° int�� arr2�� �迭, �ι�° int�� priority
	vector<pair<int,int>> vc;

}

/*
	arr1�迭�� ��迭 �Ұǵ� ������ arr2�� ������ ������ ��.
	�� arr2�� �迭�� ������ ũ���� �������� �迭�ϸ� ��
	ex ) arr1 : 3 2 4 1 2

	     arr2 : 5 1 0 4 2
	  -> arr1 : 1 3 4 2 2
*/