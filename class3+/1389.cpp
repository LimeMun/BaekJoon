#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector <int> graph[101];

int vertexNum, edgeNum;
bool visited[101];

void set(){
    for(int i = 0 ; i < 101; i++)   visited[i] = false;
}

int bfs(int start){
    queue < pair <int, int> > bfsQueue; // first는 현재 위치, second는 count이다.
    visited[start] = true;
    bfsQueue.push(make_pair(start, 0));
    int ans = 0;
    while(!bfsQueue.empty()){
        int nowLoc = bfsQueue.front().first;
        int nowCount = bfsQueue.front().second;
        bfsQueue.pop();
        for(int i = 0 ; i < graph[nowLoc].size(); i++){
            if(!visited[graph[nowLoc][i]]){
                bfsQueue.push(make_pair(graph[nowLoc][i], nowCount + 1));
                visited[graph[nowLoc][i]] = true;
                ans += nowCount + 1;
                continue;
            }
        }
    }
    return ans;
    
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int minBacon = 1000000000;
    int ans;
    
    cin >> vertexNum >> edgeNum;
    for(int i = 0 ; i < edgeNum; i++){
        int temp, temp2;
        cin >> temp >> temp2;
        graph[temp].push_back(temp2);
        graph[temp2].push_back(temp);
    }
    for(int i = vertexNum ; i >= 1; i--){
        set();
        int vertexAns = bfs(i);
        if( vertexAns <= minBacon){
            minBacon = vertexAns;
            ans = i;
        }
    }
    cout << ans << '\n';



	return 0;
}