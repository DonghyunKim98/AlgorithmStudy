#include <bits/stdc++.h>
using namespace std;
struct comp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		//���Ƚ�� ���� ���ϰ� , ���Ƚ���� ������ index�� ���� ���� ��ȯ
		if (a.first == b.second) return a.second < b.second;
		else return a.first > b.second;
	}
};


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map <string, int> m;
	//1�� ���� -> ���� ���� �뷡�� ���� �뷡���� ��.
	for (int i = 0; i < genres.size(); i++) {
		if (m.count(genres[i]) == 0)
			m.insert(make_pair(genres[i], plays[i]));
		else m[genres[i]] +=plays[i];
	}
	sort(m.begin(), m.end());
	//2�� ����->���� �뷡�߿��� ���� ���� ����� �뷡���� ����.
	return answer;
}

/*
	�˰��� ����Ʈ -> �ѹ��� �� ó���������� �ϳ��ϳ� ó������

*/