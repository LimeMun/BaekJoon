#include <iostream>
#include <queue>
using namespace std;

int nodeNum, nodeLine;
bool graph[101][101] = {false, };
bool visited[101] = {false, };
queue <int> bfsQueue;

void bfs(){
    int count = 0;
    bfsQueue.push(1);
    visited[1] = true;
    while(!bfsQueue.empty()){
        int nowValue = bfsQueue.front();
        bfsQueue.pop();
        for(int i = 1; i <= nodeNum; i++){
            if(!visited[i] && graph[nowValue][i]){
                bfsQueue.push(i);
                visited[i] = true;
                count++;
            }
        }
    }
    cout << count << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> nodeNum >> nodeLine;
    for(int i = 0; i < nodeLine; i++){
        int temp, temp2;
        cin >> temp >> temp2;
        graph[temp][temp2] = true;
        graph[temp2][temp] = true;
    }
    bfs();

	return 0;
}