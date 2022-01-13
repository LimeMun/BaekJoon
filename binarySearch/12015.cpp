#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    vector<int> sequence;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        int index = sequence.size();
        if (index == 0) {
            sequence.push_back(temp);
            continue;
        }
        if (temp > sequence[index - 1]) {
            sequence.push_back(temp);
            continue;
        } 
        else {
            int low = 0, high = index - 1;
            int minButMaxIndex =
                0;  //비교하려는 수보다 큰 수 중, 제일 작은 수의 index
            while (low <= high) {
                int mid = (low + high) / 2;
                if (sequence[mid] >= temp) {
                    minButMaxIndex = mid;
                    high = mid - 1;
                    continue;
                } else {
                    low = mid + 1;
                    continue;
                }
            }
            sequence[minButMaxIndex] = temp;
        }
    }
    cout << sequence.size() << '\n';
    return 0;
}