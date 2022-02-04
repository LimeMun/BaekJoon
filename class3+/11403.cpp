#include <iostream>

using namespace std;
#define MAX 100
bool graph[MAX][MAX];
bool visited[MAX];
int vertexNum;

// 0 -> 1로 가는 경로가 있는데, 0 -> 2로 가는 경로가 있는지 확인하고 싶다.
// 0 -> 1로 가는 경로를 가지고 dfs를 돌려서, startvertex, endvertex를 두고, 1 -> 2로 가는 경로가 있다면 graph[0][2] = true로 만들어주면 된다. 

void setFalse(){
    for(int i = 0 ; i < MAX; i++)   visited[i] = false;
}

void dfs(int startVertex, int endVertex){
    for(int i = 0; i < vertexNum; i++){
        if(graph[endVertex][i] == true && !visited[i]){
            graph[startVertex][i] = true;
            visited[i] = true;
            dfs(startVertex, i);
        }
    }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> vertexNum;
    for(int i = 0; i < vertexNum; i++){
        for(int j = 0; j < vertexNum; j++){
            cin >> graph[i][j];
        }
    }
    //dfs 탐색
    for(int i = 0 ; i < vertexNum; i++){
        setFalse(); // visited 초기화. 이유는 1-> 4 -> 3 > 2 -> 5 의 경로를 탐색했다고 하자., 그러면 2->4를 가는 경로는 뱡향 그래프여서 이 경로와 별개일 것이다. 그래서 새로 탐색해줘야 하므로 visited를 모두 초기화 해준다.
        for(int j = 0; j < vertexNum; j++){
            if(graph[i][j] == true && !visited[j]){ // 존재하는 경로인데, 탐색하지 않은 정점을 바탕으로 탐색한다.
                visited[j] = true;
                dfs(i, j);
            }
        }
    }
    for(int i = 0; i < vertexNum; i++){
        for(int j = 0; j < vertexNum; j++){
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }



	return 0;
}