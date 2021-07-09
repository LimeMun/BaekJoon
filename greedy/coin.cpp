#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
// 	변수 initialization
	int kindOfCoin[10];
	int count = 0;
// 	입력 받기
	int N, K;
	cin >> N >> K;
	for(int i = 0 ; i < N; i++)
		cin >> kindOfCoin[i];
	
	int presentIndex = N - 1;
	while(K != 0){
		int presentCoin = kindOfCoin[presentIndex];
		if(K >= presentCoin){
			int howMany = (K / presentCoin);
			K -=  howMany * presentCoin;
			count = count + howMany;
			presentIndex--;
			continue;
		}
		else
			presentIndex--;
	}
	cout << count << '\n';
	return 0;
}