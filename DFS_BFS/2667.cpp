#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int matrix[25][25];
bool visited[25][25] = {false, };
vector <int> apartNum;
int apartCount = 0;

void parsing(int N, int row, string temp){
    for(int i = N - 1 ; i >= 0; i--)
        matrix[row][i] = temp[i] - 48;
}

void DFS(int i, int j){
    visited[i][j] = true;
    apartCount++;
    //상하좌우 탐색하기
    if((i - 1 >= 0) && !visited[i - 1][j] && matrix[i - 1][j] == 1) DFS(i - 1, j);
    if((j + 1 < N) && !visited[i][j + 1] && matrix[i][j + 1] == 1) DFS(i , j + 1);
    if(( i + 1 < N) && !visited[i + 1][j] && matrix[i + 1][j] == 1) DFS(i + 1 , j);
    if(( j - 1 >= 0) && !visited[i][j - 1] && matrix[i][j - 1] == 1) DFS(i , j - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        parsing(N, i, temp);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j] && matrix[i][j] == 1){
                DFS(i, j);
                ans++;
                apartNum.push_back(apartCount);
                apartCount = 0;
            }
        }
    }
    sort(apartNum.begin(), apartNum.end());
    cout << ans << '\n';
    for(int i = 0; i < apartNum.size(); i++)
        cout << apartNum[i] << '\n';

	return 0;
}