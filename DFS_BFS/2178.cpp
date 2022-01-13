#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M;
int matrix[100][100];
bool visited[100][100];

void parsing(int row, string temp){
    for(int i = M - 1 ; i >= 0; i--){
        matrix[row][i] = temp[i] - 48;
    }
}

void bfs(){
    queue <pair<int, int> > bfsQueue;
    bfsQueue.push(make_pair(0, 0));
    visited[0][0] = true;
    // 알고리즘 정리,
    // 1. 최소 거리 탐색은 BFS가 유리하다, 닿는 모든 노드들을 탐색하면서 가기에 처음으로 그 장소에 도달하는 순간이 바로 최소거리이기 때문이다.
    // 2. pop을 하면서 현재 좌표를 변경해주고 다음 좌표로 이동하면 그 전 좌표까지 왔던 칸수를 더해서 matrix에 저장해준다.
    // 3. 그리고 저장한 matrix는 지나갔으므로 visited를 업데이트해준다. 
    while(!visited[N - 1][M - 1]){
        int i = bfsQueue.front().first;
        int j = bfsQueue.front().second;
        bool signal = false;
        bfsQueue.pop();
        if((i - 1 >= 0) && !visited[i - 1][j] && matrix[i - 1][j] > 0){
            bfsQueue.push(make_pair(i - 1, j));
            matrix[i - 1][j] = matrix[i][j] + 1; 
            visited[i - 1][j] = true;
        }
        if((j + 1 < M) && !visited[i][j + 1] && matrix[i][j + 1] > 0){
            bfsQueue.push(make_pair(i, j + 1));
            matrix[i][j + 1] = matrix[i][j] + 1;
            visited[i][j + 1] = true;
        }
        if(( i + 1 < N) && !visited[i + 1][j] && matrix[i + 1][j] > 0){
            bfsQueue.push(make_pair(i + 1, j));
            matrix[i + 1][j] = matrix[i][j] + 1;
            visited[i + 1][j] = true;
        }
        if(( j - 1 >= 0) && !visited[i][j - 1] && matrix[i][j - 1] > 0){
            bfsQueue.push(make_pair(i, j - 1));
            matrix[i][j - 1] = matrix[i][j] + 1;
            visited[i][j - 1] = true;
        }
    }

}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0 ; i < N; i++){
        string temp;
        cin >> temp;
        parsing(i, temp);
    }
    bfs();
    cout << matrix[N - 1][M - 1] << '\n';
    

	return 0;
}