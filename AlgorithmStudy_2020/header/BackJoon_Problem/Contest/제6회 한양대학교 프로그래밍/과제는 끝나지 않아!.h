#include <bits/stdc++.h>
using namespace std;
//17952�� ���� , ��ô�ȸ a��

int N ; 
int total_Score=0;
// {������ �ɸ��� �ð�, ��������}
stack <pair<int,int>> s;
void Assignment(){
    //setting
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //input & processing
    cin>> N;
    for(int i=0 ; i<N ; i++){
        int is_Assignment;
        cin >> is_Assignment;
        //������ �޾Ҵٸ�
        if(is_Assignment) {
            int score , time;
            cin>> score >> time;
            s.push(make_pair(time,score));
        }
        if(!s.empty()){
            pair<int, int> temp = s.top();
            s.pop();
            temp.first--;
            //���� �ϷḦ �� ��
            if (temp.first)
                s.push(temp);
            //�Ϸ�����
            else
                total_Score += temp.second;
        }
    }

    cout<<total_Score;
}