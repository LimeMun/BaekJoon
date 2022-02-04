#include <iostream>

using namespace std;
int N, M;
int arr[500][500]; // 각 경로의 값을 저장하는 배열
int memoization[500][500]; //경로의 개수를 저장하는 배열.
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

//부가적으로, 방문했는지 체크하지 않는 이유는, 어차피 작은 순서대로 내려오므로, 같은 경로를 계속 맴돌일은 없기 때문이다.
// 그렇지만, true, false로 체크를 하게 되면, 경로가 없는 false의 경우 계속 다시 탐색을 하게 되므로, 이미 탐색되었다는 것을 저장힐 필요가 있다.

void reset(){
	for(int i = 0 ; i < 500; i++){
		for(int j = 0 ; j < 500; j++){
			memoization[i][j] = -1;
		}
	}
}

int dfs(int y, int x){
	if(y == N - 1 && x == M - 1){ //끝지점에 도착했을 경우, 경로의 개수를 추가해준다.
		return 1;
	}

	if (memoization[y][x] == -1){ // 아직 맞는 경로인지 모르는 경우, dfs탐색
		memoization[y][x] = 0;
		for(int i = 0; i < 4; i++){
			int newY = y + dy[i];
			int newX = x + dx[i];
			if(newY >= 0 && newX >= 0 && newY < N && newX < M && arr[newY][newX] < arr[y][x]){
				memoization[y][x] += dfs(newY, newX); // 답이 나오는 경로라는 것을 표시.
			}

		}
	}
	return memoization[y][x];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M; j++){
			cin >> arr[i][j];
		}
	}
	reset();
	cout <<  dfs(0, 0) << '\n';
	return 0;
}