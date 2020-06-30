#include <bits/stdc++.h>
using namespace std;
struct comp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		//재생횟수 부터 비교하고 , 재생횟수가 같으면 index가 작은 것을 반환
		if (a.first == b.second) return a.second < b.second;
		else return a.first > b.second;
	}
};


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map <string, int> m;
	//1번 과정 -> 제일 속한 노래가 많은 노래들이 봄.
	for (int i = 0; i < genres.size(); i++) {
		if (m.count(genres[i]) == 0)
			m.insert(make_pair(genres[i], plays[i]));
		else m[genres[i]] +=plays[i];
	}
	sort(m.begin(), m.end());
	//2번 과정->속한 노래중에서 가장 많이 재생된 노래들을 수록.
	return answer;
}

/*
	알고리즘 포인트 -> 한번에 막 처리하지말고 하나하나 처리하자

*/