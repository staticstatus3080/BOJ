#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    int n, arr[250001], tmp[250001];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        if (i==0) continue;
        int cur=arr[i], cnt=0;
        while (arr[i-1] < cur) {
            cnt--;
            cur /= 2;
        }
        while (arr[i-1] > cur) {
            cnt++;
            cur *= 2;
        }
        tmp[i] = cnt;
    }
    
    long long ans=0;
    for (int i=1; i<n; i++) {
        if (tmp[i] <= 0) continue;
        ans += tmp[i];
        tmp[i+1] += tmp[i];
    }
    
    cout << ans;
}