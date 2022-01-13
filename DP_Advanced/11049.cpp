#include <iostream>
#include <climits>
using namespace std;

pair <int, int> matrixArr[501]; // 원래 행렬을 저장
int dp[501][501]; //계산값을 저장	// 계산된 행렬을 저장

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	cin >> num;
	for(int i = 1; i <= num; i++){
		int temp, temp2;
		cin >> temp >> temp2;
		matrixArr[i] = make_pair(temp, temp2);
	}
	for(int i = 1 ; i <= num; i++){
		for(int j = 1; j <= num - i; j++){
			dp[j][j + i] = INT_MAX;
			for(int k = j; k <= j + i; k++){
				int res = dp[j][k] + dp[k + 1][j + i] + matrixArr[j].first * matrixArr[k].second * matrixArr[j + i].second;
				dp[j][j + i] = min(res, dp[j][j + i]);
			}
		}
	}
	cout << dp[1][num] << '\n';

	return 0;
}