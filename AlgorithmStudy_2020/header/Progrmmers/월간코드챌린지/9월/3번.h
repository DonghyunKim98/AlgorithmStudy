#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
bool arr[MAX];

int solution(vector<int> a) {
    int answer;
    //�� ���ʰ� �������� ������ �ǹǷ�
    a.size() == 1 ? answer = 1 : answer = 2;
   
    //���� ����
    int left_min_num = a[0];
    for (int i = 1; i < a.size()-1; i++) {
        //�̹� ���ڰ� ���ʿ��� ���� ���� ���ڴ�.
        if (a[i] < left_min_num) {
            left_min_num = a[i];
            answer++;
            arr[i] = true;
        }
    }
    //������ ����
    int right_min_num=a[a.size()-1];
    for (int i = a.size() - 2; i >= 1; i--) {
        if (a[i] < right_min_num) {
            right_min_num = a[i];
            if (arr[i]) continue;
            answer++;
            arr[i] = true;
        }
    }
    return answer;
}

/*
        ��ȣ�� ū�� �����°� ��Ģ
        -----<����>a<������>------
        [0,a�� idx]���� a�� ���� ������    -> ������ ����
        [0,a�� idx]���� a�� ���� ���� ����
        -> ������ �ִ�. => ���ʿ��� ���� ū�� ����
                       => ��Ŵ� ������ �� ����
                       => �ٵ� �����ʿ�����

        [���ʿ��� ����ū��]a[�����ʿ��� ���� ū��]
        =>���Ѵ�!
        a->k��°�� ū��&p
        ������!

*/