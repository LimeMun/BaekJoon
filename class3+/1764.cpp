#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N , M;
    vector <string> nonHearing;
    vector <string> nonSeeing;
    vector <string> nonHearSeeing;
    cin >> N >> M;
    for(int i = 0 ; i < N; i++){
        string temp;
        cin >> temp;
        nonHearing.push_back(temp);
    }
    for(int i = 0 ; i < M; i++){
        string temp;
        cin >> temp;
        nonSeeing.push_back(temp);
    }
    if(nonHearing.size() < nonSeeing.size()){
        sort(nonSeeing.begin(), nonSeeing.end());
        for(int i = 0; i < nonHearing.size(); i++){
            string findingStr = nonHearing[i];
            int left = 0;
            int right = nonSeeing.size() - 1;
            while(left <= right){
                int mid = (left + right) / 2;
                if(findingStr < nonSeeing[mid]){ // 찾는 문자열이 왼쪽에 있다면.
                    right = mid - 1;
                }
                else if (findingStr > nonSeeing[mid]){
                    left = mid + 1;
                }
                else{
                    nonHearSeeing.push_back(findingStr);
                    break;
                }
            }
        }
    }
    else{
        sort(nonHearing.begin(), nonHearing.end());
        for(int i = 0; i < nonSeeing.size(); i++){
            string findingStr = nonSeeing[i];
            int left = 0;
            int right = nonHearing.size() - 1;
            while(left <= right){
                int mid = (left + right) / 2;
                if(findingStr < nonHearing[mid]){ // 찾는 문자열이 왼쪽에 있다면.
                    right = mid - 1;
                }
                else if (findingStr > nonHearing[mid]){
                    left = mid + 1;
                }
                else{
                    nonHearSeeing.push_back(findingStr);
                    break;
                }
            }
        }
    }
    sort(nonHearSeeing.begin(), nonHearSeeing.end());
    cout << nonHearSeeing.size() << '\n';
    for(int i = 0 ; i < nonHearSeeing.size(); i++)  cout << nonHearSeeing[i] << '\n';

	return 0;
}