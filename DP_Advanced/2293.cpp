#include <iostream>

using namespace std;
int coinNum;
int targetValue;

int coinArr[101];
int dp[10001] = {0, };

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> coinNum >> targetValue;
    for(int i = 1 ; i < coinNum + 1; i++){
        int temp;
        cin >> temp;
        coinArr[i] = temp;
        dp[temp]++;
    }
    for(int i = 1; i < targetValue + 1; i++){
        for(int j = 1; j <= i / 2; j++){
            if(i - j == j)  dp[i] = dp[i] + dp[j];
            else    dp[i] = dp[i] + dp[i - j] + dp[j];
        }
    }
    cout << dp[targetValue] << '\n';
    

	return 0;
}