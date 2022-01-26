#include <iostream>
#include <queue>
using namespace std;

//	priority_queue<T, Container, Compare>
#define MAX 1000001
bool visited[MAX]; // visited는 삭제된 노드인지 아닌지를 체크해준다.
// 두 큐로 나눠주고, 그 값이 유효한 값인지 체크하는 것이다.
// 나도 비슷하게 생각했지만 ,들어온 수를 기준으로 배열을 만들 생각이었는데 그게 32비트다 보니, 21억개의 배열을 선언할 수가 없어서 안된다고 생각했다. 그러나, 들어온 인덱스를 기준으로 그 숫자가 유효한지 체크를 해주고, 유효하지 않은 숫자라면 pop을 해주면 되는 부분이었다. 조금 더 다양하게 생각을 해봐야겠다.. ㅠㅜㅠㅜㅜ

void reset(){
	for(int i = 0 ; i < MAX; i++)	visited[i] = false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testNum;
	cin >> testNum;
	while(testNum-- > 0){
		reset();
		int commandNum;
		cin >> commandNum;
		// pair로 넣는 거는 first는, 몇번째 명령어인지, second는 그 값을 넣어준다.
		priority_queue < pair <int, int > > maxheap;
		priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minheap;
		for(int i = 0 ; i < commandNum; i++){
			char command;
			int num;
			cin >> command >> num;
			if(command == 'I'){
				maxheap.push(make_pair(num, i));
				minheap.push(make_pair(num, i));
			}
			else{
				if(num == 1){	// 최댓값을 삭제하는 연산, 비어있으면 연산 무시.
					while(!maxheap.empty() && visited[maxheap.top().second]){ //삭제된 노드들 전부 pop
						maxheap.pop();
					}
					if(!maxheap.empty()){// 삭제되지 않은 노드
						visited[maxheap.top().second] = true;
						maxheap.pop();
					}
					
				}
				else{	//최솟값을 삭제하는 연산
					while(!minheap.empty() && visited[minheap.top().second]){ //삭제된 노드들 전부 pop
						minheap.pop();
					}
					if(!minheap.empty()){// 삭제되지 않은 노드
						visited[minheap.top().second] = true;
						minheap.pop();
					}
				}
			}
		}
		while(!maxheap.empty() && visited[maxheap.top().second]){ //삭제된 노드들 전부 pop
			maxheap.pop();
		}
		while(!minheap.empty() && visited[minheap.top().second]){ //삭제된 노드들 전부 pop
			minheap.pop();
		}
		if(minheap.empty() && maxheap.empty())	cout << "EMPTY" << '\n';
		else cout << maxheap.top().first << ' ' << minheap.top().first << '\n';
	}

	return 0;
}