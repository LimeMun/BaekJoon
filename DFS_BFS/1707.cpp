#include <iostream>
#include <vector>
using namespace std;
#define MAX 20000+1

//핵심은 이분그래프를 찾아내는 방법이다. DFS를 통해서 한 vertex에 연결된 간선을 계속 따라가면서 1,2를 번갈아 가며 기록한다. 그러둔 중, 자기랑 연결된 vertex 중 자기 자신과 같은 값을 가진애가 나오면 이분그래프는 성립 할 수 없다. 서로가 연결되어있는 vertex는 각기 다른 값을 가져야 이분그래프가 성립하기 때문이다!

vector <int> graph[MAX]; // 이렇게 해서 벡터에 2차원 배열을 넣을 수 있다.
int visited[MAX]; // 0은 방문을 하지 않은 경우, 1,2는 각 이분그래프
bool noSig = false;

void reset(){
    
    for(int i = 0; i < MAX; i++){
        visited[i] = 0;
        graph[i].clear();
    }
    noSig = false;

}

void dfs(int vertex){
    for(int i = 0; i < graph[vertex].size(); i++){
        int nowNode = graph[vertex][i]; // 현재 vertex와 연결되어 있는 노드.
        if(visited[nowNode] == 0){
            if(visited[vertex] == 1)    visited[nowNode] = 2;
            else if (visited[vertex] == 2)  visited[nowNode] = 1;
            dfs(nowNode);
        }
        else if(visited[nowNode] == visited[vertex]){ // 같은 값이 나온경우 이분그래프는 성립이 불가능
            noSig = true;
            break;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while(testcase-- > 0){
        reset();
        int vertex, edge;
        cin >> vertex >> edge;
        for(int i = 0 ; i < edge; i++){
            int temp, temp2;
            cin >> temp >> temp2;
            graph[temp].push_back(temp2);
            graph[temp2].push_back(temp);
        }
        for(int i = 1 ; i < vertex + 1; i++){
            if(visited[i] == 0) {
                visited[i] = 1;
                dfs(i);
            }
            if(noSig)   break;
        }
        if(noSig)   cout << "NO" << '\n';
        else    cout << "YES" << '\n';
    }
	return 0;
}