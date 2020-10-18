#include <bits/stdc++.h>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    int begin = 0, end = rocks[rocks.size() - 1];
    while (begin <= end) {
        //최솟값 gap
        int gap = (begin + end) / 2;
        //cnt는 없애는 바위의 개수. std 는 gap의 시작 위치 바위
        int cnt = 0, std=0;
        for (int i = 0; i <= rocks.size(); i++) {
            int current;
            if (i != rocks.size()) current = rocks[i];
            else current = distance;
            //gap보다 넓음 -> std만 바꿔줌
            if (current - std >= gap) std = current;
            //gap보다 좁음 -> 그 바위를 없앰 (cnt를 늘림)
            else cnt++;
        }
        //적은 바위를 없앰 -> gap을 줄여야 함 (그래야 덜 없앰)
        if (cnt <= n) begin = gap + 1;
        //많은 바위를 없앰 -> gap을 늘려야 함 (그래야 더 없앰)
        else end = gap - 1;
    }
    return end;
}

/*
    rocks[0]을 지우는 경우는 어떻게 처리하지? => 애초에 문제에서 출발지점에서 시작하라고 되어 있음
*/