#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int input;
	queue <int> cardDeck;
	cin >> input;
	for(int i = 1 ; i < input + 1; i++)
		cardDeck.push(i);
	
	while(cardDeck.size() != 1){
		cardDeck.pop();
		int temp = cardDeck.front();
		cardDeck.pop();
		cardDeck.push(temp);
	}
	cout << cardDeck.front() << '\n';
	return 0;
}