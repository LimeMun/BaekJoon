#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for(int i = 0 ; i < testCase; i++){
// 		파일의 개수와, 몇번째로 인쇄되었는지 궁금한 문서가 있는 index 입력받기.
		queue<pair<int,int>> fileClip;
		int fileNum, wantedIndex;
		int fileCount [10] = {0, }; // 문서의 중요도 별로 몇 건인지 저장하는 arr
		cin >> fileNum >> wantedIndex;
// 		for문 돌면서 문서의 중요도 받기.
		for(int j = 0; j < fileNum; j++){
			int temp;
			cin >> temp;
			fileClip.push(make_pair(j, temp)); //인덱스와 중요도 같이 저장하기.
			fileCount[temp]++;
		}
		int presentPriority = 9;
		int count = 0;
		
		while(true){
			if(fileCount[presentPriority] == 0){
				presentPriority--;
				continue;
			}
			pair<int,int> & presentFile = fileClip.front();
// 			원하는 인덱스를 찾은경우.
			if(presentFile.second == presentPriority){
				if(wantedIndex == presentFile.first){
					count++;
					cout << count << '\n';
					break;
				}// 원하는 인덱스는 아니지만, 우선순위는 같은 경우
				else{
					fileClip.pop();
					count++;
					fileCount[presentPriority]--;
					continue;
				}
			} // 우선순위가 다른 경우, pop and push
			else{
				pair<int,int> temp2 = fileClip.front();
				fileClip.pop();
				fileClip.push(temp2);
			}
		}
	}
	return 0;
}