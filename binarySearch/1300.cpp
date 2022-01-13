#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	int low = 1, high = K, res = 0; // high가 K인 이유는, B[K] <= K이기 때문이다.
	while(low <= high){
		int mid = (low + high) / 2;
		int cnt = 0;
		for(int i = 1 ; i <= N; i++)
			cnt += min(mid / i, N);
		if(cnt < K){
			low = mid + 1;
			continue;
		}
		else{
			high = 	mid - 1;
			res = mid; // 어차피 범위를 좁히면서, 개수가 훨씬 많은 큰 mid 값은 교체된다.
		}
	}
	cout << res << '\n';
	return 0;
}