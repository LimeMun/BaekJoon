#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(true){
		stack <long long> s;	//index 저장
		long long N;
		long long histogram[100001];
		long long ans;	//ans를 초기화 해주지 않으면, 이전 값으로 남아있다.
		cout << "ans : " << ans << '\n';
		cin >> N;
		if(N == 0)	break;
		for(int i = 0; i < N; i++)	cin >> histogram[i];
		
		for(long long i = 0; i < N; i++){
			while(!s.empty() && histogram[i] < histogram[s.top()]){	// 비교하는 히스토그램보다 작아질때까지 pop한다.
				long long tempHeight = histogram[s.top()];	//잴 높이를 선택
				s.pop();	//그 히스토그램은 pop
				long long tempI = i;	//
				if(!s.empty())	tempI = i - s.top() - 1;
				ans = max(ans , tempHeight * tempI);
			}
			s.push(i);
		}
		while(!s.empty()){
			long long tempHeight = histogram[s.top()];	//잴 높이를 선택
			s.pop();	//그 히스토그램은 pop
			long long tempI = N;	// 자기보다 작은게 없으면, 최장길이로 선택
			if(!s.empty())	tempI = N - s.top() - 1;	//자신보다 작은게 있다면, 부분길이로 선택
			ans = max(ans , tempHeight * tempI);
		}
		
		cout << ans << '\n';
		
	}
	return 0;
}