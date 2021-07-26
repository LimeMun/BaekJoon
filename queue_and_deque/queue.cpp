#include <iostream>
#include <string>
using namespace std;
class Queue{
	public:
		int arr[2000000];
		int front_index;
		int rear_index;
		Queue();
		void push(int num);
		void pop();
		void size();
		void empty();
		void front();
		void back();
};
Queue::Queue(){
	front_index = 0;
	rear_index = 0;
}
void Queue::push(int num){
	arr[rear_index] = num;
	rear_index++;
}
void Queue::pop(){
	if(front_index == rear_index){
		cout << -1 << '\n';
		return ;
	}
	cout << arr[front_index] << '\n';
	front_index++;
}
void Queue::size(){
	cout << rear_index - front_index << '\n';
}
void Queue::empty(){
	if(rear_index == front_index){
		cout << 1 << '\n';
		return ;
	}
	cout << 0 << '\n';
}
void Queue::front(){
	if(rear_index == front_index){
		cout << -1 << '\n';
		return ;
	}
	// cout << "front_index : " << front_index << '\n'; 
	cout << arr[front_index] << '\n';
}
void Queue::back(){
	if(rear_index == front_index){
		cout << -1 << '\n';
		return ;
	}
	cout << arr[rear_index - 1] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int commandNum;
	Queue queue;
	cin >> commandNum;
	for(int i = 0 ; i < commandNum; i++){
		string command;
		cin >> command;
		if(command == "push"){
			int input;
			cin >> input;
			queue.push(input);
		}
		else if(command == "pop")	queue.pop();
		else if(command == "size")	queue.size();
		else if(command == "empty")	queue.empty();
		else if(command == "front")	queue.front();
		else if(command == "back")	queue.back();
	}
}