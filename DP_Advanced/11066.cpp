#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000
int dp[501][501];
int sum[501];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int testCaseNum;
    cin >> testCaseNum;
    for(int i = 0 ; i < testCaseNum; i++){
        int chapterNum;
        cin >> chapterNum;
        int chapterArr [501] = {0, };
        for(int j = 1 ; j <= chapterNum; j++){
            cin >> chapterArr[j];
            sum[j] = sum[j-1] + chapterArr[j];
        }
        // dp 값 구해주기, dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j] - sum[i - 1])
        for(int j = 1; j <= chapterNum; j++){
            for(int k = 1 ; k <= chapterNum - j; k++){
                dp[k][k + j] = INF;
                for(int l = k; l <= k + j; l++){
                    dp[k][k + j] = min(dp[k][k + j], dp[k][l] + dp[l + 1][k + j] + sum[k + j] - sum[k - 1]);
                }
            }
        }
        cout << dp[1][chapterNum] << '\n';
    }

	return 0;
}