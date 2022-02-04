#include <iostream>
#include <queue>
using namespace std;
int board[101];
bool visited[101];
queue < pair< int, int> > bfsQueue; // <현재 칸의 번호, 주사위 굴린 횟수>
int bfs(){
	int ans;
	bfsQueue.push(make_pair(1, 0));
	visited[1] = true;
	while(true){
		int nowLoc = bfsQueue.front().first;
		int nowCount = bfsQueue.front().second;
		bfsQueue.pop();
		if(nowLoc == 100){
			ans = nowCount;
			break;
		}
		for(int i = 1; i <= 6; i++){
			if(nowLoc + i <= 100){
				if(!visited[nowLoc + i]){ //이미 탐색한 경로인지 체크
					int boardShotrcut = board[nowLoc + i]; // 뱀이나 사다리를 타고 도착하는 칸.
					if(boardShotrcut != 0){ // 만약 사다리나 뱀을 타고 이동하는 경우. 뱀이나 사다리를 통해, 더빠르게 그 칸에 들어갈 수 도 있으므로 visited는 체크해주지 않아도 된다.
						visited[nowLoc + i] = true; // 이동했던 칸, 원래 칸 둘다 방문했다고체크
						visited[boardShotrcut] = true;
						bfsQueue.push(make_pair(boardShotrcut, nowCount + 1));
					}
					else{
						visited[nowLoc + i] = true; // 탐색한 경로는 탐색하지 않기 위해서.
						bfsQueue.push(make_pair(nowLoc + i, nowCount + 1));
					}
				}
			}
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ladderNum, snakeNum;
	cin >> ladderNum >> snakeNum;
	for(int i = 0 ; i < ladderNum + snakeNum; i++){
		int temp, temp2;
		cin >> temp >> temp2;
		board[temp] = temp2;
	}
	cout << bfs() << '\n';


	return 0;
}