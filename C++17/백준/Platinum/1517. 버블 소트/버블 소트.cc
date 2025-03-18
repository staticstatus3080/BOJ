#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

vector<int> v, arr;

ll Conquer(int st, int en) {
    int mid = (st+en)/2;
    vector<int> v1, v2;
    for (int i=st; i<=mid; i++) v1.push_back(arr[i]);
    for (int i=mid+1; i<=en; i++) v2.push_back(arr[i]);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int idx1=st, idx2=mid+1;
    ll val=0;
    while (idx1 <= mid && idx2 <= en) {
        if (v1[idx1-st] <= v2[idx2-mid-1]) {
            idx1++;
        }
        else {
            val += mid-idx1+1;
            idx2++;
        }
    } 
    return val;
}

ll Solve(int st, int en) {
    if (st==en) return 0;
    ll val=0;
    int mid=(st+en)/2;
    val += Solve(st, mid);
    val += Solve(mid+1, en);
    val += Conquer(st, en);
    return val;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    v = arr;
    sort(v.begin(), v.end());
    cout << Solve(0, n-1);
    return 0;
}