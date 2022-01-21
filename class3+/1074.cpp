#include <iostream>
using namespace std;

// 만약에 N이 있다면, y좌표, x좌표 둘 다 2^(N-1)을 기준으로 4사분면으로 나뉜다. 
// 그리고 만약, 각 사분면은 다시 4분면으로 쪼개져서 답을 구하게 되고, 최종답은 모두 더해지게된다.
// 그거에 대한 알고리즘이 (((1 << (2 * N - 2)) * 0) + find(N - 1, y, x)); 이다.

// 한가지 깨달은 사실, 1 << 2가 2^2과 같다. 그래서 2 << 2는 2^3이므로, shift연산자로 표시할때는 항상 조심해주자.
// 안풀릴 거 같던 문제도 결국은 풀렸다, 노력하면 된다. 규칙을 찾으려고 노력하고, 계속해서 해보자!

int find(int N, int y, int x){
	
	if(N == 1){
		if(y == 0 && x == 0)	return 0;
		else if(y == 0 && x == 1)	return 1;
		else if(y == 1 && x == 0)	return 2;
		else	return 3;
	}
	else{
		int standard = 1 << (N - 1);
		if(y  < standard && x < standard){ // 1사분면에 있는 경우
			return (((1 << (2 * N - 2)) * 0) + find(N - 1, y, x)); 
		}
		else if(y < standard && x >= standard){ // 2사분면에 있는 경우.
			return (((1 << (2 * N - 2)) * 1) + find(N - 1, y, x - standard)); 
		}
		else if(y >= standard && x < standard){
			return (((1 << (2 * N - 2)) * 2) + find(N - 1, y - standard, x)); 
		}
		else{
			return (((1 << (2 * N - 2)) * 3) + find(N - 1, y - standard, x - standard)); 
		}

	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, r, c;
	cin >> N >> r >> c;
	cout << find(N, r, c) << '\n';


	return 0;
}