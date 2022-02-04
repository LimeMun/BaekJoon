#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 801

int vertexNum, edgeNum; // 정점과 간선의 개수
vector < pair<int, int> > edgeInfo[MAX]; // 각 간선들의 정보 (목적지, 가중치) 저장.
int graph[MAX]; // 각 그래프의 최소값들을 저장.
bool visited[MAX]; // 각 그래프의 정점을 방문할수 있으면 false, 불가능 하면 true.
priority_queue < pair<int, int>, vector < pair <int, int> >, greater <pair<int, int> > > minHeap;

void initialization(){
	for(int i = 0; i < MAX; i++)	graph[i] = INT32_MAX;
}

void dijkstra(int startVertex, int endVertex){
    int temp = graph[startVertex];
    initialization();
    graph[startVertex] = temp;
    if(temp == INT32_MAX)   return; // 만약 없는 경로일 경우, 미리 끝내버린다.
	minHeap.push(make_pair(graph[startVertex], startVertex));
	while(!minHeap.empty()){
		int nowWeight = minHeap.top().first;
		int nowVertex = minHeap.top().second;
        minHeap.pop(); 
		if(graph[nowVertex] < nowWeight)    continue; // 최소 가중치를 갖지 않는 정점이 나오면 다음 노드 탐색.
        for(int i = 0 ; i < edgeInfo[nowVertex].size(); i++){
            int tempVertex = edgeInfo[nowVertex][i].first;
            int tempWeight = edgeInfo[nowVertex][i].second;
            if(tempWeight + nowWeight < graph[tempVertex]){ // 더 작은 경로가 나오면 새롭게 값을 결정.
                graph[tempVertex] = tempWeight + nowWeight;
                minHeap.push(make_pair(graph[tempVertex], tempVertex));
            }
        }

	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> vertexNum >> edgeNum;
	for(int i = 0 ; i < edgeNum; i++){
		int temp, temp2, temp3;
        cin >> temp >> temp2 >> temp3;
		edgeInfo[temp].push_back(make_pair(temp2, temp3));
		edgeInfo[temp2].push_back(make_pair(temp, temp3));
	}
	int mustVertex, mustVertex2;
	cin >> mustVertex >> mustVertex2;

    graph[1] = 0;
    // 1 -> mustVertex -> mustVertex2 -> N으로 가는 경우.
	dijkstra(1, mustVertex); // 처음은 1에서 mustVertex로 가는걸 탐색. 그러나 mustVertex2과 N 은 visited로 지나가지 않는 경로의 최솟값 구하기.
    dijkstra(mustVertex, mustVertex2);
    dijkstra(mustVertex2, vertexNum);
    int firstWay = graph[vertexNum];

    // 1 -> mustVertex2 -> mustVertex -> N으로 가는 경우.
    graph[1] = 0;
	dijkstra(1, mustVertex2); // 처음은 1에서 mustVertex로 가는걸 탐색. 그러나 mustVertex2과 N 은 visited로 지나가지 않는 경로의 최솟값 구하기.
    dijkstra(mustVertex2, mustVertex);
    dijkstra(mustVertex, vertexNum);
    int secondWay = graph[vertexNum];
    int ans = min(firstWay, secondWay);
    if(ans == INT32_MAX)    cout << "-1" << '\n';
    else cout << ans << '\n';


	return 0;
}