#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001

vector <int> graph[MAX];
bool visited[MAX] = {false, };

void dfs(int node){
    for(int i = 0 ; i < graph[node].size(); i++){
        int targetNode = graph[node][i];
        if(!visited[targetNode]) {
            visited[targetNode] = true;
            dfs(targetNode);
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int vertex, edge;
    int ansCount = 0;
    cin >> vertex >> edge;
    for(int i = 0 ; i < edge; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    for(int i = 1; i < vertex + 1; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i);
            ansCount++;
        }
    }
    cout << ansCount << '\n';


	return 0;
}