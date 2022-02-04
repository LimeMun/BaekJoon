#include <iostream>
#include <algorithm>
using namespace std;
int arr[500][500];
int N, M;

//흠.. 나는 모든 경우의 수를 구현하긴 했는데, 사람이 할짓이 아닌거 같다..ㅎㅎ
// DFS로 깊이가 4인것만을 탐색해서 최대 길이면 추가해준다, 그리고 백트래킹을 적용하여 갔다온 지점은 다시 false로 바꿔준다. 
// 이러면, 5번 도형을 제외하고는 모두 구할 수 있다.
int firstTetriMino(){ // 세로 4줄 테트로미노
    int ans = 0;
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < M ; j++){
            if(i + 3 < N){ 
                int temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
                ans = max(temp, ans);
            }
            if(j + 3 < M){
                int temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
                ans = max(temp, ans);
            }
        }
    }
    return ans;
}

int secondTetriMino(){ // 2 x 2 테트로미노
    int ans = 0;
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < M ; j++){
            if(i + 1 < N && j + 1 < M){ 
                int temp = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
                ans = max(temp, ans);
            }
        }
    }
    return ans;
}

int thirdTetriMino(){ //ㄴ자 테트리미노
    int ans = 0;
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < M ; j++){
            if(i + 2 < N && j + 1 < M){  // 원래 모양인 경우, + 원래 모양에서 상하대칭
                int temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
                int temp2 = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j + 1];
                ans = max(ans, max(temp, temp2));
            }
            if(i + 2 < N && j - 1 >= 0){ // 원래 모양에서 좌우 대칭인 경우 + 이 모양에서 상하대칭
                int temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j - 1];
                int temp2 = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j - 1];
                ans = max(ans, max(temp, temp2));
            }
            if(i - 1 >= 0 && j + 2 < M){
                int temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 2];
                int temp2 = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j];
                ans = max(ans, max(temp, temp2));
            }
            if(i + 1 < N && j + 2 < M){
                int temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
                int temp2 = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j];
                ans = max(ans, max(temp, temp2));
            }
            
        }
    }
    return ans;
}
int fourthTetriMino(){ //ㄹ자 테트리미노
    int ans = 0;
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < M ; j++){
            if(i + 2 < N && j + 1 < M){  // 원래 모양인 경우, + 원래 모양에서 상하대칭
                int temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
                ans = max(ans, temp);
            }
            if(i + 2 < N && j - 1 >= 0){
                int temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 2][j - 1];
                ans = max(ans, temp);
            }
            if(i - 2 >= 0 && j + 1 < M){
                int temp = arr[i][j] + arr[i - 1][j] + arr[i - 1][j + 1] + arr[i - 2][j + 1];
                ans = max(ans, temp);
            }
            if(i - 2 >= 0 && j - 1 >= 0){
                int temp = arr[i][j] + arr[i - 1][j] + arr[i - 1][j - 1] + arr[i - 2][j - 1];
                ans = max(ans, temp);
            }
            if(i + 1 < N && j + 2 < M){
                int temp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
                ans = max(ans, temp);
            }
            if(i + 1 < N && j - 2 >= 0){
                int temp = arr[i][j] + arr[i][j - 1] + arr[i + 1][j - 1] + arr[i + 1][j - 2];
                ans = max(ans, temp);
            }
            if(i - 1 >= 0 && j + 2 < M){
                int temp = arr[i][j] + arr[i][j + 1] + arr[i - 1][j + 1] + arr[i - 1][j + 2];
                ans = max(ans, temp);
            }
            if(i - 1 >= 0 && j - 2 >= 0){
                int temp = arr[i][j] + arr[i][j - 1] + arr[i - 1][j - 1] + arr[i - 1][j - 2];
                ans = max(ans, temp);
            }
            
        }
    }
    return ans;
}

int fifthTetriMino(){ // 2 x 2 테트로미노
    int ans = 0;
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < M ; j++){
            if(i + 1 < N && j + 1 < M && j - 1 >= 0){ 
                int temp = arr[i][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i + 1][j];
                ans = max(temp, ans);
            }
            if(i - 1 >= 0 && j + 1 < M && j - 1 >= 0){
                int temp = arr[i][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i - 1][j];
                ans = max(temp, ans);
            }
            if(i + 1 < N && j - 1 >= 0 && i - 1 >= 0){ 
                int temp = arr[i][j] + arr[i + 1][j] + arr[i - 1][j] + arr[i][j - 1];
                ans = max(temp, ans);
            }
            if(i + 1 < N && j + 1 < M && i - 1 >= 0){
                int temp = arr[i][j] + arr[i + 1][j] + arr[i - 1][j] + arr[i][j + 1];
                ans = max(temp, ans);
            }
            
        }
    }
    return ans;
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
    int first = firstTetriMino();
    int second = secondTetriMino();
    int third = thirdTetriMino();
    int fourth = fourthTetriMino();
    int fifth = fifthTetriMino();
    cout << max(max(max(max(first, second), third), fourth), fifth) << '\n';


	return 0;
}