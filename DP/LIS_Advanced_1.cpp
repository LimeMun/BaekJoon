#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define forLoop(start, end) for(int i = start; i < end; i++)



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
//	변수 선언 및 초기화
	int input;
	int cache[100];
	vector<pair <int, int>> inputLine;
//입력 받기
	cin >>input;
	forLoop(0, input){
		int temp;
		int temp2;
		cin >> temp >> temp2;
		inputLine.push_back(make_pair(temp, temp2));
	}
// 	1. 모든 전깃줄을 pair array에 받고 소트한다.
	sort(inputLine.begin(), inputLine.end());

// 	2. 오른쪽 전깃줄에서 LIS를 구한다.
// 		A. Sort를 하게되면 오른쪽 전깃줄은 그에 맞춰서 정렬된다.
// 		B. 그 중에서 차례로 증가하는 최대부분수열을 찾으면 겹치지 않는 전깃줄들이 완성된다.
// 		C. 전체 개수에서 그 개수를 뺀다.
	int maximum = 0;
	for(int i = 0 ; i < input; i++){
		int & ret = cache[i] = 1;
		for(int j = 0; j < i; j++){
			if(inputLine[i].second > inputLine[j].second)
				ret = max(ret, cache[j] + 1);
		}
		maximum = max(maximum, ret);
	}
	
	cout << input - maximum << '\n';
	
	return 0;
}