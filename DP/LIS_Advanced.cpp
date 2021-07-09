#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define forLoop(start, end) for(int i = start; i < end; i++)

int cache[501][100];
int cacheCount[501];
vector<pair <int, int>> inputLine;

int findMaxCount(int selectedLine){
	if(cacheCount[selectedLine] == 0)
		return 1;
	int temp = cacheCount[selectedLine];
	for(int i = 0; i < temp-1; i++){
		return findMaxCount(cache[selectedLine][i]) + 1;
	}
	return findMaxCount(cache[selectedLine][temp-1]) + 1;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
//변수 선언 및 초기화
	int input;

	vector<pair <int, int>> inputLine;
	memset(cache, -1, sizeof(cache));

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
	// forLoop(0, input){
	// 	cout << inputLine[i].first << inputLine[i].second << '\n';
	// }
// 	2. pair들 중에서 안겹치는 것들의 각각의 집합을 만든다.
	for(int i = 0; i < input; i++){
		int standX = inputLine[i].first;
		int standY = inputLine[i].second;
		int count = 0;
		
		for(int j = i+1; j < input; j++){
			int cmpX = inputLine[j].first;
			int cmpY = inputLine[j].second;
			
			if((cmpX < standX && cmpY < standY) || (cmpX > standX && cmpY > standY)){
				cache[standX][count] = cmpX;
				count++;
			}
		}
		cacheCount[standX] = count;
	}


// 	3. 하나씩 체크해본다.
	int maxCount = 0;
	for(int i = 0; i < input; i++){
		int selectedLine = inputLine[i].first;
		int cmpCount = findMaxCount(selectedLine);
		maxCount = max(maxCount, cmpCount);
	}
	
	cout << input - maxCount << '\n';


	
	return 0;
}