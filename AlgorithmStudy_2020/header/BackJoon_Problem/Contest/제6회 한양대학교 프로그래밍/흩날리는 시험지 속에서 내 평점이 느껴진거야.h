#include <bits/stdc++.h>
//17951�� ����
using namespace std;
const int MAX = 100000 + 1;
int arr[MAX];
int N, K;

int can(int x) {
    int now = 0, cnt = 1;
    for (int i = 1; i <= N; i++) {
        //�̹� ���Ҹ� ������ �߷��� �׷��� �ּڰ��� �ʰ��Ѵٸ�
        if (now + arr[i] >= x) {
            //�̹��� ���������� �־��ش�. (�ּڰ��̴ϱ�!)
            now += arr[i];
            //�ʱ�ȭ
            now = 0;
            //�׷��� ������ �÷���.
            cnt++;
            //�׷��� ������ over�ȴٸ� �ּڰ��� �ʹ� �۰� ������.
            if (cnt > K) {
                return 1;
            }
        }
        else {
            now += arr[i];
        }
    }
    //���������� for���� �� ���Ҵ� => 21��°�� if���� ��� ���� => �ּڰ��� �ʹ� ŭ
    return 0;
}

void solution(){
    //setting
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N >> K;
    
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    //parameter Search
    //���� �� �� �ִ� �ִ밪�� ��� ���Ұ� 20�̸鼭 ������ �׷��� 1�� �϶�.
    int start = 0, end = N * 20;
    while (start <= end) {
        int mid = (start + end) / 2;
        //�ּڰ��� �ʹ� �۰� ���� ��� -> start�� �ϳ� �÷���
        if (can(mid))    start = mid + 1;
        //�ּڰ��� �ʹ� ũ�� ���� ��� -> end�� �ϳ� �ٿ���
        else end = mid - 1;
    }
    cout << end;
}

/*
    �־��� ������ �̿��ؼ� �׷����� ���� => �ּڰ��� ���� ũ�� �����.
    �� ������ ����.


    
*/