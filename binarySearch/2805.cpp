#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	vector <long long> treeArr;
	// 기본적입 입력 받기
	cin >> N >> M;
	int low = 1, high = 0;
	for(int i = 0 ; i < N ; i++){
		int temp;
		cin >> temp;
		treeArr.push_back(temp);
		high = max(high, temp);
	}
	// parametric Search 시작
	long long highestLen = 0;
	while(low <= high){
		long long mid = (low + high) / 2;
		long long res = 0;
		for(int i = 0 ; i < N; i++){
			if(treeArr[i] >= mid)	//자르려는 길이가 더 크면, 음수가 나오기때문에 그 경우는 제외시키기
				res += treeArr[i] - mid;
		}
		if(res >= M){ // 자른 길이가 더 길거나 같은경우, 더 높게 설정해서 자를 수가 있음
			highestLen = max(highestLen, mid);
			low = mid + 1;
			continue;
		}
		else{
			high = mid -1;
			continue;
		}
	}
	cout << highestLen << '\n';


	return 0;
}