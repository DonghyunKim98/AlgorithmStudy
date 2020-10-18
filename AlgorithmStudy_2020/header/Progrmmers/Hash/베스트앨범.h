#include <bits/stdc++.h>
using namespace std;
//https://greenapple16.tistory.com/86 참고
bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> mp_count;
	vector<pair<string, int>> vc;

	//장르 별 재생횟수 카운트
	//mp_count에 key 값이 존재하지 않아도 바로 됨
	for (int i = 0; i < genres.size(); i++)
		mp_count[genres[i]] += plays[i];
	map<string, int>::iterator it = mp_count.begin();
	//sort를 위해 맵을 백터에 저장
	for (it = mp_count.begin(); it != mp_count.end(); it++)
		vc.push_back(make_pair(it->first, it->second));

	//재생 횟수를 기준으로 sort
	sort(vc.begin(), vc.end(),cmp);
	//장르별 많이 재생된 두 곡 찾기
	for (int i = 0; i < vc.size(); i++) {
		int first = 0, second = 0, first_index = 0, second_index = 0;
		for (int j = 0; j < genres.size(); j++) {
			//장르를 다 돌면서 (map의 key값도 장르니깐) 일치하면 -> 가장 많이 재생된 횟수
			if (genres[j] == vc[i].first) {
				if (plays[j] > first) {
					second = first;
					second_index = first_index;
					first = plays[j];
					first_index = j;
				}
				else if(plays[j]>second) {
					second = plays[j];
					second_index = j;
				}
			}
		}
		answer.push_back(first_index);
		//장르에 2개 이상의 곡이 있을 경우에만 앨범에 넣기.
		if (second > 0)
			answer.push_back(second_index);
	}
	return answer;
}

/*
	알고리즘 포인트 -> 한번에 막 처리하지말고 하나하나 처리하자

	제발 문제좀 '제대로' 읽자
	나는 "가장 많이 재생된 장르중 top2개에서 2개씩" 이라고 잘못 읽었다.
*/