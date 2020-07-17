#include <bits/stdc++.h>
//17951번 문제
using namespace std;
const int MAX = 100000 + 1;
int arr[MAX];
int N, K;

int can(int x) {
    int now = 0, cnt = 1;
    for (int i = 1; i <= N; i++) {
        //이번 원소를 넣은게 추론한 그룹의 최솟값을 초과한다면
        if (now + arr[i] >= x) {
            //이번을 마지막으로 넣어준다. (최솟값이니깐!)
            now += arr[i];
            //초기화
            now = 0;
            //그룹의 개수를 늘려줌.
            cnt++;
            //그룹의 개수가 over된다면 최솟값을 너무 작게 잡은것.
            if (cnt > K) {
                return 1;
            }
        }
        else {
            now += arr[i];
        }
    }
    //정상적으로 for문을 다 돌았다 => 21번째줄 if문을 통과 못함 => 최솟값이 너무 큼
    return 0;
}

void solution(){
    //setting
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N >> K;
    
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    //parameter Search
    //답이 될 수 있는 최대값은 모든 원소가 20이면서 나누는 그룹이 1개 일때.
    int start = 0, end = N * 20;
    while (start <= end) {
        int mid = (start + end) / 2;
        //최솟값을 너무 작게 잡은 경우 -> start를 하나 늘려줌
        if (can(mid))    start = mid + 1;
        //최솟값을 너무 크게 잡은 경우 -> end를 하나 줄여줌
        else end = mid - 1;
    }
    cout << end;
}

/*
    주어진 점수를 이용해서 그룹으로 분할 => 최솟값을 가장 크게 만들기.
    단 순서는 유지.


    
*/