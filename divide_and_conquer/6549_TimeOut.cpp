#include <iostream>
#include <algorithm>
using namespace std;
int histogram[100000];
unsigned long long cache[100000];
// LIS를 이용해서 풀건데.. 시작길이보다 작아질 때 까지..?


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(true){
		int N;
		cin >> N;
		if(N == 0)
			break;
		for(int i = 0 ; i < N; i++)
			cin >> histogram[i];
		for(int i = 0; i < N; i++){
			int start = i;
			int end = i;
			int height = histogram[i];
			unsigned long long ans = height;
			for(int j = i + 1; j < N; j++){
				if(height > histogram[j]){ 	//height가 더 작은 경우
					unsigned long long canBeAns = (end - start + 1) * histogram[j]; // 작은 높이의 넓이
					ans = max(ans, canBeAns);// 작은 거를 기준으로 했을 때 비교.
					if(ans == canBeAns){
						height = histogram[j];
						end++;
					}
					else
						break;
				}
				else{
					ans += height;
					end++;
				}
			}
			cache[i] = ans;
		}
		unsigned long long finalAns = 0;
		for(int i = 0; i < N; i++){
			finalAns = max(finalAns, cache[i]);
		}
		
		for(int i = N  - 1; i >= 0; i--){
			int start = i;
			int end = i;
			int height = histogram[i];
			unsigned long long ans = height;
			for(int j = i - 1; j >= 0; j--){
				if(height > histogram[j]){ 	//height가 더 작은 경우
					unsigned long long canBeAns = (start - end + 1) * histogram[j]; // 작은 높이의 넓이
					ans = max(ans, canBeAns);// 작은 거를 기준으로 했을 때 비교.
					if(ans == canBeAns){
						height = histogram[j];
						end--;
					}
					else
						break;
				}
				else{
					ans += height;
					end--;
				}
			}
			cache[i] = ans;
		}
		for(int i = 0; i < N; i++){
			finalAns = max(finalAns, cache[i]);
		}
		
		
		
// 		최소 길이로 쭉 이어져서 답인 경우, min height를 구하고 길이를 곱해준다.
		int start = 0;
		int end = 0;
		int height = 1100000000;
		unsigned long long tempAns = 0;
		for(int i = 0; i < N; i++){
			if(histogram[i] == 0){	// 만약, 최소 높이인 히스토그램이 없어지는 경우.
				unsigned long long canBeAns = (end - start + 1) * height;
				if(end == start)
					canBeAns = 0;
				tempAns = max(tempAns, canBeAns);
				start = i + 1;
				end = i + 1;
				height = 1100000000;
			}
			else{
				height = min(height, histogram[i]);
				end++;
			}
		}
// 		끝까지 도달한 경우
		unsigned long long temp = 0;
		if(end != start)
			 temp = (end - start) * height;
		tempAns = max(tempAns, temp);
		
		
		cout << max(finalAns, tempAns) << '\n';
	}

	return 0;
}