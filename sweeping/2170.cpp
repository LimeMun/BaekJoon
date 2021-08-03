#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	vector<pair<int, int>> line;
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		int start, end;
		cin >> start >> end;
		line.push_back(make_pair(start, end));
	}
	
	sort(line.begin(),line.end());
	int result = 0;
	int left = line[0].first;
	int right = line[0].second;
	for(int i = 1 ; i < N; i++){
		if(line[i].first < right){	// 계속해서 선을 합칠 수 있는 경우
			right = max(right, line[i].second);
		}
		else{	//합칠 수 없는 경우, 그 길이를 더해주고, 새로운 선을  설정.
			result += right - left;
			left = line[i].first;
			right = line[i].second;
		}
	}
	result += right - left;
	cout << result << '\n';
	return 0;
}