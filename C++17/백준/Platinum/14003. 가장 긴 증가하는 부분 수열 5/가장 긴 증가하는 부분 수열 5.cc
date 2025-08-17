#include <bits/stdc++.h>
// 다음 설명을 참고하였습니다.
// https://eatchangmyeong.github.io/2022/01/20/why-is-lis-algorithm-so-confusing.html
// https://velog.io/@seho100/최강-증가-부분-수열LIS-알고리즘
using namespace std;

long long arr[1000001], idx[1000001], n; // arr : 원본, idx : 각 원소가 LIS의 몇 번째 구간인지

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    vector<long long> LIS;
    for (int i=0; i<n; i++) {
        if (LIS.empty() || lower_bound(LIS.begin(), LIS.end(), arr[i]) == LIS.end())  {
            LIS.push_back(arr[i]);
            idx[i] = LIS.size();
        }
        else {
            auto tmp = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin(); 
            LIS[tmp] = arr[i];
            idx[i] = tmp+1;
        }
    }
    
    int cur = LIS.size();
    cout << cur << '\n';
    
    // 역추적
    stack<int> ans;
    
    for (int i=n-1; i>=0; i--) {
        if (idx[i] == cur) {
            ans.push(arr[i]);
            cur--;
        }
    }
    
    while (!ans.empty()) {cout << ans.top() << ' '; ans.pop();}
}