#include <bits/stdc++.h>
//2108�� ����
using namespace std;

void Statistics() {
	//setting
	cin.tie(0);
	int N;
	vector<int> vc;
	//�ֺ��� ����ϱ� ���� arr
	int arr[8001];
	fill_n(arr, 8001, 0);

	//input
	cin >> N;
	int temp_N = N;
	int total = 0;
	while (temp_N > 0) {
		int temp;
		cin >> temp;
		total += temp;
		if (temp < 0) arr[abs(temp) + 4000]++;
		else arr[temp]++;
		vc.push_back(temp);
		temp_N--;
	}
	//processing
	sort(vc.begin(), vc.end());
	//������
	printf("%.0f\n", (double)total / N);
	//�߾Ӱ�
	cout << vc.at(N / 2) << '\n';
	//�ֺ�
	vector <int> Most;
	int max = -1;
	for (int i = 0; i <= 8000; i++) {
		if (max == arr[i]) {
			max = arr[i];
			if (i > 4000) 
				Most.push_back(-1 * (i - 4000));
			else Most.push_back(i);
		}
		if (max < arr[i]) {
			max = arr[i];
			Most.clear();
			if (i > 4000) 
				Most.push_back(-1 * (i - 4000));
			else Most.push_back(i);
		}
	}
	sort(Most.begin(), Most.end());
	if (Most.size() == 1) {
		cout << Most.at(0) << '\n';
	}
	else {
		cout << Most.at(1) << '\n';
	}
	//����
	cout << vc.at(N-1) - vc.at(0) << '\n';
}