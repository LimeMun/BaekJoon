#include <iostream>
#include <queue>
using namespace std;

bool visited[300][300];
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void reset(){
    for(int i = 0 ; i < 300; i++)
        for(int j = 0; j < 300; j++)
            visited[i][j] = false;
}

int knightBfs(int boardSize,pair <int, int> startPoint, pair <int, int> endPoint){
    queue < pair< pair<int, int>, int > > bfsQueue; // 좌표와 현재까지 이동 count를 넣는다.
    bfsQueue.push(make_pair(startPoint, 0));
    visited[startPoint.first][startPoint.second] = true;
    while(!bfsQueue.empty()){
        int y = bfsQueue.front().first.first;
        int x = bfsQueue.front().first.second;
        int count = bfsQueue.front().second;
        bfsQueue.pop();
        if(y == endPoint.first && x == endPoint.second) return count;
        for(int i = 0 ; i < 8; i++){
            int newY = y + dy[i];
            int newX = x + dx[i];
            if(newY >= 0 && newX >= 0 && newY < boardSize && newX < boardSize && !visited[newY][newX]){
                bfsQueue.push(make_pair(make_pair(newY, newX), count + 1));
                visited[newY][newX] = true;
            }
        }
    }
    return -1;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while(testcase-- > 0){
        reset();
        int boardSize;
        cin >> boardSize;
        pair <int, int> startPoint, endPoint;
        cin >> startPoint.first >> startPoint.second;
        cin >> endPoint.first >> endPoint.second;
        cout << knightBfs(boardSize, startPoint, endPoint) << '\n';
    }
	return 0;
}