#include <bits/stdc++.h>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    int begin = 0, end = rocks[rocks.size() - 1];
    while (begin <= end) {
        //�ּڰ� gap
        int gap = (begin + end) / 2;
        //cnt�� ���ִ� ������ ����. std �� gap�� ���� ��ġ ����
        int cnt = 0, std=0;
        for (int i = 0; i <= rocks.size(); i++) {
            int current;
            if (i != rocks.size()) current = rocks[i];
            else current = distance;
            //gap���� ���� -> std�� �ٲ���
            if (current - std >= gap) std = current;
            //gap���� ���� -> �� ������ ���� (cnt�� �ø�)
            else cnt++;
        }
        //���� ������ ���� -> gap�� �ٿ��� �� (�׷��� �� ����)
        if (cnt <= n) begin = gap + 1;
        //���� ������ ���� -> gap�� �÷��� �� (�׷��� �� ����)
        else end = gap - 1;
    }
    return end;
}

/*
    rocks[0]�� ����� ���� ��� ó������? => ���ʿ� �������� ����������� �����϶�� �Ǿ� ����
*/