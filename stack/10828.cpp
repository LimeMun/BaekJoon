#include <iostream>
#include <string>
using namespace std;

class Stack{
	public:

		void push(int num);
		int pop();
		int size();
		bool empty();
		int top();
	private:
		int arr[10000] = {0, };
		int index = 0;
};

void Stack::push(int num){
	arr[index] = num;
	index++;
}

int Stack::pop(){
	if(index == 0){
		return -1;
	}
	index--;
	return arr[index];
}

int Stack::size(){
	return index;
}

bool Stack::empty(){
	if(index == 0)
		return true;
	return false;
}

int Stack::top(){
	if(index == 0)
		return -1;
	return arr[index - 1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Stack stack;
	int input;
	cin >> input;
	for(int i = 0 ; i < input; i++){
		string command;
		cin >> command ;
		if(command == "push"){
			int num;
			cin >> num;
			stack.push(num);
		}
		else if(command == "pop"){
			cout << stack.pop() << '\n';
		}
		else if(command == "size"){
			cout << stack.size() << '\n';
		}
		else if(command == "empty"){
			cout << stack.empty() << '\n';
		}
		else{
			cout << stack.top() << '\n';
		}
	}
	return 0;
}