#include <iostream>
#include <algorithm>
using namespace std;
// 최대 제곱수를 빼면 23같은 경우는 틀리다, 16 + 4 + 1 + 1 + 1이다. 그러나 답은 9 + 9 + 4 + 1이다.그러므로  23 보다 작은 수를 뺸 것들 중에서 dp값을 더해주는 것이다 dp[7], dp[14], dp[19], dp[22] 중에 최소 값에 + 1을 해주는 것이다.
int dp[50001];

void set(){
    for(int i = 0 ; i < 50001; i++)  dp[i] = 100000000;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int num;
    cin >> num;
    set();
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < num + 1; i++){
        for(int j = 1; j * j <= i; j++){
            dp[i] = min(dp[i], dp[i - (j * j)]);
        }
        dp[i]++;
    }
    cout << dp[num] << '\n';

	return 0;
}