#include <iostream>
#include <queue>
using namespace std;

int tomato[1000][1000];
bool visited[1000][1000] = {false, };
int M, N;
int zeroCount = 0;
queue <pair <int, int> > bfsQueue;


int bfs(){
    int minDay = 0;
    while(!bfsQueue.empty()){
        if(zeroCount == 0)  break;
        int presentSize = bfsQueue.size();
        for(int i = 0 ; i < presentSize; i++){
            int y = bfsQueue.front().first;
            int x = bfsQueue.front().second;
            bfsQueue.pop();
            if( (y + 1 < M) && (tomato[y + 1][x] == 0) && !visited[y + 1][x]  ){
                tomato[y + 1][x] = 1;
                visited[y + 1][x] = true;
                bfsQueue.push(make_pair(y + 1, x));
                zeroCount--;
            }
            if( (x + 1 < N) && (tomato[y][x + 1] == 0) && !visited[y][x + 1]  ){
                tomato[y][x + 1] = 1;
                visited[y][x + 1] = true;
                bfsQueue.push(make_pair(y, x + 1));
                zeroCount--;
            }
            if( (y - 1 >= 0) && (tomato[y - 1][x] == 0) && !visited[y - 1][x]  ){
                tomato[y - 1][x] = 1;
                visited[y - 1][x] = true;
                bfsQueue.push(make_pair(y - 1, x));
                zeroCount--;
            }
            if( (x - 1 >= 0) && (tomato[y][x - 1] == 0) && !visited[y][x - 1]  ){
                tomato[y][x - 1] = 1;
                visited[y][x - 1] = true;
                bfsQueue.push(make_pair(y, x - 1));
                zeroCount--;
            }
        }
        minDay++;
    }
    return minDay;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    // 입력 받기 및, 0카운트 세기, 전체를 토마토를 채울 수 있는지를 보기 위해서.
    cin >> N >> M;
    for(int i = 0 ; i < M; i++){
        for(int j = 0 ; j < N; j++){
            int temp;
            cin >> temp;
            if(temp == 0)    zeroCount++;
            tomato[i][j] = temp;
        }
    }

    for(int i = 0 ; i < M; i++){
        for(int j = 0 ; j < N; j++){
            if(!visited[i][j] && tomato[i][j] == 1){
                bfsQueue.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }
    int ans = bfs();
    if(zeroCount == 0)  cout << ans << '\n';
    else    cout << -1 << '\n';

	return 0;
}