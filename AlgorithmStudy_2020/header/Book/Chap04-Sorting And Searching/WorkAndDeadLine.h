#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Work {
	int dead;
	int time;
};

bool cmp(Work a, Work b) {
	return a.time < b.time;
}

void WorkAndDeadLine(){
	int N;
	cin >> N;
	vector<Work> vc(N);
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		vc[i].time = a;
		vc[i].dead = b;
	}
	sort(vc.begin(), vc.end(), cmp);
	int Max = 0, CurrentTime=0;
	for (int i = 0; i < N; i++) {
		CurrentTime += vc[i].time;
		Max += (vc[i].dead - CurrentTime);
	}
	cout << Max << endl;
	return;
}