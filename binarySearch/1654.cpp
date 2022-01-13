#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> numOfCable;
long long maxLength = 0;
int N;

vector<int> vectorInput(int K) {  // K개수만큼만 input을 vector로 받는 함수
    vector<int> numOfCable;
    for (int i = 0; i < K; i++) {
        int temp;
        cin >> temp;
        numOfCable.push_back(temp);
    }
    return numOfCable;
}

void parametricSearch(long long low, long long high) {
	if(low > high)	return ;
    long long mid = (low + high) / 2;
    int count = 0;
    for (int i = 0; i < numOfCable.size(); i++) {
        count += numOfCable[i] / mid;
    }
    if (count >= N) {
        maxLength = max(maxLength, mid);
		parametricSearch(mid + 1, high);
    } 
	else {
        parametricSearch(low, mid -1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int K;
    cin >> K >> N;
    numOfCable = vectorInput(K);
    sort(numOfCable.begin(), numOfCable.end());
    // parametric Search
    long long low = 1, high = numOfCable.back();
	parametricSearch(low, high);
    cout << maxLength << '\n';

    return 0;
}