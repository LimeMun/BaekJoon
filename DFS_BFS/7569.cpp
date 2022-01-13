#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int tomato[100][100][100];
bool visited[100][100][100] = {false, };
int M, N, H;
int zeroCount = 0;
queue <pair <pair <int, int>, int> > bfsQueue;


int bfs(){
    int minDay = 0;
    while(!bfsQueue.empty()){
        if(zeroCount == 0)  break;
        int presentSize = bfsQueue.size();
        for(int i = 0 ; i < presentSize; i++){
            int y = bfsQueue.front().first.first;
            int x = bfsQueue.front().first.second;
            int z = bfsQueue.front().second;
            bfsQueue.pop();
            if( (y + 1 < M) && (tomato[y + 1][x][z] == 0) && !visited[y + 1][x][z]  ){
                tomato[y + 1][x][z] = 1;
                visited[y + 1][x][z] = true;
                bfsQueue.push(make_pair(make_pair(y + 1, x), z));
                zeroCount--;
            }
            if( (x + 1 < N) && (tomato[y][x + 1][z] == 0) && !visited[y][x + 1][z]  ){
                tomato[y][x + 1][z] = 1;
                visited[y][x + 1][z] = true;
                bfsQueue.push(make_pair(make_pair( y, x + 1), z));
                zeroCount--;
            }
            if( (y - 1 >= 0) && (tomato[y - 1][x][z] == 0) && !visited[y - 1][x][z]  ){
                tomato[y - 1][x][z] = 1;
                visited[y - 1][x][z] = true;
                bfsQueue.push(make_pair(make_pair(y - 1, x), z));
                zeroCount--;
            }
            if( (x - 1 >= 0) && (tomato[y][x - 1][z] == 0) && !visited[y][x - 1][z]  ){
                tomato[y][x - 1][z] = 1;
                visited[y][x - 1][z] = true;
                bfsQueue.push(make_pair(make_pair(y, x - 1), z));
                zeroCount--;
            }
            if( (z - 1 >= 0) && (tomato[y][x][z - 1] == 0) && !visited[y][x][z - 1]  ){
                tomato[y][x][z - 1] = 1;
                visited[y][x][z - 1] = true;
                bfsQueue.push(make_pair(make_pair(y, x), z - 1));
                zeroCount--;
            }
            if( (z + 1 < H) && (tomato[y][x][z + 1] == 0) && !visited[y][x][z + 1]  ){
                tomato[y][x][z + 1] = 1;
                visited[y][x][z + 1] = true;
                bfsQueue.push(make_pair(make_pair(y, x), z + 1));
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
    cin >> N >> M >> H;
    for(int k = 0; k < H; k++){
        for(int i = 0 ; i < M; i++){
            for(int j = 0 ; j < N; j++){
                    int temp;
                    cin >> temp;
                    if(temp == 0)    zeroCount++;
                    tomato[i][j][k] = temp;
            }
        }
    }

    for(int i = 0 ; i < M; i++){
        for(int j = 0 ; j < N; j++){
            for(int k = 0; k < H; k++){
                if(!visited[i][j][k] && tomato[i][j][k] == 1){
                bfsQueue.push(make_pair(make_pair(i, j), k));
                visited[i][j][k] = true;
                }
            }
        }
    }
    int ans = bfs();
    if(zeroCount == 0)  cout << ans << '\n';
    else    cout << -1 << '\n';

	return 0;
}