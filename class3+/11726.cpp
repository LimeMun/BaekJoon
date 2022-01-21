#include <iostream>

using namespace std;
int dp[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int num;
    cin >> num;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i < num + 1; i++)    dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
    cout << dp[num] << '\n';
    

	return 0;
}