#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];

int bfs(int N, int K){
    int ans = 0;
    queue <int> bfsQueue;
    bfsQueue.push(N);
    visited[N] = true;
    bool sig = false;
    while(true){
        int queueSizeTemp = bfsQueue.size();
        if(N == K)  break;
        for(int i = 0 ; i < queueSizeTemp; i++){
            int temp = bfsQueue.front();
            int locArr[3] = {temp - 1, temp + 1, temp * 2};
            bfsQueue.pop();
            for(int j = 0 ; j < 3; j++){
                if(locArr[j] == K)  {
                    sig = true;
                    break;
                }
            }
            for(int j = 0 ; j < 3; j++){
                int tempLocArr = locArr[j];
                if(tempLocArr >= 0 && tempLocArr <= 100000 && !visited[tempLocArr]){
                    bfsQueue.push(tempLocArr);
                    visited[tempLocArr] = true;
                }
            }
        }
        ans++;
        if(sig) break;
        
    }
    return ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    cout << bfs(N, K) << '\n';

	return 0;
}