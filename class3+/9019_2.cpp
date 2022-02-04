#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define MAX 10000

int visited[MAX];

// 이 문제의 핵심은, string 연산을 최대한 줄이는 것이었다. 애초에 숫자도 편하게 계산하기 위해서 string으로 저장해버리면, 시간이 많이 소요될 수 밖에 없었다.

void resetArr(){
    for(int i = 0 ; i < MAX; i++)   visited[i] = 1000000000;
}

void bfs(int start, int end){
    queue < pair <int, string > > bfsQueue; // 숫자와, D, S, L ,R 을 저장하는 배열
    bfsQueue.push(make_pair(start, ""));
    visited[start] = 0;
    string ans;
    while(!bfsQueue.empty()){
        int nowNum = bfsQueue.front().first;
        string nowCommand = bfsQueue.front().second;
        int nowCommandSize = nowCommand.size() + 1;
        bfsQueue.pop();
        if(nowNum == end){
            cout << nowCommand << '\n';
            break;
        }

        int D = (nowNum * 2) % 10000;
        if(nowCommandSize < visited[D]){
            visited[D] = nowCommandSize;
            bfsQueue.push(make_pair(D, nowCommand + "D"));
        }
        int S = nowNum - 1;
        if(nowNum == 0) S = 9999;
        if(nowCommandSize < visited[S]){
            visited[S] = nowCommandSize;
            bfsQueue.push(make_pair(S, nowCommand + "S"));
        }

        int L = (nowNum % 1000) * 10 + (nowNum / 1000);
        if(nowCommandSize < visited[L]){
            visited[L] = nowCommandSize;
            bfsQueue.push(make_pair(L, nowCommand + "L"));
        }

        int R = (nowNum % 10) * 1000 + ((nowNum - (nowNum % 10)) / 10);
        if(nowCommandSize < visited[R]){
            visited[R] = nowCommandSize;
            bfsQueue.push(make_pair(R, nowCommand + "R"));
        }
    }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int testNum;
    cin >> testNum;
    while(testNum-- > 0){
        resetArr();
        int a, b;
        cin >> a >> b;
        bfs(a, b);
        
    }

	return 0;
}