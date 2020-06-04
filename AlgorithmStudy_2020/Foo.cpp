#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
 
using namespace std;
 
//앞에는 다음 공항, 뒤는 cost
vector<pair<int, pair<int, int> > > idx[101];
const int INF = 1000000007;
//timeDealy 가 곧 Distance 역할 (즉 timeDelay[a] 까지 오는 동안 돈을 얼마 쓰고 왔는지를 구분해야 한다.)
//벽 부수고 이동하기의 알고리즘과 비슷함
int timeDelay[101][10001];
 
void dijkstra(const int& N, const int& MAX_COST) {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= MAX_COST; j++)
            timeDelay[i][j] = INF;
    }
    timeDelay[1][0] = 0;
    //idx[출발공항]={도착공항,{비용,소요시간}}
    //pq => {비용,{시간,공항}}
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push({ 0, {0, 1} });
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int time = pq.top().second.first;
        int here = pq.top().second.second;
        pq.pop();
        if (timeDelay[here][cost] < time)
            continue;
        for (int i = 0; i < idx[here].size(); i++) {
            int nextCost = cost + idx[here][i].second.first;
            int there = idx[here][i].first;
            int nextTime = time + idx[here][i].second.second;
            
            //만일 최대 비용을 초과하는 가격이 나온다면, 패스한다.
            if (nextCost > MAX_COST)
                continue;
            //이 비용 위로 이 시간이 최소 시간이 되는지 확인하고, 미리 설정해준다.
            //이유는, pq에 push를 최소로 하도록 만들어주고, 이미 들어간 값들의 무의미한 계산을 막아주기 위해서이다.
            if (timeDelay[there][nextCost] > nextTime) {
                for (int i = nextCost; i <= MAX_COST; i++) {
                    if (timeDelay[there][i] > nextTime)
                        timeDelay[there][i] = nextTime;
                }
                pq.push({ -nextCost, {timeDelay[there][nextCost], there} });
            }
        }
    }
    int ret = INF;
    for (int i = 1; i <= MAX_COST; i++)
        ret = min(ret, timeDelay[N][i]);
    if (ret == INF)
        cout << "Poor KCM" << endl;
    else
        cout << ret << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    //T=테스트 케이스 수, N=공항의 수, M=지원 비용, K=티켓정보의 수
    int T, N, M, K;
    //u=출발공항, v=도착공항, c=비용, d=소요시간
    int u, v, c, d;
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        //clear
        for (int i = 1; i <= N; i++) {
            while (!idx[i].empty())
                idx[i].pop_back();
        }
        //input
        for (int i = 0; i < K; i++) {
            cin >> u >> v >> c >> d;
            idx[u].push_back({ v, {c, d} });
        }
        dijkstra(N, M);
    }
    
 
 
    return 0;
}
