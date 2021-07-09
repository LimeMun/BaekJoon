#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 회의실을 배정할 수 있는 방법은 끝나는 시간을 순차적으로 정렬한 이후에 추가해야한다. 그러면 왜 시작하는 시간을 기준으로 정렬을 하면 안될까..? 이게 내 고민이다.
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// 	변수 설정
	int inputNum;
	vector<pair<int, int>> sessionTime;
// 	입력 받기
	cin >> inputNum;
	for(int i = 0; i < inputNum; i++){
		int temp1, temp2;
		cin >> temp1 >> temp2;
		sessionTime.push_back(make_pair(temp2, temp1));
	}
	sort(sessionTime.begin(), sessionTime.end());
	
	int temp = sessionTime[0].first;
	int count = 1;
	
	for(int i = 1; i < inputNum; i++){
		if(temp <= sessionTime[i].second){
			count++;
			temp = sessionTime[i].first;
		}
	}
	
	cout << count << '\n';
	return 0;
}