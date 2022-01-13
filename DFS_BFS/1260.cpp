#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool graph[1001][1001] = {false, };
bool visited[1001] = {false, };
int N, M, V;

void reset(){
    for(int i = 0; i < 1001; i++) visited[i] = false;
}

void dfs(int node){
    visited[node] = true;
    cout << node << ' ';
    for(int i = 1; i <= N; i++){
        if((!visited[i]) && (graph[node][i]))    dfs(i);
    }
}

void bfs(){
    queue <int> bfsQueue;
    bfsQueue.push(V);
    visited[V] = true;
    while(bfsQueue.size() > 0){
        int nowValue = bfsQueue.front();
        cout << nowValue << ' ';
        bfsQueue.pop();
        for(int i = 1; i <= N ; i++){
            bool temp = graph[nowValue][i];
            if(!visited[i] && temp){
                bfsQueue.push(i);
                visited[i] = true;
            }
        }
    }
    
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N >> M >> V;
    for(int i = 0 ; i < M; i++){
        int temp, temp2;
        cin >> temp >> temp2;
        graph[temp][temp2] = true;
        graph[temp2][temp] = true;
    }
    dfs(V);
    cout << '\n';
    reset();
    bfs();
    cout << '\n';

	return 0;
}