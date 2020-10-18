#include<bits/stdc++.h>
//16472번 문제
using namespace std;
int N;
int arr[26];

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	string s;
	cin >> s;
	memset(arr, 0, sizeof(arr));
	int ptr1 = 0, ptr2 = 0, ans=0, cnt=0;
	while (1) {
		//부분 string에서 알파벳의 개수가 N보다 큼-> 왼쪽 포인터를 한칸 오른쪽으로 옮김
		if (cnt>N) {
			//왼쪽포인터에 해당하는 알파벳의 개수를 일단 삭제해줌
			arr[s[ptr1] - 'a']--;
			if (arr[s[ptr1] - 'a'] == 0) cnt--;
			ptr1++;
		}
		//오른쪽 포인터가 끝까지 옮
		else if (ptr2 == s.size()) break;
		//오른쪽 포인터가 끝까지 오진 않음
		else {
			arr[s[ptr2]-'a']++;
			if (arr[s[ptr2] - 'a'] == 1) cnt++;
			ptr2++;
		}

		//위의 결과에 해당하는 부분 string에 해당하는 알파벳의 개수가 N보다 작다면 ans 갱신
		if (cnt <= N) ans = max((ptr2-ptr1), ans);
	}
	cout << ans;
}

/*
	Two pointer method에서 중요한점
	1. 왼쪽과 오른쪽을 동시에 컨트롤
	2. 왼쪽을 옮기는 조건 => 부분합(배열)이 조건을 만족하지 못했을때
	3. 오른쪽을 옮기는 조건 => 왼쪽을 움직이지 않음 && 오른쪽 포인터가 끝까지 안갔을 경우
						  => 오른쪽을 한칸 움직일땐 조건을 만족하는지 안 하는지는 확인 X
*/