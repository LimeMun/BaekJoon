#include <iostream>

using namespace std;

//표료 그려보자 각 원소에서 특정 원소까지가 palindrome인지 아닌지 보여주는 표
    //     1   2   1   3   1   2   1
    // 1   O   X   O   X   X   X   O

    // 2       O   X   X   X   O   X   

    // 1           O   X   O   X   X

    // 3               O   X   X   X

    // 1                   O   X   O

    // 2                       O   X

    // 1                           O
    // 만약 [1][7]이 palindrome이면, [2][6]도 palindrome이다. 더 긴 범위로 올라가기 위해서, 아래쪽 부터 위로 palindrome인지 아닌지 true false를 넣는다.
    // 여기서 핵심은  s부터 e까지 palindrome인지 확인하는 palindrome[s][e] = (arr[s] == arr[e] && palindrome[s + 1][e - 1])으로 결정이 된다.
int N, M;
int arr[2001];
bool palindrome[2001][2001] = {false, }; // palindrome[a][b] a부터 b까지 plaindrome인지 알려주는 변수이다.

void input(){
    cin >> N;
    for(int i = 1 ; i < N + 1; i++)
        cin >> arr[i];
    cin >> M;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    input();
    for(int i = 1; i < N + 1; i++){ //개수가 한개인 경우는 무조건 palindrome이다
        palindrome[i][i] = true;
    }
    for(int j = 1; j < N; j++){
        if(arr[j] == arr[j + 1])    palindrome[j][j+1] = true;
    }
    for(int i = N - 2; i >= 1; i--){
        for(int j = i + 2; j <= N; j++){
            if(arr[i] == arr[j] && palindrome[i + 1][j - 1])    palindrome[i][j] = true;
        }
    }
    while(M-- > 0){
        int num1, num2;
        cin >> num1 >> num2;
        cout << palindrome[num1][num2] << '\n';
    }
	return 0;
}