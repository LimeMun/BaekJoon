#include <iostream>

using namespace std;
int dp[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int num;
    cin >> num;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    for(int i = 4; i <= num; i++)   dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    cout << dp[num] << '\n';


	return 0;
}