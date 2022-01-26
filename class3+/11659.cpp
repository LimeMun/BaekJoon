#include <iostream>

using namespace std;

int dp[100001] = {0, };
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        int temp;
        cin >> temp;
        dp[i] = dp[i - 1] + temp;
    }
    for(int i = 0; i < M; i++){
        int temp, temp2;
        cin >> temp >> temp2;
        cout << dp[temp2] - dp[temp - 1] << '\n';
    }

	return 0;
}