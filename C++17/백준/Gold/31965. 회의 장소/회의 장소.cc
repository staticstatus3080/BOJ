#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second

using namespace std;
ll S[200001]={}, IncS[200001]={}, DecS[200001]={};
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll N, Q;
    vector<ll> arr;
    cin >> N >> Q;
    
    for (ll i=0; i<N; i++) {
        ll input;
        cin >> input;
        arr.push_back(input);
        if (i==0) continue;
        S[i] = S[i-1] + (input-arr[i-1]);
        IncS[i] = IncS[i-1] + i * (input-arr[i-1]);
        DecS[i] = DecS[i-1] + (N-i) * (input-arr[i-1]);
    }
    
    while (Q--) {
        ll st, en;
        ll minLen, maxLen;
        cin >> st >> en;
        ll start = lower_bound(arr.begin(), arr.end(), st) - arr.begin();
        ll end = upper_bound(arr.begin(), arr.end(), en) - arr.begin() - 1;
        if (end==start || end-1==start || start>=N) {
            cout << 0 << '\n';
            continue;
        }
        ll mid = (start+end)/2;
        maxLen = max(IncS[end] - IncS[start] - (S[end] - S[start]) * start, 
                    DecS[end] - DecS[start] - (S[end] - S[start]) * (N-end-1));
        minLen = (DecS[end] - DecS[mid]) - (S[end] - S[mid]) * (N-end-1) +
        (IncS[mid] - IncS[start]) - (S[mid]-S[start]) * start;
        
        if ((end-start)&1) {
            mid--;
            minLen = min(minLen, (DecS[end] - DecS[mid]) - (S[end] - S[mid]) * (N-end-1) +
            (IncS[mid] - IncS[start]) - (S[mid]-S[start]) * start);
        }
        
        cout << maxLen - minLen << '\n';
    }
}