#include <iostream>
#include <queue>
using namespace std;
#define MAX 20

struct babySharkStruct
{
    int y;
    int x;
    int eatenCount;
    int size ;
    int timeCount;
};
int N;
int arr[MAX][MAX]; // 물고기 크기를 나타내는 배열
bool visited[MAX][MAX];


int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

void initialization(){
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            visited[i][j] = false;
        }
    }
}

babySharkStruct bfs(babySharkStruct babyShark){
    queue < babySharkStruct > bfsQueue;
    bfsQueue.push(babyShark);
    visited[babyShark.y][babyShark.x] = true;
    bool firstSiganl = false;
    while(!bfsQueue.empty()){
        babySharkStruct nowShark = bfsQueue.front();
        bfsQueue.pop();
        for(int i = 0 ; i < 4; i++){
            int nowY = nowShark.y + dy[i];
            int nowX = nowShark.x + dx[i];
            if(nowY >= 0 && nowX >=0 && nowY < N && nowX < N){ //존재하는 좌표라면
                if(!visited[nowY][nowX]){ // 방문하지 않은 곳이라면
                    if(arr[nowY][nowX] == 0 || arr[nowY][nowX] == nowShark.size){ // 그냥 지나갈 수 있는 좌표, 0이거나 같은 크기거나.
                        babySharkStruct tempShark = nowShark;
                        tempShark.y = nowY;
                        tempShark.x = nowX;
                        tempShark.timeCount++;
                        visited[nowY][nowX] = true;
                        bfsQueue.push(tempShark);
                    }
                    else if(arr[nowY][nowX] < nowShark.size){ // 잡아 먹을 수 있는 경우. 좌표 및, 먹은 횟수, 사이즈 증가, 그리고 그 칸의 물고기 삭제
                        if(!firstSiganl){
                            babyShark.y = nowY;
                            babyShark.x = nowX;
                            babyShark.eatenCount = nowShark.eatenCount + 1;
                            babyShark.size = nowShark.size;
                            babyShark.timeCount = nowShark.timeCount + 1;
                            if(babyShark.eatenCount == babyShark.size){
                                babyShark.eatenCount = 0;
                                babyShark.size++;
                            }                         
                            visited[nowY][nowX] = false;
                            firstSiganl = true;
                        }
                        else{
                            if(nowShark.timeCount + 1 > babyShark.timeCount)  continue; // 더 긴경로는 아웃
                            else if(nowShark.timeCount + 1 < babyShark.timeCount){
                                babyShark.y = nowY;
                                babyShark.x = nowX;
                                babyShark.eatenCount = nowShark.eatenCount + 1;
                                babyShark.size = nowShark.size;
                                babyShark.timeCount = nowShark.timeCount + 1;
                                if(babyShark.eatenCount == babyShark.size){
                                    babyShark.eatenCount = 0;
                                    babyShark.size++;
                                }
                                visited[nowY][nowX] = false;
                            }
                            else{
                                if(nowY < babyShark.y || (nowY == babyShark.y && nowX < babyShark.x)){
                                    babyShark.y = nowY;
                                    babyShark.x = nowX;
                                    babyShark.eatenCount = nowShark.eatenCount + 1;
                                    babyShark.size = nowShark.size;
                                    babyShark.timeCount = nowShark.timeCount + 1;
                                    if(babyShark.eatenCount == babyShark.size){
                                        babyShark.eatenCount = 0;
                                        babyShark.size++;
                                    }
                                    visited[nowY][nowX] = false;
                                }
                                
                            }   

                        }
                    }
                }
            }
        }
    }
    arr[babyShark.y][babyShark.x] = 0;
    return babyShark;

}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    babySharkStruct babyshark;
    cin >> N;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            int temp;
            cin >> temp;
            if(temp == 9)   {
                babyshark.y = i;
                babyshark.x = j;
                temp = 0;
            }
            arr[i][j] = temp;
        }
    }
    babyshark.eatenCount = 0;
    babyshark.size = 2;
    babyshark.timeCount = 0;

    while(true){
        initialization(); // 어느 한 지점을 찾고나면, visited값이 이미 설정되어 있으므로 전부 안간곳으로 초기화.
        int nowCount = babyshark.eatenCount;
        int nowSize = babyshark.size;
        babyshark = bfs(babyshark);// bfs를 거치면, 물고기를 먹는 시간이 추가되고, 물고기의 지점, 먹은 횟수, 
        if(nowCount == babyshark.eatenCount && nowSize == babyshark.size){ // 더이상 먹을 물고기가 없는 경우
            break;
        }
    }
    cout << babyshark.timeCount << '\n';



    

	return 0;
}