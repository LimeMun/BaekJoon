#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int valueCache[101][100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// 	입력 받기
	int stuffNum;
	int possibleMass;
	vector <pair<int, int>> allOfStuff;
	
	allOfStuff.push_back(make_pair(0, 0));
	cin >> stuffNum >> possibleMass;
	
	
	for(int i = 0; i < stuffNum; i++){
		int temp;
		int temp2;
		cin >> temp >> temp2;
		allOfStuff.push_back(make_pair(temp, temp2));
	}
	
	// for(int i = 0; i < stuffNum + 1; i++){
	// 	for(int j = 0; j < possibleMass + 1; j++)
	// 		cout << valueCache[i][j] << ' ';
	// 	cout << '\n';
	// }
			
	for(int i = 1; i < stuffNum + 1; i++){
		for(int j = 1; j < possibleMass + 1; j++){
			int weight = allOfStuff[i].first;
			int value = allOfStuff[i].second;
			if(weight <= j)
				valueCache[i][j] = max(valueCache[i - 1][j - weight] + value, valueCache[i - 1][j]);
			else
				valueCache[i][j] = valueCache[i - 1][j];
		}
	}
	
	// for(int i = 0; i < stuffNum + 1; i++){
	// 	for(int j = 0; j < possibleMass + 1; j++)
	// 		cout << valueCache[i][j] << ' ';
	// 	cout << '\n';
	// }
	
	cout << valueCache[stuffNum][possibleMass] << '\n';
	
	return 0;
}