#include <iostream>

using namespace std;
#define MAX 100
int N;
char arr[MAX][MAX];
bool visited[MAX][MAX];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void initialization(){
    for(int i = 0 ; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            visited[i][j] = false;
    }
}

void dfs(int y, int x, char color){
    for(int i = 0 ; i < 4; i++){
        int newY = y + dy[i];
        int newX = x + dx[i];
        if(newY >= 0 && newY < N && newX >= 0 && newX < N && color == arr[newY][newX] && !visited[newY][newX]){
            visited[newY][newX] = true;
            dfs(newY, newX, color);
        }
    }
}

void abnormalDfs(int y, int x, char color){
    for(int i = 0 ; i < 4; i++){
        int newY = y + dy[i];
        int newX = x + dx[i];
        if(newY >= 0 && newY < N && newX >= 0 && newX < N && !visited[newY][newX]){
            char nowColor = arr[newY][newX];
            if(color == nowColor || (color == 'R' && nowColor == 'G') || (color == 'G' && nowColor == 'R')){
                visited[newY][newX] = true;
                abnormalDfs(newY, newX, color);
            }
            
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            cin >> arr[i][j];
        }
    }
    int normalCount = 0;
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                visited[i][j] = true;
                dfs(i, j, arr[i][j]);
                normalCount++;
            }
        }
    }
    initialization();
    int abnormalCount = 0;
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                visited[i][j] = true;
                abnormalDfs(i, j, arr[i][j]);
                abnormalCount++;
            }
        }
    }
    cout << normalCount << ' ' << abnormalCount << '\n';



	return 0;
}



