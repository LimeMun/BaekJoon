#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// 변수 초기화 및 입력
// 	length는 길이를 저장하는 캐시, cache는 각 위치별로 인덱스를 저장하는 cache
	int lengthCache[1000];
	int indexCache[1000];
	memset(-1, indexCache, sizeof(indexCache));
	string str1;
	string str2;
	
	cin >> str1 >> str2;
	int str1Length = str1.length();
	int str2Length = str2.length();
	
	for(int i = str1Length - 1; i > -1; i--){
		int & targetLength = lengthCache[i];
		int & targetIndex = indexCache[i]
		for(int j = str2Length - 1; j  > -1; j--){
			if(str1[i] == str2[j])
				targetIndex = max(targetIndex, j);
		}
		for(int j = i + 1; j < )
	}
	
	return 0;
}