#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define MAX 10000
//string 자체가 무거운 객체라, string으로 복사하고 빼고 할 시, 시간복잡도가 커진다. 그래서 웬만하면 string으로 DSLR 계산을 안하는 것이 좋다.
int visited[MAX];

string check4Size(string inputString){
    string temp = "";
    for(int i = 0 ; i < 4 - inputString.size(); i++)    temp += "0";
    temp += inputString;
    return temp;
}

void resetArr(){
    for(int i = 0 ; i < MAX; i++)   visited[i] = 1000000000;
}

string D(string inputString){
    int num = (stoi(inputString) * 2) % 10000;
    return check4Size(to_string(num));
}

string S(string inputString){
    int num = stoi(inputString);
    if(num == 0)    return "9999";
    return check4Size(to_string(num - 1)); 
}

string L(string inputString){
    string a,b,c,d;
    a = inputString[0];
    b = inputString[1];
    c = inputString[2];
    d = inputString[3];
    return (b + c + d + a);
}

string R(string inputString){
    string a,b,c,d;
    a = inputString[0];
    b = inputString[1];
    c = inputString[2];
    d = inputString[3];
    return (d + a + b + c);
}



string bfs(string startString, string endString){
    string ans;
    queue < pair <string, string> > bfsQueue;
    bfsQueue.push(make_pair(startString, ""));
    visited[stoi(startString)] = 0;
    while(!bfsQueue.empty()){
        string nowString = bfsQueue.front().first;
        string nowCommand = bfsQueue.front().second;
        bfsQueue.pop();
        if(nowString == endString){
            ans = nowCommand;
            break;
        }
        string afterD = D(nowString);
        string afterS = S(nowString);
        string afterL = L(nowString);
        string afterR = R(nowString);
        int afterSize = nowCommand.size() + 1;
        if(afterSize < visited[stoi(afterD)]){
            visited[stoi(afterD)] = afterSize;
            bfsQueue.push(make_pair(afterD, nowCommand + "D"));
        }
        if(afterSize < visited[stoi(afterS)]){
            visited[stoi(afterS)] = afterSize;
            bfsQueue.push(make_pair(afterS, nowCommand + "S"));
        }
        if(afterSize < visited[stoi(afterL)]){
            visited[stoi(afterL)] = afterSize;
            bfsQueue.push(make_pair(afterL, nowCommand + "L"));
        }
        if(afterSize < visited[stoi(afterR)]){
            visited[stoi(afterR)] = afterSize;
            bfsQueue.push(make_pair(afterR, nowCommand + "R"));
        }
    }
    return ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int testNum;
    cin >> testNum;
    while(testNum-- > 0){
        resetArr();
        string startString, endString;
        cin >> startString >> endString;
        if(startString.size() < 4)  startString = check4Size(startString);
        if(endString.size() < 4)    endString = check4Size(endString);
        cout << bfs(startString, endString) << '\n';
        
    }

	return 0;
}