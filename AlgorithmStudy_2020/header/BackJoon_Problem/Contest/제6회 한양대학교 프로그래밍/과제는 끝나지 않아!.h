#include <bits/stdc++.h>
using namespace std;
//17952번 문제 , 경시대회 a번

int N ; 
int total_Score=0;
// {과제에 걸리는 시간, 과제점수}
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
        //과제를 받았다면
        if(is_Assignment) {
            int score , time;
            cin>> score >> time;
            s.push(make_pair(time,score));
        }
        if(!s.empty()){
            pair<int, int> temp = s.top();
            s.pop();
            temp.first--;
            //아직 완료를 못 함
            if (temp.first)
                s.push(temp);
            //완료했음
            else
                total_Score += temp.second;
        }
    }

    cout<<total_Score;
}