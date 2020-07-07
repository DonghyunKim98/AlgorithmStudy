#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    //전체개수 계산
    int sum = brown + red;
    //높이는 최소3부터 시작
    for (int height = 3; ; height++) {
        //총합을 높이로 나누었을때 나머지가 0일때만
        if (!(sum % height)) {
            //합을 높이로 나누면 가로길이가 된다.
            int weight = sum / height;
            //테두리는 갈색이므로 2줄씩 빼고 계산
            //높이에서 2개를빼고 가로길이에서 2개를 빼고 곱한값이 빨간색개수와 같다면 가로 세로 높이를 찾은것이다.
            if (((height - 2) * (weight - 2)) == red) {
                answer.push_back(weight);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}