#include <iostream>
#include <queue>
using namespace std;

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int input;
	int inputNum;
	queue <int> cardDeck;
	cin >> input >> inputNum;
	for(int i = 1 ; i < input + 1; i++)
		cardDeck.push(i);
	cout << '<';
	int count = 1;
	while(cardDeck.size() != 1){
		if(count == inputNum){
			cout << cardDeck.front() << ", ";
			cardDeck.pop();
			count = 1;
// 			시간초과가 뜨길래, push, pop 과정에서 시간복잡도가 높아서 시간초과가 발생하는줄 알았다. 그러나, 만약 제거하는 K번째를 제거하는데, K = 1 이면은, 밑 continue;가 없어서 count는 증가하면서, K를 건너뛰어서 그런거였다.. 다음번엔 더 신중하게 해보자.
			// if(cardDeck.size() < inputNum){
			// 	temp = inputNum % cardDeck.size();
			// }
			continue;
		}
		int temp = cardDeck.front();
		cardDeck.pop();
		cardDeck.push(temp);
		count++;
	}
	cout << cardDeck.front() << '>' << '\n';
	return 0;
}