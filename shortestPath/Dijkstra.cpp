#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 20001

vector < pair <int, int> > graph[MAX]; // 도착 정점, 가중치 저장
int vertex[MAX]; // 각 그래프의 현재 최소 값을 저장.
bool visited[MAX]; // 탐색이 끝난 그래프인지 저장.
int vertexNum;
priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int ,int> > > minHeap; // first는 가중치, second는 정점 번호 그래야 내림차순.

// 1. 시작 정점으로부터 연결 된 노드들의 값을 설정해준다.
// 2. 최단 거리가 짧은 노드를 찾는다.
// 3. 그 노드를 바탕으로 다시 연결딘 노드들의 값을 설정해준다.
// 2, 3번을 반복한다.

void initialization(){
    for(int i = 0 ; i < MAX; i++)   vertex[i] = INT32_MAX;
}



void dijkstra(int startVertex){    
    //시작 정점을 기준으로 연결되어있는 정점값 설정 및 시작 정점은 방문 표시.
    
    // 이 코드를 넣어서 처음 초기값을 넣으면 안되는 이유, 서로 다른 두 정점 사이에 여러개의 간선이 존재할 수 있다.
    //  1 - 5 사이에 가중치가 4,5,6,7이 있는 간선이 존재하는데, 지금 처럼 최소인지 체크하지 않고 넣어버리면 최소가 vertex에 들어가지 않는 문제가 생기기 때문이다.
    // 항상 문제의 조건을 잘 체크하자!!!!😃
    // for(int i = 0 ; i < graph[startVertex].size(); i++){
    //     int nowVertex = graph[startVertex][i].first;
    //     int nowEdgeWeight = graph[startVertex][i].second;
    //     vertex[nowVertex] = nowEdgeWeight;
    //     minHeap.push(make_pair(nowEdgeWeight, nowVertex));
    // }
    vertex[startVertex] = 0;
    minHeap.push(make_pair(0, startVertex));

    // 남은 정점의 개수만큼 알고리즘을 반복한다.
    while(!minHeap.empty()){
        int smallestVertex = minHeap.top().second;
        int smallestVertexWeight = minHeap.top().first;
        minHeap.pop();
        if(visited[smallestVertex])   continue; // 큐에 들어갔는데, 이미 더 최소값이 저장된 경우,
        // 48번째 줄에서, 같은 노드에 대해서 최소값이 계속 갱신된다면, 같은 정점이지만, 가중치가 다른 정보가 큐에 들어가게 된다. 그래서 그 중에서 제일 작은 것만 빼곤 다 정리한다.
        for(int j = 0; j < graph[smallestVertex].size(); j++){
            int nowVertex = graph[smallestVertex][j].first;
            int nowEdgeWeight = graph[smallestVertex][j].second;
            if(visited[nowVertex])  continue;
            if(vertex[smallestVertex] + nowEdgeWeight < vertex[nowVertex]){ // 제일 작은 정점에서 가는 경로가 더 작다면,
                vertex[nowVertex] = vertex[smallestVertex] + nowEdgeWeight;
                minHeap.push(make_pair(vertex[nowVertex], nowVertex));
            }
            
        }
        visited[smallestVertex] = true;
    }

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int edgeNum, startVertex;
    cin >> vertexNum >> edgeNum;
    cin >> startVertex;
    for(int i = 0 ; i < edgeNum; i++){
        int firstVertex, secondVertex, weight;
        cin >> firstVertex >> secondVertex >> weight;
        graph[firstVertex].push_back(make_pair(secondVertex, weight));
    }
    initialization();
    dijkstra(startVertex);

    for(int i = 1 ; i <= vertexNum; i++){
        if(vertex[i] == INT32_MAX)  cout << "INF" << '\n';
        else    cout << vertex[i] << '\n';
    }

	return 0;
}