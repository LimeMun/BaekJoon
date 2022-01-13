#include <iostream>

using namespace std;

bool matrix[50][50];
int row, column, cabbageNum;
bool visited[50][50];

void reset(){
    for(int i = 0 ; i < 50; i++)
        for(int j = 0 ; j < 50; j++)
            matrix[i][j] = false;
}

void reset2(){
    for(int i = 0 ; i < 50; i++)
        for(int j = 0 ; j < 50; j++)
            visited[i][j] = false;
}

void DFS(int i, int j){
    visited[i][j] = true;
    //상하좌우 탐색하기
    if((i - 1 >= 0) && !visited[i - 1][j] && matrix[i - 1][j]) DFS(i - 1, j);
    if((j + 1 < row) && !visited[i][j + 1] && matrix[i][j + 1]) DFS(i , j + 1);
    if(( i + 1 < column) && !visited[i + 1][j] && matrix[i + 1][j]) DFS(i + 1 , j);
    if(( j - 1 >= 0) && !visited[i][j - 1] && matrix[i][j - 1]) DFS(i , j - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int testCase;
    cin >> testCase;
    while (testCase-- > 0){
        //변수 입력 및 초기화
        int ans = 0;
        reset();
        reset2();
        cin >> column >> row >> cabbageNum;
        for(int i = 0; i < cabbageNum; i++){
            int temp, temp2;
            cin >> temp >> temp2;
            matrix[temp][temp2] = true;
        }
        for (int i = 0; i < column; i++){
            for(int j = 0; j < row; j++){
                if(!visited[i][j] && matrix[i][j]){
                    DFS(i, j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
        
    }
    

	return 0;
}