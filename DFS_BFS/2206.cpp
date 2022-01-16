#include <iostream>
#include <queue>
#include <string>
using namespace std;

int matrix[1000][1000];
bool visited[1000][1000][2]; // 3차원 배열로 만들어주는 이유는 같이 방문한 정점이라도, 벽을 부수고 오냐, 안오냐에 차이가 생기기 때문이다.
int N, M;
queue < pair <pair<int, int>, pair<int, int> > > bfsQueue; // (y좌표, x좌표), (벽 부순 횟수, 길을 온 횟수 )

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void parsing(int row, string temp){
    for(int i = 0 ; i < M; i++) matrix[row][i] = temp[i] - 48;
}

int bfs(){
    bfsQueue.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
    visited[0][0][0] = true;
    while(!bfsQueue.empty()){
            int y = bfsQueue.front().first.first;
            int x = bfsQueue.front().first.second;
            int isBreak = bfsQueue.front().second.first;
            int count = bfsQueue.front().second.second;
            bfsQueue.pop();
            if(y == N - 1 && x == M - 1)    return count;
            for(int j = 0 ; j < 4; j++){ // 상하좌우 좌표를 저장하고, 이동을 할 수 있는지 살핀다.
                int newY = y + dy[j];
                int newX = x + dx[j];
                // 이동할 수 있는 곳을 경로로 탐색하는 경우.
                if(newY >= 0 && newY < N && newX >=0 && newX < M){
                    if(matrix[newY][newX] == 1 && isBreak == 0){ // 벽이고, 벽을 뚫을 수 있는경우
                        bfsQueue.push(make_pair(make_pair(newY, newX), make_pair(isBreak + 1, count + 1)));
                        visited[newY][newX][isBreak + 1] = true;
                    }

                    else if(matrix[newY][newX] == 0 && !visited[newY][newX][isBreak]){ // 벽이 아니고, 이전에 방문한적이 있는지 체크.
                        bfsQueue.push(make_pair(make_pair(newY, newX), make_pair(isBreak, count + 1)));
                        visited[newY][newX][isBreak] = true;
                    }
                }
            }
    }
    return -1;
}

//이 문제의 핵심은 이거다, BFS를 통해서 좌표 이동을 할 때, 이미 들린 좌표가 벽을 뚫고온 경로냐, 아닌 경로냐에 따라서 도달하는 거리가 달라질 수 있다는 것이다.
// 나는 솔직히 그렇다 하더라도, 순서대로 넣는다면 더 빠른 경로가 queue에 먼저 들어가서 벽을 뚫었는지 안뚫었는지만 체크해서 Queue에 넣으면된다고 생각하는데..

// 찾아보니 이게 반례였다.
// 7 4
// 0000
// 1110
// 0000
// 0111
// 0000
// 0011
// 0010

// 시작부분에서 스타트하면 처음에 벽을 깨고 [2.0]을 찍고, visited를 하게 된다. 근데 이 경로는 무조건 끝에 꽉 막힌 지점에 가서 벽을 깨는 걸 써야 경로가 나오는데, 이미 지나가는 길목을 visited를 해버렸으므로 원래 길을 찾을 수가 없는거다.. 그래서 이 부분이 벽을깨고 지나간건지, 벽을 안깨고 지나간건지에 대한 구분이 필요해 보인다. 그래서 visited에 [2]짜리 배열을 추가해서 벽을 깬, 안깬 경로를 둘다 나누어서 구한다. 
// 그래서 벽일 때는, 벽을 뚫을 수 있는지만 체크하고, visited를 업데이트 해준다
// 벽이 아닐 때는, 그 곳이 "벽을 뚫고서 왔는데 지나간 곳인지", "벽을 안뚫고서 왔는데 지나간 곳인지" 현재 진행중인 좌표에서의 isBreak의 값을 참고해서 queue에 추가할 것인지 말것인지 결정해준다.
// 핵심은 벽을 깬 경로, 벽을 안 깨고 가는 경로를 구분해줘야 한다는 것이다. 벽을 깬 경로가 greedy처럼 그지점에선 최단경로 일지라도, dp에서 처럼 전체적으로 봤을때는 최단경로가 아닐 수도 있다.
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0 ; i < N; i++){
        string temp;
        cin >> temp;
        parsing(i, temp);
    }
    cout << bfs() << '\n';

	return 0;
}