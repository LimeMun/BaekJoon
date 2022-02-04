#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 1000001
bool visited[MAX];
int targetNum, errorButNum;
bool disableButton[10] = {false, };

queue <pair <int ,int > > bfsQueue; // <num, count>
vector <pair <int, int> > targetedArr;

void bfs(){
    if(targetNum == 100){
        cout << 0 << '\n';
        return;
    }
    for(int i = 1; i < 10; i++){ // 먼저 채널을 번호로 입력하는 경우.
        if(disableButton[i])    continue;
        bfsQueue.push(make_pair(i, 1));
        visited[i] = true;
    }
    if(!disableButton[0]) visited[0] = true;

    while(!bfsQueue.empty()){
        int nowNum = bfsQueue.front().first;
        int nowCount = bfsQueue.front().second;
        bfsQueue.pop();
        for(int i = 0; i < 10; i++){ // 숫자를 뒤에 하나씩 추가하는 경우
            if(disableButton[i])    continue;
            int make_num = nowNum * 10 + i;
            //  입력하기 전 번호보다 상대적 거리가 가까운 경우.
            if(abs(targetNum - make_num) < abs(targetNum - nowNum) ){ 
                //새로운 채널은, 원래 채널보다 횟수가 1회 많으므로, 현재 채널보다 누르는 횟수가 작을때만 q ueue에 넣어야한다.
                if(!visited[make_num]){ // 방문하지 않은 경우 push해준다.
                    visited[make_num] = true;
                    bfsQueue.push(make_pair(make_num, nowCount + 1));
                }
            }
            else{ // 현재 거리가 가까운경우, 정답이 될 수 있는 arr에 추가한다.
                targetedArr.push_back(make_pair(nowNum, nowCount));
            }
        }
    }

    targetedArr.push_back(make_pair(100, 0));
    if(!disableButton[0])   targetedArr.push_back(make_pair(0, 1));
    int ans = 1000000000;
    for(int i = 0 ; i < targetedArr.size(); i++){
        ans = min(ans, abs(targetedArr[i].first - targetNum) + targetedArr[i].second);
    }
    cout << ans << '\n';

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> targetNum;
    cin >> errorButNum;
    for(int i = 0 ; i < errorButNum; i++){
        int temp;
        cin >> temp;
        disableButton[temp] = true;
    }
    bfs();

	return 0;
}