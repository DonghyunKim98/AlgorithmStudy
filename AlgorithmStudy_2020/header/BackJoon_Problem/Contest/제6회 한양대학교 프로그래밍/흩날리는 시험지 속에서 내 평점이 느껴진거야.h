#include <bits/stdc++.h>
//17951번 문제
using namespace std;

void Test(){
    //setting
    int N, K;
    vector <int> Score;
    
    //input & proccessing
    cin>>N >> K;
    for(int i=0; i<K; i++){
        Score.push_back(0);
    }
    
    for(int i=0;i<N; i++){
        int x;
        cin>>x;
        Score[0]+=x;
        sort(Score.begin(),Score.end());
    }

    //output
    cout<<Score[0]<<endl;
}

/*
    문제 구현
    => Greedy?? 안 됨
*/